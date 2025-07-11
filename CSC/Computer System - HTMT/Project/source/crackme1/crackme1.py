from re import split
from random import choice

def f1(n):
    return n[5] * n[1] * n[6] + n[2] * n[7] * n[3] + n[8] * n[4] * n[0] - (n[3] * n[1] * n[8] + n[0] * n[7] * n[5] + n[6] * n[4] * n[2])

def check_value(number5, digit, number3, number9, number7):
    return 10000 * (number5 % 10) + 1000 * (digit % 10) + 100 * (int(number3 / 10) % 10 + 5) + 10 * (int(number9 / 10) % 10) + (number7 % 10) + 2

def check_condition(n):
    if n[0] % 10 == n[5] % 10 == (n[1] % 10) + 3:
        r1 = f1(n)
        check1 = check_value(n[4], n[0], n[2], n[8], n[6])
        check2 = check_value(n[4], n[5], n[2], n[8], n[6])
        check3 = check_value(n[4], (n[1] % 10) + 3, n[2], n[8], n[6])
        return r1 == check1 == check2 == check3
    return False

def random_numbers():
    success = False
    while not success:
        number2 = choice(range(1, 100))
        number1 = number6 = number2 + 3
        number3 = number4 = number5 = number7 = number8 = choice(range(1, 100))

        number9 = 0
        r1 = -1
        check1 = check2 = check3 = 0
        while r1 < check1 or r1 < check2 or r1 < check3:
            number9 += 1
            n = [number1, number2, number3, number4, number5, number6, number7, number8, number9]
            r1 = f1(n)
            check1 = check_value(number5, number1, number3, number9, number7)
            check2 = check_value(number5, number6, number3, number9, number7)
            check3 = check_value(number5, (number2 % 10) + 3, number3, number9, number7)

        if r1 == check1 == check2 == check3:
            success = True
            return n

def process_words(words):
    count = 0
    print("\nWords with 9 letters (all lowercase):")
    for word in words:
        if len(word) == 9:
            n = [ord(c) for c in word]
            if check_condition(n):
                count += 1
                print(n, "".join(chr(i) for i in n))
    
    if count == 0:
        print("Not found any words.")

    print("\nWords with 9 letters (first letter uppercase):")
    for word in words:
        if len(word) == 9:
            n = [ord(c) for c in word]
            n[0] -= 0x20
            if check_condition(n):
                print(n, "".join(chr(i) for i in n))

def main():
    print("Random key pass the condition:")
    numbers = random_numbers()
    print(numbers)
    with open('input.txt', 'r', encoding='utf-8') as f:
        text = f.read()
    words = split(r"[\s:/,.:]", text)
    process_words(words)

if __name__ == "__main__":
    main()

import os
os.system('pause')