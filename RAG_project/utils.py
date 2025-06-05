# src/utils.py

import os
import json
from typing import List, Dict
from tqdm import tqdm
from transformers import AutoTokenizer
import faiss
import numpy as np
from langchain.vectorstores import FAISS
from langchain.embeddings import HuggingFaceEmbeddings

# -----------------------------------------------------------------------------
# CONFIGURATION
# -----------------------------------------------------------------------------
EMBEDDING_MODEL_NAME = "sentence-transformers/all-MiniLM-L6-v2"
_tokenizer = AutoTokenizer.from_pretrained(EMBEDDING_MODEL_NAME)
# -----------------------------------------------------------------------------

def load_json_docs(raw_dir: str) -> List[Dict]:
    """
    Read all .json files in raw_dir and return a list of dictionaries.
    Each dict is the parsed JSON for one document.
    """
    docs = []
    for fname in os.listdir(raw_dir):
        if not fname.endswith(".json"):
            continue
        path = os.path.join(raw_dir, fname)
        with open(path, "r", encoding="utf-8") as f:
            data = json.load(f)
            docs.append(data)
    return docs

def chunk_text(
    text: str,
    max_tokens: int = 500,
    overlap_tokens: int = 50
) -> List[str]:
    """
    Split `text` into chunks of at most max_tokens (according to tokenizer),
    with overlap of overlap_tokens between chunks. Returns list of text chunks.
    """
    # Tokenize the entire text into token IDs
    tokens = _tokenizer(text, return_attention_mask=False, return_token_type_ids=False)["input_ids"]
    chunks = []
    start = 0
    total_tokens = len(tokens)

    while start < total_tokens:
        end = min(start + max_tokens, total_tokens)
        chunk_ids = tokens[start:end]
        chunk_text = _tokenizer.decode(chunk_ids, skip_special_tokens=True)
        chunks.append(chunk_text)

        # Move start forward by max_tokens - overlap_tokens
        start += max_tokens - overlap_tokens

    return chunks

class CustomFaissRetriever:
    """
    Wrap a prebuilt FAISS index and metadata in a LangChain VectorstoreRetriever.
    """

    def __init__(self, faiss_index_path: str, metadata_path: str, embedding_model_name: str):
        # 1. Load metadata
        with open(metadata_path, "r", encoding="utf-8") as f:
            self.metadata = json.load(f)  # List of { "doc_id": ..., "chunk_id": ... }

        # 2. Load FAISS index
        self.index = faiss.read_index(faiss_index_path)

        # 3. Build a LangChain FAISS vectorstore object
        hf_embedder = HuggingFaceEmbeddings(model_name=embedding_model_name)

        # Reload chunk texts in the same order as metadata
        chunks_json_path = "../data/processed/chunks.json"
        with open(chunks_json_path, "r", encoding="utf-8") as cf:
            chunks_list = json.load(cf)
        texts = [entry["text"] for entry in chunks_list]

        # Initialize LangChain FAISS vectorstore wrapper
        self.vectorstore = FAISS(
            embedding_function=hf_embedder,
            index=self.index,
            texts=texts,
            metadatas=self.metadata,
            normalize_L2=True  # Because we used inner product on normalized embeddings
        )

    def get_retriever(self, top_k: int = 5):
        """
        Return a LangChain Retriever object that returns top_k similar chunks.
        """
        return self.vectorstore.as_retriever(search_type="similarity", search_kwargs={"k": top_k})
