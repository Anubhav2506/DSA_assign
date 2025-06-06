# RAG Project: Retrieval‐Augmented Generation over JSON/Text Documents

This repository implements an end‐to‐end RAG (Retrieval‐Augmented Generation) pipeline:
1. Chunking raw documents (JSON or text) into ~500‐token pieces  
2. Embedding each chunk with a Hugging Face SentenceTransformer  
3. Building a FAISS index over those embeddings  
4. Running a LangChain “RetrievalQA” chain to answer user queries interactively  

## Directory Structure


### `requirements.txt`

List of Python packages needed:

```text
langchain
sentence-transformers
faiss-cpu
huggingface_hub
transformers
torch
tqdm
numpy

pip install -r requirements.txt
