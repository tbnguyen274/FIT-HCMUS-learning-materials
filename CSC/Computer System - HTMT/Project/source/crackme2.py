def username_hash(username):
    """
    Calculate hash value from the first 5 characters of the username.
    """

    input_str = username[:5].upper()    ## Convert to uppercase first
    result = 0
    for ch in input_str:
        ascii_val = ord(ch)
        if 'A' <= ch <= 'Z':
            val = ascii_val - ord('A')
        else:
            val = 0
        result = result * 26 + val
    
    print(f"Hash value for '{input_str}': {result}")
    return result

def calculate_coeffs(x):
    """
    x = ecx1 * 36^4 + ecx2 * 36^3 + ecx3 * 36^2 + ecx4 * 36^1 + ecx5
    Returns list of 5 coefficients [ecx5, ecx4, ecx3, ecx2, ecx1].
    """

    coefficients = []
    for i in range(5):
        coefficients.append(x % 36)
        x //= 36
    return coefficients  # [ecx5, ecx4, ecx3, ecx2, ecx1]

def generate_part(coefficients, table_start_index):
    """
    Generate 5-character part of the serial based on the coefficients and starting index.
    """

    magic_string = "AGMSY4BHNTZ5CIOU06DJPV17EKQW28FLRX39"
    result = ""

    for i in range(5):
        # Calculate index
        char_index = (table_start_index + coefficients[i]) % len(magic_string)
        # Append character to result
        result += magic_string[char_index]
    
    return result

def generate_serial(username):
    """
    Generate serial key based on the username.
    """

    if len(username) < 5:
        return "Username must be at least 5 characters long."
    
    # Calculate hash from username
    hash_value = username_hash(username)
    
    # Break down the hash value into base-36 coefficients
    coefficients = calculate_coeffs(hash_value)
    
    # Generate each part of the serial
    part1 = generate_part(coefficients, 0)  # Start with index A (0)
    part2 = generate_part(coefficients, 6)  # Start with index B (1)
    part3 = generate_part(coefficients, 12)  # Start with index C (2)
    part4 = generate_part(coefficients, 18)  # Start with index D (3)
    
    # Combine all parts with hyphens "-"
    serial = f"{part1}-{part2}-{part3}-{part4}"
    
    return serial

def main():
    print("Crackme2 - WinCrackMe KeyGen")
    print("--------------------------------")
    
    while True:
        username = input("\nEnter username (at least 5 characters): ")
        
        if len(username) < 5:
            print("Username must be at least 5 characters long.")
            continue
        
        serial = generate_serial(username)
        print(f"\nUsername: {username}")
        print(f"Serial  : {serial}")
        
        another = input("\nGenerate another key? (y/n): ")
        if another.lower() != 'y':
            break
        print()

if __name__ == "__main__":
    main()