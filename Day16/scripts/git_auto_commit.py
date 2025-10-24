import os
from datetime import datetime

def git_auto_commit(day):
    commit_message = f"Day {day} progress update – {datetime.now().strftime('%d %B %Y')}"
    
    commands = [
        "git add .",
        f'git commit -m "{commit_message}"',
        "git push origin main"
    ]
    
    for cmd in commands:
        os.system(cmd)
    
    print(f"✅ Git commit pushed successfully for Day {day}")

if __name__ == "__main__":
    day = input("Enter Day Number: ")
    git_auto_commit(day)
