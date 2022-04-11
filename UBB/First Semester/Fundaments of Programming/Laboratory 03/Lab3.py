# Definire meniu

def Meniu():
    lista = []
    comenzi = {1: [Citire_lista, "1.Citire lista"],
               2: [Secventa_maxima1, "2.Secventa maxima care are oricare doua elemente consecutive de semne contrare"],
               3: [Secventa_maxima2, "3.Secventa maxima care contine suma maxima"]}
    while True:
        StartProgram(comenzi)
        nr = int(input("Introduceti comanda:"))
        if nr == 4:
            return
        if nr in comenzi:
            comenzi[nr][0](lista)
        else:
            print("Comanda invalida")


# Afisare meniu 

def StartProgram(comenzi):
    print("Meniu")
    for i in (comenzi):
        print(comenzi[i][1])
    print("4.Iesire din aplicatie")


# Definirea comenzilor prin functii

# Comanda 1 : citire lista

def Citire_lista(lista):
    n = int(input("Introduceti numarul de elemente din lista: "))
    for i in range(0, n):
        lista.append(int(input("l[" + str(i) + "]=")))


# Comanda 2 : determinare secventa maxima 1

def Verificare_semne(a, b):
    if (a <= 0 and b <= 0) or (a > 0 and b > 0):
        return False
    return True


def Secventa_maxima1(lista):
    if not lista:
        print("Lista este vida")
        return
    lf = 0
    lmax = 0
    pi = 0
    pf = 0
    inceput = 0
    final = 0
    rez1 = []
    for i in range(0, len(lista) - 1):
        if Verificare_semne(lista[i], lista[i + 1]):
            if lf == 0:
                inceput = i
            lf = lf + 1
        else:
            final = i
            if lf > lmax:
                lmax = lf
                pi = inceput
                pf = final
            lf = 0
    if Verificare_semne(lista[len(lista) - 2], lista[len(lista) - 1]):
        if lf != 0:
            final = i + 1
            if lf > lmax:
                lmax = lf
                pi = inceput
                pf = final
    if pi != pf:
        for i in range(pi, pf + 1):
            rez1.append(lista[i])
    print(rez1)


# Comanda 3 : Deteminare secventa maxima 2

def Secventa_maxima2(lista):
    if not lista:
        print("Lista este vida")
        return
    suma_max = float('-inf')
    suma_min = 0
    pf = 0
    for i in range(0, len(lista)):
        suma_min = suma_min + lista[i]
        if suma_max < suma_min:
            suma_max = suma_min
            pf = i

        if suma_min < 0:
            suma_min = 0
    pi = pf
    suma = suma_max
    while suma > 0:
        suma = suma - lista[pi]
        if suma > 0:
            pi = pi - 1
    rez2 = []
    for i in range(pi, pf + 1):
        rez2.append(lista[i])
    print(rez2)


# Incepere program   
Meniu()
