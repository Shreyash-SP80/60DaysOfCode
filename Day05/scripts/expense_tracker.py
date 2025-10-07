
expenses = []

def show_menu():
    print("\n💰 Expense Tracker Menu")
    print("1. Add Expense")
    print("2. View Expenses")
    print("3. Show Total")
    print("4. Exit")

def add_expense():
    try:
        amount = float(input("Enter expense amount: "))
        desc = input("Enter description: ")
        expenses.append((desc, amount))
        print("✅ Expense added successfully!")
    except ValueError:
        print("⚠️ Please enter a valid number.")

def view_expenses():
    if not expenses:
        print("📭 No expenses recorded.")
        return
    print("\nYour Expenses:")
    for i, (desc, amount) in enumerate(expenses, 1):
        print(f"{i}. {desc} - ₹{amount}")

def show_total():
    total = sum(amount for desc, amount in expenses)
    print(f"\n💵 Total Expenses: ₹{total}")

while True:
    show_menu()
    choice = input("Enter your choice (1-4): ")

    if choice == '1':
        add_expense()
    elif choice == '2':
        view_expenses()
    elif choice == '3':
        show_total()
    elif choice == '4':
        print("👋 Exiting Expense Tracker. Stay organized!")
        break
    else:
        print("⚠️ Invalid option. Try again.")

# Output =>
# 💰 Expense Tracker Menu
# 1. Add Expense
# 2. View Expenses
# 3. Show Total
# 4. Exit
# Enter your choice (1-4): 1
# Enter expense amount: 200
# Enter description: Groceries    
# ✅ Expense added successfully!

# 💰 Expense Tracker Menu
# 1. Add Expense
# 2. View Expenses
# 3. Show Total
# 4. Exit
# Enter your choice (1-4): 2

# Your Expenses:
# 1. Groceries - ₹200.0

# 💰 Expense Tracker Menu
# 1. Add Expense
# 2. View Expenses
# 3. Show Total
# 4. Exit
# Enter your choice (1-4): 1
# Enter expense amount: 500
# Enter description: Utilities
# ✅ Expense added successfully!

# 💰 Expense Tracker Menu
# 1. Add Expense
# 2. View Expenses
# 3. Show Total
# 4. Exit
# Enter your choice (1-4): 2

# Your Expenses:
# 1. Groceries - ₹200.0
# 2. Utilities - ₹500.0

# 💰 Expense Tracker Menu
# 1. Add Expense
# 2. View Expenses
# 3. Show Total
# 4. Exit
# Enter your choice (1-4): 3

# 💵 Total Expenses: ₹700.0

# 💰 Expense Tracker Menu
# 1. Add Expense
# 2. View Expenses
# 3. Show Total
# 4. Exit
# Enter your choice (1-4): 4
# 👋 Exiting Expense Tracker. Stay organized!
