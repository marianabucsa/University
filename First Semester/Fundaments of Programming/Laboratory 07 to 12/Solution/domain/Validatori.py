class ValidatorException(Exception):
    def __init__(self, errors):
        self.__errors = errors

    def getErrors(self):
        return self.__errors


class ValidatorPersoana:
    # creeaza clasa validator persoana
    # verifica validitatea datelor persoanei
    def validare(self, persoana):
        eroare = ""
        if persoana.get_personID() < 0:
            eroare += "ID persoana invalid!\n"
        if persoana.get_name().strip() == '':
            eroare += "Numele nu poate fi vid!\n"
        if persoana.get_address().strip() == '':
            eroare += "Adresa nu poate fi vida!\n"
        if eroare != "":
            raise ValidatorException(eroare)


class ValidatorEveniment:
    # creeaza clasa validator eveniment
    # verifica validitatea datelor evenimentului
    def validare(self, eveniment):
        eroare = ""
        if eveniment.get_ID() < 0:
            eroare += "ID eveniment invalid!\n"
        data = eveniment.get_data()
        l = data.split(sep='/', maxsplit=2)
        if int(l[0]) > 31 or int(l[0]) < 1 or int(l[1]) < 1 or int(l[1]) > 12 or int(l[2]) < 2000 or int(
                l[2]) > 2100 or data == '':
            eroare += "Data invalida!\n"
        ora = eveniment.get_ora()
        l = ora.split(sep=':', maxsplit=1)
        if int(l[0]) > 24 or int(l[0]) < 0 or int(l[1]) < 0 or int(l[1]) > 59 or ora == '':
            eroare += "Ora invalida!\n"
        if eveniment.get_descriere() == "":
            eroare += "Descrierea nu poate fi vida!\n"
        if eroare != "":
            raise ValidatorException(eroare)


class ValidatorBilet:
    # creeaza clasa validator bilet
    # verifica validitatea datelor biletului
    def validare(self, bilet):
        eroare = ""
        if bilet.get_id_persoana() < 0:
            eroare += "\nID persoana invalid!\n"
        if bilet.get_id_eveniment() < 0:
            eroare += "\nID eveniment invalid!\n"
        if bilet.get_pret() < 0:
            eroare += "\nPret bilet invalid!\n"
        if eroare != "":
            raise ValidatorException(eroare)
