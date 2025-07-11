def generate_key(username):
    if len(username) < 5:
        raise ValueError("Username must have at least 5 character.")
    if len(username) > 7:
        print("WARNING: A username with 8 OR MORE characters might cause the program to crash!!!")
    
    R1 = sum(ord(char) for char in username)
    temp = len(username) ** 3  # Number of characters 
    R1 = R1 ^ temp  # ASCII sum XOR len of username cubed
    R2 = ord(username[0]) * ord(username[-1]) # ASCII of first char * ASCII of last char
    R2 = R2 ** 2
    R2 = R2 ^ 0x0B221  # temp6 XOR 0x0B221 (const)
    R1 = R2 // R1 # part1 integer-divided by temp4
    
    return f"{R1}-{R2}"

def main():
    while True:
        try:
            username = input("Enter username: ")
            key = generate_key(username)
            print(f"Generated key: {key}")
        
        except ValueError as err:
            print(f"Error: {err}")
        except Exception as exc:
            print(f"An unexpected error occurred: {exc}")

        another = input("\nGenerate another key? (y/n): ")
        if another.lower() != 'y':
            break
        print()

if __name__ == "__main__":
    main()