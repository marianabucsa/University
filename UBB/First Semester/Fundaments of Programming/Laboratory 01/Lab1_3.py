#  Calculate the greatest common factor of two numbers

a = int(input("Introduceti nr: "))
b = int(input("Introduceti nr: "))

while a != b:
    if a > b:
        a = a - b
    else:
        b = b - a
print(a)
