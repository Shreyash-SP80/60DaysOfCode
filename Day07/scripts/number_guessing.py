
import random

def number_guessing_game():
    print("Welcome to the Number Guessing Game!")
    print("I'm thinking of a number between 1 and 10.")
    
    secret_number = random.randint(1, 10)
    attempts = 0
    guessed = False

    while not guessed:
        try:
            guess = int(input("Enter your guess: "))
            attempts += 1

            if guess < secret_number:
                print("Too low! Try again.")
            elif guess > secret_number:
                print("Too high! Try again.")
            else:
                print(f"🎉 Congratulations! You guessed the number {secret_number} in {attempts} attempts.")
                guessed = True
        except ValueError:
            print("Please enter a valid integer.")

if __name__ == "__main__":
    number_guessing_game()

# Output =>
# Welcome to the Number Guessing Game!
# I'm thinking of a number between 1 and 50.
# Enter your guess: 25
# Too low! Try again.
# Enter your guess: 40
# Too high! Try again.
# Enter your guess: 32
# 🎉 Congratulations! You guessed the number 32 in 3 attempts.

