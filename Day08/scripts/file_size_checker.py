import os

def get_readable_size(size_in_bytes):
    """Convert bytes to KB, MB, or GB for better readability."""
    for unit in ['B', 'KB', 'MB', 'GB']:
        if size_in_bytes < 1024:
            return f"{size_in_bytes:.2f} {unit}"
        size_in_bytes /= 1024
    return f"{size_in_bytes:.2f} TB"

def list_file_sizes(folder_path):
    """List all files and their sizes in the specified folder."""
    if not os.path.exists(folder_path):
        print("❌ Folder not found.")
        return

    print("\n📂 File Size Report")
    print("-" * 40)

    total_size = 0
    for filename in os.listdir(folder_path):
        file_path = os.path.join(folder_path, filename)

        if os.path.isfile(file_path):
            size = os.path.getsize(file_path)
            readable_size = get_readable_size(size)
            total_size += size
            print(f"{filename:30} {readable_size}")

    print("-" * 40)
    print(f"Total Size: {get_readable_size(total_size)}")

if __name__ == "__main__":
    folder = input("Enter folder path to check file sizes: ")
    list_file_sizes(folder)
