# src/build_faiss.py

import os
import json
import numpy as np
from tqdm import tqdm
from sentence_transformers import SentenceTransformer
import faiss

CHUNKS_PATH = "../data/processed/chunks.json"
EMBEDDING_MODEL_NAME = "sentence-transformers/all-MiniLM-L6-v2"
OUT_FAISS_DIR = "../data/processed/faiss_index"

def main():
    # 1. Load chunks from JSON
    with open(CHUNKS_PATH, "r", encoding="utf-8") as f:
        chunks = json.load(f)

    texts = [entry["text"] for entry in chunks]
    metadata = [
        {
            "doc_id": entry["doc_id"],
            "chunk_id": entry["chunk_id"],
        }
        for entry in chunks
    ]

    # 2. Load embedding model
    model = SentenceTransformer(EMBEDDING_MODEL_NAME)
    embedding_dim = model.get_sentence_embedding_dimension()

    # 3. Compute embeddings in batches
    batch_size = 64
    all_embeddings = []

    for i in tqdm(range(0, len(texts), batch_size), desc="Embedding chunks"):
        batch_texts = texts[i : i + batch_size]
        batch_emb = model.encode(batch_texts, convert_to_numpy=True, normalize_embeddings=True)
        all_embeddings.append(batch_emb)

    all_embeddings = np.vstack(all_embeddings)  # shape: (N_chunks, dim)

    # 4. Build a FAISS index (flat inner‐product)
    index = faiss.IndexFlatIP(embedding_dim)
    index.add(all_embeddings)  # add all vectors

    # 5. Save the FAISS index and metadata
    os.makedirs(OUT_FAISS_DIR, exist_ok=True)
    faiss.write_index(index, os.path.join(OUT_FAISS_DIR, "faiss_index.ivf"))

    # Save metadata separately
    with open(os.path.join(OUT_FAISS_DIR, "metadata.json"), "w", encoding="utf-8") as f:
        json.dump(metadata, f, ensure_ascii=False)

    print(f"FAISS index with {len(texts)} vectors saved to {OUT_FAISS_DIR}")

if __name__ == "__main__":
    main()
