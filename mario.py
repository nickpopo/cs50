from cs50 import get_int

# Check for proper usage
while True:
    height = get_int("height: ")
    if height >= 0 and height < 23:
        break
    print("Please non-negative and not more than 23")

# iterate row
for row in range(height):
    # print cell in row
    for count in range(2):
        if count == 0:
            print(" " * (height - row - 1), end = "")
            print("#" * (row + 1), end = "")
            print("  ", end="")
        # second tower but mirrow
        else:
            print("#" * (row + 1), end = "")
    # print new line
    print()