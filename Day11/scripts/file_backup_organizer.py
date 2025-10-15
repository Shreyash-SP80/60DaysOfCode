import os
import shutil
from datetime import datetime

def backup_files(source, destination):
    if not os.path.exists(source):
        print("❌ Source folder not found!")
        return
    
    timestamp = datetime.now().strftime("%Y-%m-%d_%H-%M-%S")
    backup_folder = os.path.join(destination, f"Backup_{timestamp}")
    os.makedirs(backup_folder, exist_ok=True)

    for file_name in os.listdir(source):
        src_path = os.path.join(source, file_name)
        dest_path = os.path.join(backup_folder, file_name)
        if os.path.isfile(src_path):
            shutil.copy2(src_path, dest_path)

    print(f"✅ Backup completed successfully in: {backup_folder}")

if __name__ == "__main__":
    src = input("Enter source folder path: ")
    dest = input("Enter destination folder path: ")
    backup_files(src, dest)
