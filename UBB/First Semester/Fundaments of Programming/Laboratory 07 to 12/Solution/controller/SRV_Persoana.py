from Persoana import Persoana


class ServicePersoana:
    def __init__(self, rep, val):
        # initializeaza serverul
        # rep- repository unde se stocheaza persoanele
        # val- validator valideaza datele trimise din ui
        self.__rep = rep
        self.__val = val

    def creare_persoana(self, ID_ul, nume, adresa):
        # stocheaza o persoana
        # valideaza datele
        p = Persoana(ID_ul, nume, adresa)
        self.__val.validare(p)
        self.__rep.stocare(p)
        return p

    def afisare_persoane(self):
        # determina nr de persoane stocate
        # returneaza o lista
        return self.__rep.lista_persoane()

    def stergere_persoana(self, ID_ul, srvb):
        # verifica daca persoana exista
        # sterge persoana
        p = Persoana(ID_ul, "default", "default")
        self.__val.validare(p)
        srvb.stergere_bilet_id_persoana(ID_ul)
        self.__rep.stergere(p)
        return p

    def modificare_persoana(self, ID_ul, nume, adresa):
        # verifica daca persoana exista
        # modifica persoana
        p = Persoana(ID_ul, nume, adresa)
        self.__val.validare(p)
        self.__rep.modificare(p)
        return p

    def nr_persoane(self):
        # returneaza un dictionar de persoane
        return len(self.__rep)

    def cauta_persoana_id(self, ID_ul):
        # cauta persoane dupa id intr-o lista
        # returneaza o lista cu persoanele cautate
        rez = []
        p = Persoana(ID_ul, "default", "default")
        self.__val.validare(p)
        l = self.__rep.lista_persoane()
        for persoana in l:
            if persoana.get_personID() == p.get_personID():
                rez.append(persoana)
                break
        return rez[:]

    """
    Complexitatea functiei cauta_persoana_id()  
    Caz favorabil: persoana cautata se afla pe prima pozitie in lista => theta(1)
    Caz defavorabil: persoana cautata se afla pe ultima pozitie in lista => theta(n)
    Caz mediu: persoana cautata se afla aleatoriu in lista => theta(n)
    T(n)=T(n-1)+1
    T(n-1)=T(n-2)+1
    ....
    T(1)=1 => T(n)=theta(n)
    """

    def cauta_persoana_nume(self, nume):
        # cauta persoane dupa nume intr-o lista
        # returneaza o lista cu persoanele cautate
        rez = []
        p = Persoana(1, nume, "default")
        self.__val.validare(p)
        l = self.__rep.lista_persoane()
        for persoana in l:
            if persoana.get_name() == p.get_name():
                rez.append(persoana)
        return rez

    def cauta_persoana_adresa(self, adresa):
        # cauta persoane dupa adresa intr-o lista
        # returneaza o lista cu persoanele cautate
        rez = []
        p = Persoana(1, "default", adresa)
        self.__val.validare(p)
        l = self.__rep.lista_persoane()
        for persoana in l:
            if persoana.get_address() == p.get_address():
                rez.append(persoana)
        return rez
