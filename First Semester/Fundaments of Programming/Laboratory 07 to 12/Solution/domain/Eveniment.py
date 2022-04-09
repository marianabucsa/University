import datetime


class Eveniment:
    def __init__(self, ID, data, ora, descriere):
        # initializeaza un eveniment cu ID, data, ora, descriere
        # ID-intreg, data-, descriere-string
        self.__ID = ID
        self.__data = data
        self.__ora = ora
        self.__descriere = descriere

    def get_ID(self):
        # metoda getter
        # returneaza ID-ul evenimentului
        return self.__ID

    def get_data(self):
        # metoda getter
        # returneaza data evenimentului
        return self.__data

    def get_data_lista(self):
        # metoda getter
        # returneaza data evenimentului sub forma de lista
        l = self.__data.split("/", maxsplit=2)
        lista=[]
        lista.append(l[2])
        lista.append(l[1])
        lista.append(l[0])
        return lista
        # datetime.datetime.strptime(self.__data, '%d/%m/%Y')

    def get_ora(self):
        # metoda getter
        # returneaza ora evenimentului
        return self.__ora

    def get_descriere(self):
        # metoda getter
        # returneaza descrierea evenimentului
        return self.__descriere

    def set_data(self, data):
        # metoda setter
        # seteaza data
        self.__data = data

    def set_ora(self, ora):
        # metoda setter
        # seteaza ora
        self.__ora = ora

    def set_descriere(self, descriere):
        # metoda setter
        # seteaza descrierea
        self.__descriere = descriere

    def __eq__(self, e):
        # verifica daca doua obiecte de tip eveniment sunt egale
        # e- eveniment
        # returneaza True daca obiectele au ID-urile egale
        return self.get_ID() == e.get_ID()

    @staticmethod
    def citesteDinFisier(line):
        e = line.split(" ", maxsplit=3)
        return Eveniment(int(e[0]), e[1], e[2], e[3])

    @staticmethod
    def scrieInFisier(eveniment):
        return str(eveniment.get_ID()) + " " + str(eveniment.get_data()) + " " + str(eveniment.get_ora()) + " " + str(
            eveniment.get_descriere())
