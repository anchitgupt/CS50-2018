from cs50 import get_float

while True:
    print ("Change owed: ", end="")
    amount = get_float() * 100
    if amount > -1 :
        break

coin = 0

while amount > 0:
    if (amount >= 25):
        amount -=25
        coin += 1
    elif (amount >= 10):
        amount -= 10
        coin += 1
    elif (amount >= 5):
        amount -=5
        coin += 1
    else:
        amount -= 1
        coin += 1


print(coin)