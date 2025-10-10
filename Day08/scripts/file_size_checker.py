import os

def get_file_size(path):
    """Return file size in a human-readable format."""
    size = os.path.getsize(path)
    if size < 1024:
        return f"{size} B"
    elif size < 1024 ** 2:
        return f"{size / 1024:.2f} KB"
    else:
        return f"{size / (1024 ** 2):.2f} MB"

def list_file_sizes(folder_path):
    """List all files with their sizes and identify the largest one."""
    files = [f for f in os.listdir(folder_path) if os.path.isfile(os.path.join(folder_path, f))]

    if not files:
        print("⚠️ No files found in the folder.")
        return

    largest_file = None
    largest_size = 0

    print(f"\n📁 Files in '{folder_path}':\n" + "-" * 50)
    for file in files:
        file_path = os.path.join(folder_path, file)
        size = os.path.getsize(file_path)
        readable_size = get_file_size(file_path)
        print(f"{file:<35} {readable_size:>10}")

        if size > largest_size:
            largest_size = size
            largest_file = file

    print("\n📊 Summary:")
    print(f"Largest File: {largest_file}")
    print(f"Size: {get_file_size(os.path.join(folder_path, largest_file))}")

if __name__ == "__main__":
    folder = input("Enter folder path: ").strip()
    if os.path.exists(folder):
        list_file_sizes(folder)
    else:
        print("❌ Invalid path. Please enter a valid folder location.")

Enter folder path: D:\Projects

# Output =>
# 📁 Files in 'D:\Projects':
# --------------------------------------------------
# main.cpp                             2.45 KB
# notes.txt                            1.10 KB
# data.csv                             5.30 KB
# image.png                           12.60 MB

# 📊 Summary:
# Largest File: image.png
# Size: 12.60 MB



# import os

# def get_readable_size(size_in_bytes):
#     """Convert bytes to KB, MB, or GB for better readability."""
#     for unit in ['B', 'KB', 'MB', 'GB']:
#         if size_in_bytes < 1024:
#             return f"{size_in_bytes:.2f} {unit}"
#         size_in_bytes /= 1024
#     return f"{size_in_bytes:.2f} TB"

# def list_file_sizes(folder_path):
#     """List all files and their sizes in the specified folder."""
#     if not os.path.exists(folder_path):
#         print("❌ Folder not found.")
#         return

#     print("\n📂 File Size Report")
#     print("-" * 40)

#     total_size = 0
#     for filename in os.listdir(folder_path):
#         file_path = os.path.join(folder_path, filename)

#         if os.path.isfile(file_path):
#             size = os.path.getsize(file_path)
#             readable_size = get_readable_size(size)
#             total_size += size
#             print(f"{filename:30} {readable_size}")

#     print("-" * 40)
#     print(f"Total Size: {get_readable_size(total_size)}")

# if __name__ == "__main__":
#     folder = input("Enter folder path to check file sizes: ")
#     list_file_sizes(folder)

# Output =>
# Enter folder path to check file sizes: D:\60DaysOfCode

# 📂 File Size Report
# ----------------------------------------
# day01_notes.md                 1.24 KB
# file_sorter.py                 2.88 KB
# todo_list.py                   3.15 KB
# reverse_string.cpp             1.01 KB
# ----------------------------------------
# Total Size: 8.28 KB


