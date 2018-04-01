from cs50 import get_string
import sys
# checks for the exactly 2 arguments
if len(sys.argv) != 2:
    print('Nope')
    exit
# get the key value to cipher the plaintext
key = int(sys.argv[1])
# if key is less than 0
if key < 0:
    print("Nope", end = "")
    exit

print ("plaintext: ", end= "")
# getting the plain text
code = get_string()

print("ciphertext: ", end = "")
# loop through the plaintext
for char in code:
    if char.islower():
        print(chr((((ord(char) + key) -97 ) % 26) + 97), end="")
    elif char.isupper():
        print(chr((((ord(char) + key) -65 ) % 26) + 65), end="")
    else:
        print(char, end="")

print()