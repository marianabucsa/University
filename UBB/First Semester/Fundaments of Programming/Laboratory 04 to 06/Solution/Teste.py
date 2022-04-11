from Calcule import *
from Interfata import ui_undo


def rulare_teste():
    # runs all the tests
    test_verificare_scor()
    test_adauga_scor_lista()
    test_verificare_id()
    test_inserare_scor_participant()
    test_stergere_scor_participant()
    test_stergere_scor_interval_participanti()
    test_scor_valid()
    test_inlocuieste_scor_participant()
    test_creaza_participant()
    test_media_scorurilor_interval()
    test_scor_mic_interval()
    test_scor_multiplu_de_10()
    test_filtrare_scor_multiplu()
    test_ui_undo()


def test_ui_undo():
    # test for undo feature
    lista_particitipanti = [-1, 20, 30, 40]
    backup_lista = [-1, 20, 30, 40]
    adauga_scor_participant_lista(50, lista_particitipanti, backup_lista)
    ui_undo(lista_particitipanti, backup_lista)
    assert lista_particitipanti == [-1, 20, 30, 40]

    lista_particitipanti = [-1, 20, 30, 40]
    backup_lista = [-1, 20, 30, 40]
    sterge_scor_participant(1, lista_particitipanti, backup_lista)
    ui_undo(lista_particitipanti, backup_lista)
    assert lista_particitipanti == [-1, 20, 30, 40]


def test_media_scorurilor_interval():
    # test for average of the scores in an interval
    assert media_scorurilor_interval(1, 5, [-1, 10, 20, 30, 40, 50]) == 30
    assert media_scorurilor_interval(1, 2, [-1, 10, 20]) == 15


def test_creaza_participant():
    # test for creating a participant
    assert creeaza_participant((1, 1, 1, 1, 1, 1, 1, 1, 1, 1)) == 10
    assert creeaza_participant((2, 2, 2, 2, 2, 2, 2, 2, 2, 2)) == 20


def test_verificare_scor():
    # test for score verification
    try:
        verificare_scor(-1)
        assert False
    except Exception as ve:
        assert (str(ve) == "\nScor invalid!")
    try:
        verificare_scor(11)
        assert False
    except Exception as ve:
        assert (str(ve) == "\nScor invalid!")


def test_verificare_id():
    # test for id verification
    try:
        verificare_id(-7, [-1, 10, 20, 30])
        assert False
    except Exception as ve:
        assert (str(ve) == "\nId invalid!")
    try:
        verificare_id(0, [-1, 20, 20])
        assert False
    except Exception as ve:
        assert (str(ve) == "\nId invalid!")


def test_adauga_scor_lista():
    # test for adding a score to a new participant
    suma_total = 55
    lista_participanti = [-1, 20, 30]
    backup_lista = [-1, 20, 30]
    adauga_scor_participant_lista(suma_total, lista_participanti, backup_lista)
    assert len(lista_participanti) == 4
    assert lista_participanti[3] == 55

    a = 51
    lista_participanti = [-1]
    backup_lista = [-1]
    adauga_scor_participant_lista(a, lista_participanti, backup_lista)
    assert len(lista_participanti) == 2
    assert lista_participanti[1] == 51


def test_inserare_scor_participant():
    # test for insertion of a score to a participant
    lista_participanti = [-1, 20, -1, 55]
    backup_lista = [-1, 20, -1, 55]
    id_ul = 2
    a = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    inserare_scor_participant(id_ul, lista_participanti, a, backup_lista)
    assert lista_participanti[2] == 10
    lista_participanti = [-1, 20, 30, 55]
    backup_lista = [-1, 20, 30, 55]
    id_ul = 2
    a = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    try:
        inserare_scor_participant(id_ul, lista_participanti, a, backup_lista)
        assert False
    except Exception as es:
        assert (str(es) == "\nParticipantul " + str(id_ul) + " are deja un scor!")


def test_stergere_scor_participant():
    # test for deletion of a score
    lista_participanti = [-1, 20, 30, 55]
    backup_lista = [-1, 20, 30, 55]
    id_ul = 3
    sterge_scor_participant(id_ul, lista_participanti, backup_lista)
    assert lista_participanti[3] == -1


def test_stergere_scor_interval_participanti():
    # test for deletion of a score  for a range of participants
    lista_participanti = [-1, 20, 30, 55, 60, 70]
    backup_lista = [-1, 20, 30, 55, 60, 70]
    id1 = 1
    id2 = 4
    sterge_scor_interval_participanti(id1, id2, lista_participanti, backup_lista)
    assert lista_participanti[1] == -1
    assert lista_participanti[2] == -1
    assert lista_participanti[3] == -1
    assert lista_participanti[4] == -1
    lista_participanti = [-1, 20, 30, 55, 60, 70]
    backup_lista = [-1, 20, 30, 55, 60, 70]
    id1 = 4
    id2 = 1
    try:
        sterge_scor_interval_participanti(id1, id2, lista_participanti, backup_lista)
        assert False
    except Exception as ve:
        assert (str(ve) == "\n Id-urile nu formeaza un interval!")


def test_inlocuieste_scor_participant():
    # test for replacing the score of a participant
    lista_participanti = [-1, 20, 30, 50]
    backup_lista = [-1, 20, 30, 50]
    id_ul = 2
    a = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    inlocuieste_scor_participant(id_ul, lista_participanti, a, backup_lista)
    assert lista_participanti[2] == 10


def test_scor_valid():
    # test for the validation of a score
    try:
        scor_valid(1)
        assert False
    except Exception as ve:
        assert (str(ve) == "\nScor invalid!")
    try:
        scor_valid(101)
        assert False
    except Exception as ve:
        assert (str(ve) == "\nScor invalid!")


def test_filtrare_cu_scor_mai_mic():
    # test for the filtration with a lower score
    lista_participanti = [-1, 10, 20, 30, 40]
    scor = 30
    filtrare_cu_scor_mai_mic(scor, lista_participanti)
    assert lista_participanti[3] == -1
    assert lista_participanti[4] == -1
    lista_participanti = [-1, 50, 10, 20, 60]
    scor = 30
    filtrare_cu_scor_mai_mic(scor, lista_participanti)
    assert lista_participanti[1] == -1
    assert lista_participanti[4] == -1


def test_scor_mic_interval():
    # test for the filtration with a lower score for a range
    assert scor_mic_interval(1, 2, [-1, 10, 20]) == 10
    assert scor_mic_interval(1, 3, [-1, 20, 10, 30]) == 10


def test_scor_multiplu_de_10():
    # test for the filtration with a score multiple of 10
    assert scor_multiplu_de_10(1, 3, [-1, 10, 25, 40]) == [10, 40]
    assert scor_multiplu_de_10(1, 3, [-1, 15, 25, 36, 50]) == []


def test_filtrare_scor_multiplu():
    # test for the filtration with a score multiple of a given number
    assert filtrare_scor_multiplu(5, [-1, 10, 23, 30, 50]) == [10, 30, 50]
    assert filtrare_scor_multiplu(5, [-1, 13, 12, 14]) == []
