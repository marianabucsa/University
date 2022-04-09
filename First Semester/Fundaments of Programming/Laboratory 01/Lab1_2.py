# Check that a keyboard read number is prime

nr = int(input("Introduceti nr: "))
d = 2
ok = 1
for d in range(2, nr):
    if nr % d == 0:
        ok = 0
if ok == 1:
    print("Nr prim")
else:
    print("Nr nu este prim")
