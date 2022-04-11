class Persoana:
    def __init__(self, personID, name, address):
        # initializeaza o persoana cu id, nume si adreasa
        # personID- intreg ; name, address- string
        self.__personID = personID
        self.__name = name
        self.__address = address

    def get_personID(self):
        # metoda getter
        # returneaza ID-ul persoanei
        return self.__personID

    def get_name(self):
        # metoda getter
        # returneaza numele persoanei
        return self.__name

    def get_address(self):
        # metoda getter
        # returneaza adresa persoanei
        return self.__address

    def set_name(self, nume):
        # metoda setter
        # seteaza numele
        self.__name = nume

    def set_address(self, adresa):
        # metoda setter
        # seteaza adresa
        self.__address = adresa

    def __eq__(self, p):
        # verifica daca doua obiecte de tip persoana sunt egale
        # p- persoana
        # returneaza True daca persoanele au acelasi ID
        return self.get_personID() == p.get_personID()

    @staticmethod
    def citesteDinFisier(line):
        p = line.split(" ", maxsplit=2)
        return Persoana(int(p[0]), p[1], p[2])

    @staticmethod
    def scrieInFisier(persoana):
        return str(persoana.get_personID()) + " " + str(persoana.get_name()) + " " + str(persoana.get_address())
