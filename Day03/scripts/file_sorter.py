import os
import shutil

def  sort_files(folder_path):
    file_types = {
        "Images": [".png", ".jpg", ".jpeg", ".gif"],
        "Documents": [".pdf", ".docx", ".txt", ".xlsx", ".bin"],
        "Videos": [".mp4", ".mkv", ".avi"],
        "Music": [".mp3", ".wav"],
        "Code": [".py", ".cpp", ".js", ".html", ".css"]
    }

    for filename in os.listdir(folder_path):
        file_path = os.path.join(folder_path, filename)

        if os.path.isfile(file_path):
            file_ext = os.path.splitext(filename)[1].lower()

            for folder, extension in file_types.items():
                if file_ext in extension:
                    folder_name = os.path.join(folder_path, folder)
                    os.makedirs(folder_name, exist_ok=True)  
                    shutil.move(file_path, os.path.join(folder_name, filename))
                    break
            
if __name__ == "__main__":
    folder = input("Enter folder path to organize: ")
    sort_files(folder)
    print("✅ Files sorted successfully!")
