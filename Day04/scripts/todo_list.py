
tasks = []

def show_menu():
    print("\n📝 To-Do List Menu")
    print("1. Add Task")
    print("2. View Tasks")
    print("3. Remove Task")
    print("4. Exit")

def add_task():
    task = input("Enter new task: ")
    tasks.append(task)
    print("✅ Task added successfully!")

def view_tasks():
    if not tasks:
        print("📭 No tasks found.")
    else:
        print("\nYour Tasks:")
        for i, task in enumerate(tasks, 1):
            print(f"{i}. {task}")

def remove_task():
    view_tasks()
    try:
        task_no = int(input("Enter task number to remove: "))
        if 1 <= task_no <= len(tasks):
            removed = tasks.pop(task_no - 1)
            print(f"❌ Removed: {removed}")
        else:
            print("⚠️ Invalid task number.")
    except ValueError:
        print("⚠️ Please enter a valid number.")

while True:
    show_menu()
    choice = input("Enter your choice (1-4): ")

    if choice == '1':
        add_task()
    elif choice == '2':
        view_tasks()
    elif choice == '3':
        remove_task()
    elif choice == '4':
        print("👋 Exiting To-Do App. Have a productive day!")
        break
    else:
        print("⚠️ Invalid option. Try again.")

# Output =>
# 📝 To-Do List Menu
# 1. Add Task
# 2. View Tasks
# 3. Remove Task
# 4. Exit
# Enter your choice (1-4): 1
# Enter new task: Learn new concept
# ✅ Task added successfully!

# 📝 To-Do List Menu
# 1. Add Task
# 2. View Tasks
# 3. Remove Task
# 4. Exit
# Enter your choice (1-4): 2

# Your Tasks:
# 1. Learn new concept

# 📝 To-Do List Menu
# 1. Add Task
# 2. View Tasks
# 3. Remove Task
# 4. Exit
# Enter your choice (1-4): 3

# Your Tasks:
# 1. Learn new concept
# Enter task number to remove: 1
# ❌ Removed: Learn new concept

# 📝 To-Do List Menu
# 1. Add Task
# 2. View Tasks
# 3. Remove Task
# 4. Exit
# Enter your choice (1-4): 4
# 👋 Exiting To-Do App. Have a productive day!
