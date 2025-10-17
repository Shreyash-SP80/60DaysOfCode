import os
from datetime import date

def create_day13_files():
    day = "Day13"
    base_path = os.getcwd()
    day_folder = os.path.join(base_path, day)

    # Create Day13 folder if not exists
    os.makedirs(day_folder, exist_ok=True)

    # Create 3 DSA problem files
    problems = [
        "construct_tree.cpp",
        "same_tree.cpp",
        "symmetric_tree.cpp"
    ]

    for problem in problems:
        file_path = os.path.join(day_folder, problem)
        if not os.path.exists(file_path):
            with open(file_path, "w") as f:
                f.write("// " + problem + " - Solved on " + str(date.today()) + "\n")
            print(f"✅ Created: {problem}")
        else:
            print(f"⚠️ Already exists: {problem}")

    # Create note.md file
    note_path = os.path.join(day_folder, "note.md")
    if not os.path.exists(note_path):
        with open(note_path, "w") as f:
            f.write(f"# 📘 Day 13 Notes — {date.today()}\n\n")
            f.write("## ✅ Problems Solved\n")
            f.write("1. Construct Binary Tree from Preorder and Inorder Traversal\n")
            f.write("2. Check if Two Binary Trees are Same\n")
            f.write("3. Check if Binary Tree is Symmetric\n\n")
            f.write("## 🧩 Key Concepts Learned\n")
            f.write("- Binary Tree Traversal (Preorder, Inorder, Postorder)\n")
            f.write("- Tree Reconstruction from Traversal Orders\n")
            f.write("- Recursive Tree Comparison\n")
            f.write("- Mirror Property and Symmetry in Trees\n\n")
            f.write("## 💡 Takeaway\n")
            f.write("Understanding recursion deeply helps in solving most tree-based problems effectively.\n")
        print("📝 Created: note.md")
    else:
        print("⚠️ note.md already exists")

if __name__ == "__main__":
    create_day13_files()
