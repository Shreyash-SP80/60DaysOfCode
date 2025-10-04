import random
import string

def generate_password(length=10):
    # Characters: letters + digits + symbols
    characters = string.ascii_letters + string.digits + string.punctuation
    
    # Randomly choose characters
    password = ''.join(random.choice(characters) for _ in range(length))
    return password

if __name__ == "__main__":
    length = int(input("Enter password length: "))
    print("Generated Password:", generate_password(length))

# Output
# Enter password length: 11
# Generated Password: biIkp;^2o(X
