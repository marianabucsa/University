# Se dă o listă de numere întregi a1,...an, determinați toate sub-secvențele cu lungime mai
# mare decât 2 cu proprietatea că: numerele sunt în ordine crescătoare şi numerele
# consecutive au cel puţin o cifră în comun.

def bun(s, lista, k):
    '''
    x- lista de elemente care vor determina o solutie
    returneaza True daca numerele sunt în ordine crescătoare şi numerele
    consecutive au cel puţin o cifră în comun.
    '''
    for i in range(k - 1):
        if lista[s[i]] >= lista[s[i + 1]]:
            return False
        if lista[s[i + 1]] - lista[s[i]] == 1:
            if nr_consecutive(lista[s[i]], lista[s[i + 1]]) == False:
                return False
    return True


def nr_consecutive(a, b):
    x = cifre_nr(a)
    y = cifre_nr(b)
    for i in x:
        for j in y:
            if i == j:
                return True
    return False


def cifre_nr(nr):
    cifre = []
    while nr > 0:
        cifre.append(nr % 10)
        nr //= 10
    return cifre


def solutie(x):
    if x > 2:
        return True
    return False


def create(s, lista):
    solutie = []
    for el in s:
        solutie.append(lista[el])
    return solutie[:]


def bkt_iterativ(lista):
    # backtracking iterativ
    if len(lista) == 1 or len(lista) == 0:
        return []
    rezultat = []
    s = []
    k = 0
    for i in range(len(lista)):
        s.append(-1)
    while k > -1:
        if s[k] < len(lista) - 1:
            s[k] += 1
            if bun(s, lista, k + 1):
                if solutie(k + 1):
                    rezultat.append(create(s[:-(len(lista) - k - 1)], lista))
                k += 1
        else:
            s[k] = -1
            k -= 1
    return rezultat[:]


def run():
    '''
    n - int, numarul de elemente ale listei
    lista - lista elementelor pentru care se genereaza permutarile
    '''
    n = int(input("Dati nr de elemente: "))
    lista = []
    print("Dati elementele listei:")
    for i in range(n):
        lista.append(int(input("l[" + str(i) + "]= ")))
    rezultat = bkt_iterativ(lista)
    for el in rezultat:
        print(el)


run()
