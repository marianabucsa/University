from ListaPersoane import RepositoryException
from domain.Eveniment import Eveniment


class StocareEvenimente():
    def __init__(self):
        # defineste obiectul StocareEvenimente
        # evenimente- un dictionar
        self._evenimente = {}

    def __len__(self):
        return len(self._evenimente)

    def stocare(self, eveniment):
        # stocheaza un eveniment
        # eveniment e un obiect de tip eveniment
        # arunca exceptie daca mai exista un eveniment cu acelasi ID
        if eveniment.get_ID() in self._evenimente:
            raise RepositoryException("\nID eveniment deja existent!\n")
        self._evenimente[eveniment.get_ID()] = eveniment

    def stergere(self, eveniment):
        # sterge un eveniment
        # eveniment este un obiect de tip eveniment
        # arunca o exceptie daca evenimentul nu exista
        if eveniment.get_ID() not in self._evenimente:
            raise RepositoryException("\nEvenimetul nu exista!\n")
        key = eveniment.get_ID()
        self._evenimente.pop(key)

    def modificare(self, eveniment):
        # modifica un eveniment
        # eveniment este un obiect de tip eveniment
        # arunca o exceptie daca evenimentul nu exista
        if eveniment.get_ID() not in self._evenimente:
            raise RepositoryException("\nEvenimentul nu exista!\n")
        self._evenimente[eveniment.get_ID()].set_data(eveniment.get_data())
        self._evenimente[eveniment.get_ID()].set_ora(eveniment.get_ora())
        self._evenimente[eveniment.get_ID()].set_descriere(eveniment.get_descriere())

    def nr_evenimente(self):
        # determina cate evenimente sunt stocate
        # returneaza un nr intreg
        return len(self._evenimente)

    def lista_evenimente(self):
        # returneaza o lista cu toate evenimentele stocate
        return list(self._evenimente.values())[:]


class FileStocareEvenimente(StocareEvenimente):
    def __init__(self, numef):
        self.__citesteefisier = Eveniment.citesteDinFisier
        self.__scrieefisier = Eveniment.scrieInFisier
        self.__numef = numef
        StocareEvenimente.__init__(self)
        self.__citesteevefisier()
        self.__scrieevefisier()

    def __citesteevefisier(self):
        # citeste evenimentele din fisier
        with open(self.__numef, 'r') as fisier:
            eve = {}
            for line in fisier.readlines():
                line = line.strip()
                if len(line) > 0:
                    e = self.__citesteefisier(line)
                    eve[e.get_ID()] = e
            self._evenimente = eve.copy()

    def __scrieevefisier(self):
        # scrie evenimentele in fisier
        with open(self.__numef, 'w') as fisier:
            for key in self._evenimente:
                line = self.__scrieefisier(self._evenimente[key])
                fisier.write(line + '\n')

    def __adaugaevefisier(self, eveniment):
        # adauga un eveniment intr-un fisier
        with open(self.__numef, 'a') as fisier:
            line = self.__scrieefisier(eveniment)
            fisier.write(line + '\n')

    def stocare(self, eveniment):
        # salveaza un eveniment
        self.__citesteevefisier()
        StocareEvenimente.stocare(self, eveniment)
        self.__adaugaevefisier(eveniment)

    def modificare(self, eveniment):
        # modifica un eveniment
        self.__citesteevefisier()
        StocareEvenimente.modificare(self, eveniment)
        self.__scrieevefisier()

    def stergere(self, eveniment):
        # sterge un eveniment
        self.__citesteevefisier()
        StocareEvenimente.stergere(self, eveniment)
        self.__scrieevefisier()

    def nr_evenimente(self):
        # returneaza numarul de evenimente salvate
        self.__citesteevefisier()
        return StocareEvenimente.nr_evenimente(self)

    def __len__(self):
        return StocareEvenimente.__len__(self)

    def lista_evenimente(self):
        # returneaza lista evenimentelor salvate
        self.__citesteevefisier()
        return StocareEvenimente.lista_evenimente(self)
