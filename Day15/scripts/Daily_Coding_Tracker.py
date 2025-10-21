# day15_coding_tracker.py

import os
from datetime import datetime

LOG_FILE = "coding_log.txt"

def log_coding_session(day, problems_solved, notes):
    now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    entry = f"Date: {now}\nDay: {day}\nProblems Solved: {problems_solved}\nNotes: {notes}\n{'-'*50}\n"
    
    with open(LOG_FILE, "a", encoding="utf-8") as f:
        f.write(entry)
    
    print(f"✅ Logged Day {day} session successfully!")

def main():
    day = input("Enter Day Number: ")
    problems_solved = input("Enter problems solved today (comma separated): ")
    notes = input("Enter any notes/thoughts for today: ")
    
    log_coding_session(day, problems_solved, notes)

if __name__ == "__main__":
    main()

# Output =>
# Enter Day Number: 15
# Enter problems solved today (comma separated): Diameter of Binary Tree, Lowest Common Ancestor, Maximum Path Sum
# Enter any notes/thoughts for today: Practiced tree traversal and recursion
# ✅ Logged Day 15 session successfully!

