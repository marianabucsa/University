# Find the first prime number greater than a given number

n = int(input("Introduceti n:"))
i = n
gasit = 0
while gasit == 0:
    i = i + 1
    gasit = 1
    for d in range(2, int(i / 2)):
        if i % d == 0:
            gasit = 0
            break
print("Cel mai mic nr prim mai mare decat", n, "este", i)
