def selection_sort(lista, key=lambda x: x, reversed=False):
    for i in range(0, len(lista) - 1):
        for j in range(i + 1, len(lista)):
            if not reversed:
                if key(lista[j]) < key(lista[i]):
                    lista[i], lista[j] = lista[j], lista[i]
            if reversed:
                if key(lista[j]) > key(lista[i]):
                    lista[i], lista[j] = lista[j], lista[i]
    return lista[:]


def shake_sort(lista, key=lambda x: x, reversed=False):
    left = 0
    right = len(lista) - 1
    last_swap = 0
    while left < right:
        for i in range(right, left, -1):
            if not reversed:
                if key(lista[i - 1]) > key(lista[i]):
                    lista[i], lista[i - 1] = lista[i - 1], lista[i]
                    last_swap = i
            if reversed:
                if key(lista[i - 1]) < key(lista[i]):
                    lista[i], lista[i - 1] = lista[i - 1], lista[i]
                    last_swap = i
        left = last_swap
        for i in range(left, right):
            if not reversed:
                print(key(lista[i]))
                if key(lista[i]) > key(lista[i + 1]):
                    lista[i], lista[i + 1] = lista[i + 1], lista[i]
                    last_swap = i
            if reversed:
                if key(lista[i]) < key(lista[i + 1]):
                    lista[i], lista[i + 1] = lista[i + 1], lista[i]
                    last_swap = i
        right = last_swap
    return lista[:]


def selection_sort_2keys(lista, key1=lambda x: x, key2=lambda x: x, reversed=False):
    for i in range(0, len(lista) - 1):
        for j in range(i + 1, len(lista)):
            if not reversed:
                if key1(lista[j]) < key1(lista[i]):
                    lista[i], lista[j] = lista[j], lista[i]
                else:
                    if key1(lista[j]) == key1(lista[i]):
                        if key2(lista[j]) < key2(lista[i]):
                            lista[i], lista[j] = lista[j], lista[i]
            if reversed:
                if key1(lista[j]) > key1(lista[i]):
                    lista[i], lista[j] = lista[j], lista[i]
                else:
                    if key1(lista[j]) == key1(lista[i]):
                        if key2(lista[j]) > key2(lista[i]):
                            lista[i], lista[j] = lista[j], lista[i]
    return lista[:]
