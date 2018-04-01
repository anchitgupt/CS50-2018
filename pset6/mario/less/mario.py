from cs50 import get_int

while True:
    print("Height: ",end= " ")
    height = get_int()
    if height > -1 and height < 24:
        break

for i in range(height):
    for j in range(height-i-1):
        print(" ",end="")
    for k in range(i+2):
        print("#", end="")

    print()

