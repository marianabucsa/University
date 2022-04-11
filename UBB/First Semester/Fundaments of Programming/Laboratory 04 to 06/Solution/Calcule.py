from Verificare import *


def afiseaza_cu_scor_mai_mic(scor, lista_participanti):
    # shows the participants with a lower score than a given score
    # input: lista_participanti-list
    # output:-
    scor_valid(scor)
    if len(lista_participanti) == 1:
        print("\nNu exista participanti!")
        return
    for i in range(1, len(lista_participanti)):
        if (lista_participanti[i] < scor) and (lista_participanti[i] >= 1):
            print("Participantul " + str(i) + " cu scorul: " + str(lista_participanti[i]))


def afiseaza_cu_scor_mai_mare(scor, lista_participanti):
    # shows the participants with a greater score than a given score
    # input: lista_participanti-list
    # output:-
    scor_valid(scor)
    if len(lista_participanti) == 1:
        print("\nNu exista participanti!")
        return
    lista = []
    for i in range(1, len(lista_participanti)):
        if lista_participanti[i] > scor:
            lista.append([i, lista_participanti[i]])
    lista.sort(key=lambda x: x[1], reverse=True)
    for elem in lista:
        print("Participantul " + str(elem[0]) + " cu scorul: " + str(elem[1]))


def filtrare_cu_scor_mai_mic(scor, lista_participanti, backup_lista):
    # filters the participants with a lower score than a given score
    # input: lista_participanti-list
    # output:-
    scor_valid(scor)
    if len(lista_participanti) == 1:
        print("\nNu exista participanti!")
        return
    backup_lista.append(lista_participanti[:])
    for i in range(1, len(lista_participanti)):
        if (lista_participanti[i] >= scor) and (lista_participanti[i] >= 1):
            lista_participanti[i] = -1


def undo(backup_lista):
    # returns the last version of the lista_participanti before the last operation
    # input: backup_lista - list
    # output: - list
    if len(backup_lista) == 1:
        raise Exception("Nu exista operatie pentru care sa se faca undo!")
    return backup_lista.pop()


def inserare_scor_participant(id_ul, lista_participanti, a, backup_lista):
    # inserts a score to a participant only if the participant doesn't already have one
    # input: id_ul- integer
    #        lista_participanti-list
    #        a-list
    # output: exception-("\n Participantul id are deja un scor")
    verificare_id(id_ul, lista_participanti)
    for elem in a:
        verificare_scor(elem)
    suma_total = 0
    for i in a:
        suma_total += i
    if lista_participanti[id_ul] != -1:
        raise Exception("\nParticipantul " + str(id_ul) + " are deja un scor!")
    else:
        backup_lista.append(lista_participanti[:])
        lista_participanti[id_ul] = suma_total


def adauga_scor_participant_lista(suma_total, lista_participanti, backup_lista):
    # calculates  the sum of the obtained scores for a participant and adds the result in the list
    # input: a- list
    #        lista_participanti-list
    # output: -
    backup_lista.append(lista_participanti[:])
    lista_participanti.append(suma_total)


def sterge_scor_participant(id_ul, lista_participanti, backup_lista):
    # deletes the score for a participant
    # input: id-ul- integer
    #        lista_participanti- list
    # output: -
    verificare_id(id_ul, lista_participanti)
    backup_lista.append(lista_participanti[:])
    lista_participanti[id_ul] = -1


def sterge_scor_interval_participanti(id1, id2, lista_participanti, backup_lista):
    # deletes the score for a range of participants
    # input: id1- integer
    #        id2- integer
    #        lista_participanti-list
    # output: exception-"\n Id-urile nu formeaza un interval!"
    verificare_id(id1, lista_participanti)
    verificare_id(id2, lista_participanti)
    if id1 > id2:
        raise Exception("\n Id-urile nu formeaza un interval!")
    else:
        backup_lista.append(lista_participanti[:])
        for i in range(id1, id2 + 1):
            lista_participanti[i] = -1


def inlocuieste_scor_participant(id_ul, lista_participanti, a, backup_lista):
    # replaces a score for a given participant's id
    # input: id_ul- integer
    #        lista_participanti- list
    # output:-
    verificare_id(id_ul, lista_participanti)
    for el in a:
        verificare_scor(el)
    suma_total = 0
    for i in a:
        suma_total += i
    backup_lista.append(lista_participanti[:])
    lista_participanti[id_ul] = suma_total


def creeaza_participant(scor):
    # adds the participants at the correct id
    # input: id_ul- integer
    #        scor- integer
    # output: lista-list
    suma = 0
    for el in scor:
        verificare_scor(el)
        suma += el
    return suma


def media_scorurilor_interval(id1, id2, lista_participanti):
    # calculates the average of the scores from an interval
    # input: id1,id2- integer
    #        lista_participanti- list
    # output: media- float
    verificare_id(id1, lista_participanti)
    verificare_id(id2, lista_participanti)
    if id1 > id2:
        raise Exception("\n Id-urile nu formeaza un interval!")
    else:
        suma = 0
        for i in range(id1, id2 + 1):
            suma += lista_participanti[i]
        media = suma / (id2 - id1 + 1)
    return media


def scor_mic_interval(id1, id2, lista_participanti):
    # gives the lower score from an interval
    # input: id1,id2- integer
    #        lista_participanti- list
    # output: minim : integer
    verificare_id(id1, lista_participanti)
    verificare_id(id2, lista_participanti)
    if id1 > id2:
        raise Exception("\n Id-urile nu formeaza un interval!")
    else:
        minim = lista_participanti[id1]
        for i in range(id1 + 1, id2 + 1):
            if lista_participanti[i] < minim:
                minim = lista_participanti[i]
    return minim


def scor_multiplu_de_10(id1, id2, lista_participanti):
    # gives the scores than are multiple of 10 from the range [id1,id2]
    # input: id1,id2: integer
    #        lista_participanti-list
    # output: scoruri-list
    verificare_id(id1, lista_participanti)
    verificare_id(id2, lista_participanti)
    if id1 > id2:
        raise Exception("\n Id-urile nu formeaza un interval!")
    else:
        scoruri = []
        for i in range(id1, id2 + 1):
            if lista_participanti[i] % 10 == 0:
                scoruri.append(lista_participanti[i])
    return scoruri


def filtrare_scor_multiplu(nr, lista_participanti):
    # filters the scores that are multiple for a given score
    # input: nr - integer
    #        lista_participanti- list
    # output: a- list
    a = []
    for el in lista_participanti:
        if el % nr == 0:
            a.append(el)
    return a
