from Eveniment import Eveniment
from SRV_Bilet import ServiceException


class ServiceEveniment:
    def __init__(self, rep, val):
        # initializeaza serverul
        # rep- repository unde se stocheaza evenimentele
        # val- validator unde se valideaza datele trimise de UI
        self.__rep = rep
        self.__val = val

    def creare_eveniment(self, ID_ul, data, ora, descriere):
        # stocheaza un eveniment
        # valideaza datele
        e = Eveniment(ID_ul, data, ora, descriere)
        self.__val.validare(e)
        self.__rep.stocare(e)
        return e

    def stergere_eveniment(self, ID_ul, srvb):
        # verifica daca evenimentul exista
        # sterge evenimentul
        e = Eveniment(ID_ul, "12/03/2020", "12:30", "default")
        self.__val.validare(e)
        srvb.stergere_bilet_id_eveniment(ID_ul)
        self.__rep.stergere(e)
        return e

    def modificare_eveniment(self, ID_ul, data, ora, descriere):
        # verifica daca evenimentul exista
        # modifica evenimentul
        e = Eveniment(ID_ul, data, ora, descriere)
        self.__val.validare(e)
        self.__rep.modificare(e)
        return e

    def nr_evenimente(self):
        # determina cate evenimente au fost stocate
        # returneaza o lista
        return self.__rep.nr_evenimente()

    def afisare_evenimente(self):
        # returneaza o lista cu evenimente
        return self.__rep.lista_evenimente()

    '''
    def cauta_eveniment_id(self, ID_ul):
        # cauta evenimentele cu id-ul dat intr-o lista
        # returneaza o lista cu evenimentele cautate
        rez = []
        e = Eveniment(ID_ul, "21/03/2020", "23:15", "default")
        self.__val.validare(e)
        l = self.__rep.lista_evenimente()
        for eveniment in l:
            if eveniment.get_ID() == e.get_ID():
                rez.append(eveniment)
        return rez[:]
    '''

    # recursiv
    def cauta_eveniment_id(self, lista, Id_ul, rez):
        # cauta evenimentele cu id-ul dat intr-o lista
        # returneaza o lista cu evenimentele cautate
        e = Eveniment(Id_ul, "21/03/2020", "23:15", "default")
        self.__val.validare(e)
        if not lista:
            raise ServiceException("\n Nu exista evenimente\n")
        if lista[0].get_ID() == e.get_ID():
            rez.append(lista[0])
        if len(lista) == 1:
            return rez
        return self.cauta_eveniment_id(lista[1:], Id_ul, rez)

    '''
    def cauta_eveniment_data(self, data):
        # cauta evenimentele cu data respectiva intr-o lista
        # returneaza o lista cu evenimentele cautate
        rez = []
        e = Eveniment(123, data, "23:15", "default")
        self.__val.validare(e)
        l = self.__rep.lista_evenimente()
        for eveniment in l:
            if eveniment.get_data() == e.get_data():
                rez.append(eveniment)
        return rez
    '''

    # recursiv
    def cauta_eveniment_data(self, lista, data, rez):
        # cauta eveniemntele cu data respectiva intr-o lista
        # returneaza o lista cu evenimentele cautate
        e = Eveniment(123, data, "23:15", "default")
        self.__val.validare(e)
        if not lista:
            raise ServiceException("\n Nu exista evenimente!\n")
        if lista[0].get_data() == e.get_data():
            rez.append(lista[0])
        if len(lista) == 1:
            return rez
        return self.cauta_eveniment_data(lista[1:], data, rez)

    def cauta_eveniment_ora(self, ora):
        # cauta evenimentele cu id-ul dat intr-o lista
        # returneaza o lista cu evenimentele cautate
        rez = []
        e = Eveniment(123, "21/03/2020", ora, "default")
        self.__val.validare(e)
        l = self.__rep.lista_evenimente()
        for eveniment in l:
            if eveniment.get_ora() == e.get_ora():
                rez.append(eveniment)
        return rez

    def cauta_eveniment_descriere(self, descriere):
        # cauta evenimentele cu id-ul dat intr-o lista
        # returneaza o lista cu evenimentele cautate
        rez = []
        e = Eveniment(123, "21/03/2020", "23:15", descriere)
        self.__val.validare(e)
        l = self.__rep.lista_evenimente()
        for eveniment in l:
            if eveniment.get_descriere() == e.get_descriere():
                rez.append(eveniment)
        return rez
