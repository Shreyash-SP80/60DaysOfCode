import os

# 📝 Folder path where files are located
folder_path = "./"  # current folder, you can change to any path

# 📝 Prefix you want for renamed files
prefix = "File_"

# 📝 Get all files in the folder
files = os.listdir(folder_path)

# 📝 Counter to give unique names
count = 1

for filename in files:
    # Skip directories
    if os.path.isfile(os.path.join(folder_path, filename)):
        # Get file extension
        ext = os.path.splitext(filename)[1]  # includes the dot, e.g., ".txt"
        
        # Create new file name
        new_name = f"{prefix}{count}{ext}"
        
        # Rename the file
        os.rename(os.path.join(folder_path, filename),
                  os.path.join(folder_path, new_name))
        
        print(f"Renamed '{filename}' to '{new_name}'")
        count += 1
