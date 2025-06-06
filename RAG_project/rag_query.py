# src/rag_query.py

import os
from langchain.chains import RetrievalQA
from langchain.llms import HuggingFaceHub, OpenAI
from src.utils import CustomFaissRetriever

def main():
    # 1. Paths & model names
    faiss_index_path = "../data/processed/faiss_index/faiss_index.ivf"
    metadata_path    = "../data/processed/faiss_index/metadata.json"
    embedding_model  = "sentence-transformers/all-MiniLM-L6-v2"

    # 2. Instantiate FAISS retriever
    retriever_obj = CustomFaissRetriever(
        faiss_index_path=faiss_index_path,
        metadata_path=metadata_path,
        embedding_model_name=embedding_model
    )
    retriever = retriever_obj.get_retriever(top_k=5)

    # 3. Choose an LLM (uncomment one):
    # Option A: Hugging Face Hub (requires HUGGINGFACEHUB_API_TOKEN env var)
    llm = HuggingFaceHub(
        repo_id="google/flan-t5-base",      # or another HF model
        model_kwargs={"temperature": 0.1, "max_length": 256}
    )
    # Option B: OpenAI (requires OPENAI_API_KEY env var)
    # llm = OpenAI(temperature=0.1, max_tokens=256)

    # 4. Build a RetrievalQA chain
    qa_chain = RetrievalQA.from_chain_type(
        llm=llm,
        chain_type="stuff",
        retriever=retriever,
        return_source_documents=True
    )

    # 5. Query loop
    print("Enter ’exit’ or ’quit’ to stop.")
    while True:
        user_q = input("\nEnter your question: ").strip()
        if user_q.lower() in ["exit", "quit"]:
            break

        result = qa_chain({"query": user_q})
        answer = result["result"]
        source_docs = result["source_documents"]

        print("\nAnswer:\n", answer)
        print("\nTop retrieved chunks (metadata + snippet):")
        for doc in source_docs:
            meta = doc.metadata
            snippet = doc.page_content[:200].replace("\n", " ") + "..."
            print(f" • [DocID={meta['doc_id']} | chunk={meta['chunk_id']}]  {snippet}")

    print("Goodbye!")

if __name__ == "__main__":
    main()
