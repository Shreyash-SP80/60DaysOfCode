# word_frequency_counter.py
# A simple script to count word frequency in a given text or file.

def count_word_frequency(text):
    # Remove punctuation and convert to lowercase
    for ch in [',', '.', '!', '?', ';', ':']:
        text = text.replace(ch, '')
    text = text.lower()

    # Split text into words
    words = text.split()

    # Count frequency using a dictionary
    freq = {}
    for word in words:
        freq[word] = freq.get(word, 0) + 1

    # Display result
    print("\nWord Frequency Count:")
    for word, count in freq.items():
        print(f"{word}: {count}")

if __name__ == "__main__":
    print("Word Frequency Counter")
    print("----------------------")
    choice = input("Enter '1' to type text or '2' to read from file: ")

    if choice == '1':
        text = input("Enter your text: ")
        count_word_frequency(text)
    elif choice == '2':
        file_path = input("Enter file path: ")
        try:
            with open(file_path, 'r') as file:
                text = file.read()
                count_word_frequency(text)
        except FileNotFoundError:
            print("❌ File not found. Please check the path and try again.")
    else:
        print("Invalid choice. Please enter 1 or 2.")

# Output =>
# Word Frequency Count:
# hello: 2
# world: 1
# python: 3

