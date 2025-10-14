import os
import shutil

def organize_folder(path):
    if not os.path.exists(path):
        print("Invalid path!")
        return

    files = os.listdir(path)
    for file in files:
        full_path = os.path.join(path, file)

        if os.path.isfile(full_path):
            ext = file.split('.')[-1]
            folder_name = os.path.join(path, ext.upper() + "_Files")
            os.makedirs(folder_name, exist_ok=True)
            shutil.move(full_path, os.path.join(folder_name, file))
    
    print("✅ Folder organized successfully!")

if __name__ == "__main__":
    folder_path = input("Enter the path to organize: ")
    organize_folder(folder_path)
