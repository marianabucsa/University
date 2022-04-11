#  Determine the twin prime numbers p1 and p2 immediately greater than a natural number N given ( n!= 0).
#  Two prime numbers p1 and p2 are twins if p2-p1 = 2.

n = int(input("Introduceti n: "))
gasit = 0
i = n
while gasit == 0:
    i = i + 1
    prim = 1
    for d in range(2, (i + 2) // 2 + 1):
        if i % d == 0 or (i + 2) % d == 0:
            prim = 0
    if prim == 1:
        gasit = 1
print("Numere prime gemene sunt: ", i, i + 2)
