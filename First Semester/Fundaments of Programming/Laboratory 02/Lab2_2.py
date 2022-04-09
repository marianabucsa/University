# Given the date of birth( day/month/year), determine the person's age in days.

data = input("Introduceti data nasterii: ")
data_azi = input("Introduceti data de astazi: ")

zi = int(data[:2])
luna = int(data[4:5])
an = int(data[6:])

azi = int(data[:2])
luna_azi = int(data[4:5])
an_azi = int(data[6:])

if zi > 31 or zi <= 0:
    print("zi invalida")

if luna > 12 or luna <= 0:
    print("luna invalida")

zile = 0
for i in range(an, an_azi - 1):
    if i % 4 == 0 or i % 100 != 0:
        zile = zile + 366
    elif i % 400 == 0:
        zile = zile + 366
    else:
        zile = zile + 365
print(zile)

if luna < luna_azi:
    zile = zile + zi
if luna == luna_azi and zi > azi:
    zile = zile + azi
if luna > luna_azi:
    luna = luna_azi

i = 1
for i in range(1, luna):
    if i % 2 == 0 and i != 2:
        zile = zile + 30
    elif i == 2:
        zile = zile + 29
    else:
        zile = zile + 31

print(zile)
