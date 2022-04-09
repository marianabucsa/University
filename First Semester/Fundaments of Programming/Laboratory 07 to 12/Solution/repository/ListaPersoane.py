from domain.Persoana import Persoana


class RepositoryException(Exception):
    def __init__(self, eroare):
        self.__eroare = eroare

    def getEroare(self):
        return self.__eroare


class StocarePersoane:
    def __init__(self):
        # defineste obiectul StocarePersoane
        # persoane- un dictionar
        self._persoane = {}

    def __len__(self):
        return len(self._persoane)

    def stocare(self, persoana):
        # stocheaza persoane
        # persoana este un obiect de tip persoana
        # arunce exceptie daca exista o persoana cu acelasi ID

        if persoana.get_personID() in self._persoane:
            raise RepositoryException("\nID persoana deja existent!\n")
        self._persoane[persoana.get_personID()] = persoana

    def stergere(self, persoana):
        # sterge o persoana
        # persoana este un obiect de tip persoana
        # arunca o exceptie daca persoana nu exista
        if persoana.get_personID() not in self._persoane:
            raise RepositoryException("\nPersoana nu exista!\n")
        key = persoana.get_personID()
        self._persoane.pop(key)

    def modificare(self, persoana):
        # modifica o persoana
        # persoana este un obiect de tip persoana
        # arunca o exceptie daca persoana nu exista
        if persoana.get_personID() not in self._persoane:
            raise RepositoryException("\nPersoana nu exista!\n")
        self._persoane[persoana.get_personID()].set_name(persoana.get_name())
        self._persoane[persoana.get_personID()].set_address(persoana.get_address())

    def nr_persoane(self):
        # determina cate persoane sunt stocate
        # returneaza un nr intreg
        return len(self._persoane)

    def lista_persoane(self):
        # returneaza o lista cu toate persoanele stocate
        return list(self._persoane.values())[:]


class FilePersoane():
    def __init__(self, numef):
        self.__numef = numef
        self.__citestepfisier = Persoana.citesteDinFisier
        self.__scriepfisier = Persoana.scrieInFisier
        self.__persoane = {}

    def __citesteperfisier(self):
        # citeste persoanele din fisier
        with open(self.__numef, "r") as fisier:
            per = {}
            for line in fisier.readlines():
                line = line.strip()
                if len(line) > 0:
                    p = self.__citestepfisier(line)
                    per[p.get_personID()] = p
            self.__persoane = per.copy()

    def __adaugaperfisier(self, persoana):
        # adauga o persoana in fisier
        with open(self.__numef, "a") as fisier:
            line = self.__scriepfisier(persoana)
            fisier.write(line + '\n')

    def __cautaperfisier(self, persoana):
        # cauta o persoana in fisier
        with open(self.__numef, "r") as fisier:
            line = fisier.readline()
            while line != '':
                line = line.strip()
                if len(line) > 0:
                    p = self.__citestepfisier(line)
                    if persoana.get_personID() == p.get_personID():
                        return 1
                line = fisier.readline()
            return 0

    def __stergeperfisier(self, persoana):
        # sterge o persoana din fisier
        with open(self.__numef, "r") as fisier:
            with open("copiefisier.txt", "a")as f:
                line = fisier.readline()
                while line != '':
                    line = line.strip()
                    if len(line) > 0:
                        p = self.__citestepfisier(line)
                        if persoana.get_personID() != p.get_personID():
                            line = self.__scriepfisier(p)
                            f.write(line + "\n")
                    line = fisier.readline()
        with open("copiefisier.txt", "r")as f:
            with open(self.__numef, "w") as fisier:
                line = f.readline()
                while line != '':
                    fisier.write(line + '\n')
                    line = f.readline()
        open('copiefisier.txt', 'w').close()

    def __modificaperfisier(self, persoana):
        # modifica o persoana din fisier
        with open(self.__numef, "r") as fisier:
            with open("copiefisier.txt", "a")as f:
                line = fisier.readline()
                while line != '':
                    line = line.strip()
                    if len(line) > 0:
                        p = self.__citestepfisier(line)
                        if persoana.get_personID() != p.get_personID():
                            line = self.__scriepfisier(p)
                            f.write(line + "\n")
                        else:
                            line = self.__scriepfisier(persoana)
                            f.write(line + "\n")
                    line = fisier.readline()
        with open("copiefisier.txt", "r")as f:
            with open(self.__numef, "w") as fisier:
                line = f.readline()
                while line != '':
                    fisier.write(line + '\n')
                    line = f.readline()
        open('copiefisier.txt', 'w').close()

    def stocare(self, persoana):
        # stocheaza o persoana in fisier
        if self.__cautaperfisier(persoana) == 1:
            raise RepositoryException("\nID persoana deja existent!\n")
        self.__adaugaperfisier(persoana)

    def modificare(self, persoana):
        # modifica o persoana din fisier
        if self.__cautaperfisier(persoana) == 0:
            raise RepositoryException("\nPersoana nu exista!\n")
        self.__modificaperfisier(persoana)

    def stergere(self, persoana):
        # sterge o persoana din fisier
        if self.__cautaperfisier(persoana) == 0:
            raise RepositoryException("\nPersoana nu exista!\n")
        self.__stergeperfisier(persoana)

    def lista_persoane(self):
        # returneaza lista cu persoanele din fisier
        self.__citesteperfisier()
        return list(self.__persoane.values())[:]

    def nr_persoane(self):
        # returneaza numarul de persoane din fisier
        self.__citesteperfisier()
        return len(self.__persoane)

    def __len__(self):
        return len(self.__persoane)


class FileStocarePersoane(StocarePersoane):
    def __init__(self, numef):
        self.__citestepfisier = Persoana.citesteDinFisier
        self.__scriepfisier = Persoana.scrieInFisier
        StocarePersoane.__init__(self)
        self.__numef = numef
        self.__citesteperfisier()
        self.__scrieperfisier()

    def __citesteperfisier(self):
        # citeste persoanele din fisier
        with open(self.__numef, "r") as fisier:
            per = {}
            for line in fisier.readlines():
                line = line.strip()
                if len(line) > 0:
                    p = self.__citestepfisier(line)
                    per[p.get_personID()] = p
            self._persoane = per.copy()

    def __scrieperfisier(self):
        # scrie persoanele in fisier
        with open(self.__numef, "w") as fisier:
            for key in self._persoane:
                line = self.__scriepfisier(self._persoane[key])
                fisier.write(line + '\n')

    def __adaugaperfisier(self, persoana):
        # adauga o persoana in fisier
        with open(self.__numef, "a") as fisier:
            line = self.__scriepfisier(persoana)
            fisier.write(line + '\n')

    def stocare(self, persoana):
        # stocheaza o persoana in fisier
        self.__citesteperfisier()
        StocarePersoane.stocare(self, persoana)
        self.__adaugaperfisier(persoana)

    def modificare(self, persoana):
        # modifica o persoana din fisier
        self.__citesteperfisier()
        StocarePersoane.modificare(self, persoana)
        self.__scrieperfisier()

    def stergere(self, persoana):
        # sterge o persoana din fisier
        self.__citesteperfisier()
        StocarePersoane.stergere(self, persoana)
        self.__scrieperfisier()

    def nr_persoane(self):
        # returneaza nr de persoane din fisier
        self.__citesteperfisier()
        return StocarePersoane.nr_persoane(self)

    def __len__(self):
        return StocarePersoane.__len__(self)

    def lista_persoane(self):
        # returneaza lista de persoane din fisier
        self.__citesteperfisier()
        return StocarePersoane.lista_persoane(self)
