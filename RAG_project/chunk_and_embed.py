# src/chunk_and_embed.py

import os
import json
from tqdm import tqdm
from src.utils import load_json_docs, chunk_text

def main():
    raw_dir = "../data/raw_docs"
    out_chunks_path = "../data/processed/chunks.json"

    # 1. Load all raw docs
    docs = load_json_docs(raw_dir)

    # 2. For each doc, chunk the "body" (or whichever field):
    all_chunks = []
    for doc in tqdm(docs, desc="Chunking documents"):
        doc_id = doc.get("id", None) or doc.get("title", "unknown_id")
        text = doc.get("body", "")
        if not text.strip():
            continue

        chunks = chunk_text(text, max_tokens=500, overlap_tokens=50)
        for idx, chunk in enumerate(chunks):
            all_chunks.append({
                "doc_id": doc_id,
                "chunk_id": idx,
                "text": chunk
            })

    # 3. Write out all chunks to a single JSON file
    os.makedirs(os.path.dirname(out_chunks_path), exist_ok=True)
    with open(out_chunks_path, "w", encoding="utf-8") as f:
        json.dump(all_chunks, f, ensure_ascii=False, indent=2)

    print(f"Saved {len(all_chunks)} chunks to {out_chunks_path}")

if __name__ == "__main__":
    main()
