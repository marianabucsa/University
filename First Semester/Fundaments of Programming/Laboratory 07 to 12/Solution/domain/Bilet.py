class Bilet():
    def __init__(self, id_persoana, id_eveniment, pret):
        # initializeaza un bilet cu nr_bilet, persoana si eveniment
        # nr_bilet- intreg
        # persoana - obiect de tip Persoana
        # eveniment- obiect de tip Eveniment
        self.__id_persoana = id_persoana
        self.__id_eveniment = id_eveniment
        self.__pret = pret

    def get_id_persoana(self):
        # metoda getter
        # returneaza persoana biletului
        return self.__id_persoana

    def get_id_eveniment(self):
        # metoda getter
        # returneaza evenimentul biletului
        return self.__id_eveniment

    def get_pret(self):
        # metoda getter
        # returneaza pretul biletului
        return self.__pret

    def set_id_persoana(self, id_persoana):
        # metoda setter
        # seteaza o persoana pentru bilet
        self.__id_persoana = id_persoana

    def set_id_eveniment(self, id_eveniment):
        # metoda setter
        # seteaza un eveniment pentru bilet
        self.__id_eveniment = id_eveniment

    def set_pret(self, pret):
        # metoda setter
        # seteaza un pret pentru un bilet
        self.__pret = pret

    def __eq__(self, bilet):
        if self.get_id_persoana() == bilet.get_id_persoana() and self.get_id_eveniment() == bilet.get_id_eveniment():
            return True
        return False

    @staticmethod
    def citesteDinFisier(line):
        bilet = line.split(" ", maxsplit=2)
        return Bilet(int(bilet[0]), int(bilet[1]), int(bilet[2]))

    @staticmethod
    def scrieInFisier(bilet):
        return str(bilet.get_id_persoana()) + " " + str(bilet.get_id_eveniment()) + " " + str(bilet.get_pret())


class BiletperDTO():
    def __init__(self, id_persoana, nr_evenimente):
        self.__id_persoana = id_persoana
        self.__nr_evenimente = nr_evenimente

    def get_id_persoana(self):
        # metoda getter
        # returneaza id-ul persoanei
        return self.__id_persoana

    def get_nr_evenimente(self):
        # metoda getter
        # returneaza nr de evenimente la care participa persoana
        return self.__nr_evenimente

    def incEv(self):
        # incrementeaza nr de evenimente
        self.__nr_evenimente = self.__nr_evenimente + 1


class BileteveDTO():
    def __init__(self, id_eveniment, nr_persoane):
        self.__id_eveniment = id_eveniment
        self.__nr_persoane = nr_persoane

    def get_id_eveniment(self):
        # metoda getter
        # returneaza id-ul evenimentului
        return self.__id_eveniment

    def get_nr_persoane(self):
        # metoda getter
        # returneaza nr de persoane care perticipa la un eveniment
        return self.__nr_persoane

    def incPer(self):
        # incrementeaza nr de persoane
        self.__nr_persoane = self.__nr_persoane + 1
