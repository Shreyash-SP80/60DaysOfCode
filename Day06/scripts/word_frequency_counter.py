import os
from PyPDF2 import PdfReader

def count_word_frequency(text):
    # Clean punctuation and lowercase
    for ch in [',', '.', '!', '?', ';', ':', '-', '(', ')']:
        text = text.replace(ch, '')
    text = text.lower()

    words = text.split()
    freq = {}
    for word in words:
        freq[word] = freq.get(word, 0) + 1

    print("\nWord Frequency Count:")
    for word, count in freq.items():
        print(f"{word}: {count}")

def read_pdf(file_path):
    reader = PdfReader(file_path)
    text = ""
    for page in reader.pages:
        text += page.extract_text() or ""
    return text

if __name__ == "__main__":
    print("Word Frequency Counter")
    print("----------------------")
    choice = input("Enter '1' to type text or '2' to read from file: ")

    if choice == '1':
        text = input("Enter your text: ")
        count_word_frequency(text)

    elif choice == '2':
        file_path = input("Enter file path: ")

        if not os.path.exists(file_path):
            print("❌ File not found. Please check the path.")
        elif file_path.lower().endswith(".pdf"):
            text = read_pdf(file_path)
            count_word_frequency(text)
        else:
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as file:
                text = file.read()
                count_word_frequency(text)
    else:
        print("Invalid choice. Please enter 1 or 2.")
