from cs50 import get_int


# Promt user for credit card number
card = get_int("Card number: ")

# convert card number to string
card_str = str(card)

# check for type of card
if card_str[0] == "4":
    cardType = "VISA"
elif card_str[0] == "3" and (card_str[1] == "4" or card_str[1] == "7"):
    cardType = "AMEX"
elif card_str[0] == "5" and (card_str[1] == "1" or card_str[1] == "2" or card_str[1] == "3" or card_str[1] == "4" or card_str[1] == "5"):
    cardType = "MASTERCARD"
else:
    cardType = "INVALID"

# check checksum
if cardType != "INVALID":
    check=[]
    sum = 0
    for num in range(1, lenghtCard, 2):
        check.append(card_str[num])
    checkLength = len(check)
    for num in range(checkLength):
        check[num] = str(int(check[num])*2)
    for element in check:
        sum = sum + int(element) if len(element) != 2 else sum + int(element[0]) + int(element[1])
    for num in range(0, lenghtCard, 2):
        sum = sum + int(card_str[num])
    if sum % 10 == 0:
        print(cardType)
    else:
        print(cardType)


    
    

