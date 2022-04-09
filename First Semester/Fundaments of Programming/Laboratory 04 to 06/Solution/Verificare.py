def verifica_comanda(cmd, comenzi):
    # verifies if a command is valid
    # input: cmd- integer
    #        comenzi- dictionary
    # output: True- if cmd is in the dictionary
    #         False- otherwise
    if cmd in comenzi:
        return True
    return False


def verificare_scor(x):
    # verifies if the score is in range [1,10]
    # input: x-integer
    # output: exception-"\nScorInvalid!"
    if x > 10 or x < 1:
        raise Exception("\nScor invalid!")


def verificare_id(id_ul, lista_participanti):
    # verifies if the id is in the participants list
    # input: id_ul-integer
    #        lista_participanti-list
    # output: exception- "\n ID invalid!"
    if id_ul >= len(lista_participanti) or id_ul < 1:
        raise Exception("\nId invalid!")


def scor_valid(scor):
    # verifies if a score is valid
    # input: scor- integer
    # output: exception- "\nScor invalid!"
    if scor < 10 or scor > 100:
        raise Exception("\nScor invalid!")
