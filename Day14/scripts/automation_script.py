# day14_script_fixed.py

import os
from datetime import datetime

# -----------------------------
# Configuration
# -----------------------------
DAY_NUMBER = 14
FOLDER_NAME = f"Day{DAY_NUMBER}"
DSA_FILES = ["problem1.cpp", "problem2.cpp", "problem3.cpp"]
NOTE_FILE = "note.md"
LOG_FILE = "progress_log.txt"

# -----------------------------
# Helper Functions
# -----------------------------
def create_folder(folder_name):
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)
        print(f"✅ Folder '{folder_name}' created.")
    else:
        print(f"⚠️ Folder '{folder_name}' already exists.")

def create_dsa_files(folder_name, files):
    for file_name in files:
        file_path = os.path.join(folder_name, file_name)
        if not os.path.exists(file_path):
            with open(file_path, "w") as f:
                f.write(f"// {file_name} - DSA problem placeholder\n\n")
            print(f"✅ File '{file_name}' created.")
        else:
            print(f"⚠️ File '{file_name}' already exists.")

def create_note_md(folder_name, day_number, dsa_files):
    note_content = f"""# Day {day_number} – 60DaysOfCode

## Date: {datetime.now().strftime('%d %B %Y')}

---

## What I Did Today

1. Continued my **60DaysOfCode challenge**.
2. Solved **3 DSA problems in C++**:
   - {dsa_files[0]} → [Problem description here]
   - {dsa_files[1]} → [Problem description here]
   - {dsa_files[2]} → [Problem description here]
3. [Optional] Created Python scripts or utilities to automate tasks.

---

## Key Learnings

- Practiced **data structures and algorithms** in C++.
- Improved **problem-solving and debugging** skills.
- Learned to **organize code and notes** efficiently.

---

## Next Steps

- Solve **more complex DSA problems** tomorrow.
- Enhance previous scripts for better **automation and documentation**.
- Keep making **daily commits** and track progress.

---

> "Consistency in coding creates mastery over time."
"""
    note_path = os.path.join(folder_name, NOTE_FILE)
    # Writing content explicitly
    with open(note_path, "w", encoding="utf-8") as f:
        f.write(note_content)
    print(f"✅ Note file '{NOTE_FILE}' created and content written successfully.")

def log_progress(day_number, folder_name):
    log_entry = f"{datetime.now().strftime('%Y-%m-%d %H:%M:%S')} - Day {day_number} folder created: {folder_name}\n"
    with open(LOG_FILE, "a", encoding="utf-8") as f:
        f.write(log_entry)
    print(f"✅ Progress logged in '{LOG_FILE}'.")

# -----------------------------
# Main Execution
# -----------------------------
def main():
    create_folder(FOLDER_NAME)
    create_dsa_files(FOLDER_NAME, DSA_FILES)
    create_note_md(FOLDER_NAME, DAY_NUMBER, DSA_FILES)
    log_progress(DAY_NUMBER, FOLDER_NAME)

if __name__ == "__main__":
    main()
