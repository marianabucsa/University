from ListaEvenimente import FileStocareEvenimente
from ListaPersoane import RepositoryException, FileStocarePersoane
from domain.Bilet import Bilet


class StocareBilete():
    def __init__(self):
        # defineste obiectul StocareBilete
        # bilete - un dictionar
        self._bilete = {}

    def __len__(self):
        return len(self._bilete)

    def stocare(self, bilet):
        # stocheaza bilete
        # bilet este un obiect de tip bilet
        # arunca exceptie daca exista un bilet cu acelasi nr
        key = (bilet.get_id_persoana(), bilet.get_id_eveniment())
        if key in self._bilete:
            raise RepositoryException("\nBilet deja existent!\n")
        self._bilete[key] = bilet

    def stergere(self, bilet):
        # sterge un bilet
        # bilet este un obiect de tip bilet
        # arunca exceptie daca nu exista biletul
        key = (bilet.get_id_persoana(), bilet.get_id_eveniment())
        if key not in self._bilete:
            raise RepositoryException("\nBiletul nu exista!\n")
        self._bilete.pop(key)

    def stergere_by_persoana(self, id_persoana):
        # sterge un bilet
        # id_persoana intreg
        for key in self._bilete.copy():
            if key[0] == id_persoana:
                self._bilete.pop(key)

    def stergere_by_eveniment(self, id_eveniement):
        # sterge un bilet
        # id_eveniment intreg
        for key in self._bilete.copy():
            if key[1] == id_eveniement:
                self._bilete.pop(key)

    def modificare(self, bilet1, bilet2):
        # modifica un bilet
        # bilet este un obiect de tip bilet
        # arunca exceptie daca nu exista biletul
        key1 = (bilet1.get_id_persoana(), bilet1.get_id_eveniment())
        key2 = (bilet2.get_id_persoana(), bilet2.get_id_eveniment())
        if key1 not in self._bilete:
            raise RepositoryException("\nBiletul nu exista!\n")
        self._bilete.pop(key1)
        self._bilete[key2] = bilet2

    def nr_bilete(self):
        # determina cate bilete sunt stocate
        # returneaza un nr intreg
        return len(self._bilete)

    def lista_bilete(self):
        # returneaza o lista cu toate biletele stocate
        return list(self._bilete.values())[:]

    def dictionar_bilete(self):
        # returneaza un dictionar cu bilete
        return self._bilete.copy()


class FileStocareBilete(StocareBilete):
    def __init__(self, numef):
        self.__citestebfisier = Bilet.citesteDinFisier
        self.__scriebfisier = Bilet.scrieInFisier
        self.__numef = numef
        StocareBilete.__init__(self)
        self.__perRepo = FileStocarePersoane('persoane.txt')
        self.__eveRepo = FileStocareEvenimente('evenimente.txt')
        self.__citestebilfisier()
        self.__scriebilfisier()

    def __citestebilfisier(self):
        # citeste biletele din fisier
        with open(self.__numef, 'r') as fisier:
            bil = {}
            for line in fisier.readlines():
                line = line.strip()
                if len(line) > 0:
                    b = self.__citestebfisier(line)
                    key = (b.get_id_persoana(), b.get_id_eveniment())
                    bil[key] = b
            self._bilete = bil.copy()
        fisier.close()

    def __scriebilfisier(self):
        # scrie biletele in fisier
        with open(self.__numef, 'w') as fisier:
            for key in self._bilete:
                line = self.__scriebfisier(self._bilete[key])
                fisier.write(line + '\n')
        fisier.close()

    def __adaugabilfisier(self, bilet):
        # adauga un bilet in fisier
        with open(self.__numef, 'a') as fisier:
            line = self.__scriebfisier(bilet)
            fisier.write(line + '\n')
        fisier.close()

    def stocare(self, bilet):
        # stocheaza un bilet
        self.__citestebilfisier()
        StocareBilete.stocare(self, bilet)
        self.__adaugabilfisier(bilet)

    def modificare(self, bilet1, bilet2):
        # modifica un bilet
        self.__citestebilfisier()
        StocareBilete.modificare(self, bilet1, bilet2)
        self.__scriebilfisier()

    def stergere(self, bilet):
        # sterge un bilet
        self.__citestebilfisier()
        StocareBilete.stergere(self, bilet)
        self.__scriebilfisier()

    def stergere_by_persoana(self, id_persoana):
        # sterge biletele unei persoane
        self.__citestebilfisier()
        StocareBilete.stergere_by_persoana(self, id_persoana)
        self.__scriebilfisier()

    def stergere_by_eveniment(self, id_eveniement):
        # sterge biletele unui eveniment
        self.__citestebilfisier()
        StocareBilete.stergere_by_eveniment(self, id_eveniement)
        self.__scriebilfisier()

    def nr_bilete(self):
        # returneaza nr de bilete stocate
        self.__citestebilfisier()
        return StocareBilete.nr_bilete(self)

    def lista_bilete(self):
        # returneaza lista cu biletele stocate
        self.__citestebilfisier()
        return StocareBilete.lista_bilete(self)

    def __len__(self):
        # returneaza lungimea listei biletelor stocate
        return StocareBilete.__len__(self)

    def dictionar_bilete(self):
        # returneaza un dictionar cu biletele stocate
        self.__citestebilfisier()
        return StocareBilete.dictionar_bilete(self)
