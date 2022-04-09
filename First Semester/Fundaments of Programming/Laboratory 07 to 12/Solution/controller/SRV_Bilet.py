from Bilet import Bilet, BiletperDTO, BileteveDTO
from Eveniment import Eveniment
import datetime

from Validatori import ValidatorEveniment
from sortari.Sortari import *


class ServiceException(Exception):
    def __init__(self, eroare):
        self.__eroare = eroare

    def getEroare(self):
        return self.__eroare


class ServiceBilet():
    def __init__(self, rep, val, srvp, srve):
        # initializeaza serverul
        # rep- repository unde se stocheaza biletele
        # val- validator unde se valideaza datele trimise de UI
        self.__rep = rep
        self.__val = val
        self.__srvp = srvp
        self.__srve = srve

    def creare_bilet(self, id_persoana, id_eveniment, pret):
        # stocheaza un bilet
        # valideaza datele
        l1 = self.__srvp.cauta_persoana_id(id_persoana)
        if not l1:
            raise ServiceException("\nPersoana nu exista!\n")
        l2 = self.__srve.cauta_eveniment_id(id_eveniment)
        if not l2:
            raise ServiceException("\nEvenimentul nu exista!\n")
        b = Bilet(id_persoana, id_eveniment, pret)
        self.__val.validare(b)
        self.__rep.stocare(b)
        return b

    def stergere_bilet(self, id_persoana, id_eveniment):
        # sterge un bilet
        # valideaza datele
        l1 = self.__srvp.cauta_persoana_id(id_persoana)
        if not l1:
            raise ServiceException("\nPersoana nu exista!\n")
        l2 = self.__srve.cauta_eveniment_id(id_eveniment)
        if not l2:
            raise ServiceException("\nEvenimentul nu exista!\n")
        b = Bilet(id_persoana, id_eveniment, 10)
        self.__val.validare(b)
        self.__rep.stergere(b)
        return b

    def stergere_bilet_id_persoana(self, id_persoana):
        # sterge un bilet in cazul in care se sterge o persoana
        self.__rep.stergere_by_persoana(id_persoana)

    def stergere_bilet_id_eveniment(self, id_eveniment):
        # sterge un bilet in cazul in care se sterge un eveniment
        self.__rep.stergere_by_eveniment(id_eveniment)

    def modificare_bilet(self, id_persoana, id_eveniment, nou_persoana, nou_eveniment, nou_pret):
        # modifica un bilet
        # valideaza datele
        l1 = self.__srvp.cauta_persoana_id(id_persoana)
        if not l1:
            raise ServiceException("\nPersoana nu exista!\n")
        l2 = self.__srve.cauta_eveniment_id(id_eveniment)
        if not l2:
            raise ServiceException("\nEvenimentul nu exista!\n")
        l3 = self.__srvp.cauta_persoana_id(nou_persoana)
        if not l3:
            raise ServiceException("\nPersoana nu exista!\n")
        l4 = self.__srve.cauta_eveniment_id(nou_eveniment)
        if not l4:
            raise ServiceException("\nEvenimentul nu exista!\n")
        b1 = Bilet(id_persoana, id_eveniment, 10)
        b2 = Bilet(nou_persoana, nou_eveniment, nou_pret)
        self.__val.validare(b1)
        self.__val.validare(b2)
        self.__rep.modificare(b1, b2)
        return b2

    def nr_bilete(self):
        # returneaza un intreg
        return len(self.__rep)

    def afisare_bilete(self):
        # returneaza o lista de evenimente
        return self.__rep.lista_bilete()

    def afiseaza_evenimente_persoana_data(self, ID_ul):
        # returneaza o lista cu evenimentele la care participa o persoana
        l = self.__rep.lista_bilete()
        l1 = self.__srvp.cauta_persoana_id(ID_ul)
        if not l1:
            raise ServiceException("\nPersoana nu exista!\n")
        lista = []
        for b in l:
            if b.get_id_persoana() == ID_ul:
                lista.append(self.__srve.cauta_eveniment_id(self.__srve.afisare_evenimente(), b.get_id_eveniment(),
                             [])[0])
        if not lista:
            raise ServiceException("\nPersoana nu are bilete cumparate!\n")
        # lista.sort(key=lambda x: datetime.datetime.strptime(x.get_data(), '%d/%m/%Y'))
        rez = selection_sort_2keys(lista, Eveniment.get_data_lista, Eveniment.get_descriere)
        return rez

    def afiseaza_evenimente_persoana_descriere(self, ID_ul):
        # returneaza o lista cu evenimentele la care participa o persoana
        l = self.__rep.lista_bilete()
        l1 = self.__srvp.cauta_persoana_id(ID_ul)
        if not l1:
            raise ServiceException("\nPersoana nu exista!\n")
        lista = []
        for b in l:
            if b.get_id_persoana() == ID_ul:
                lista.append(self.__srve.cauta_eveniment_id(self.__srve.afisare_evenimente(), b.get_id_eveniment(),
                             [])[0])
        if not lista:
            raise ServiceException("\nPersoana nu are bilete cumparate!\n")
        # lista.sort(key=lambda x: x.get_descriere())
        rez = selection_sort(lista, Eveniment.get_descriere)
        return rez

    def cele_mai_multe_evenimente(self):
        # returneaza un dictionar de obiecte de tip DTO
        lista = self.__rep.lista_bilete()
        if not lista:
            raise ServiceException("\nNu exista bilete!\n")
        codper_nreve = {}
        for bilet in lista:
            codper = bilet.get_id_persoana()
            if codper in codper_nreve:
                codper_nreve[codper].incEv()
            else:
                codper_nreve[codper] = BiletperDTO(codper, 1)
        nr_max = 0
        for key in codper_nreve:
            if codper_nreve[key].get_nr_evenimente() > nr_max:
                nr_max = codper_nreve[key].get_nr_evenimente()
        remove = {}
        for key in codper_nreve:
            if codper_nreve[key].get_nr_evenimente() != nr_max:
                remove[key] = codper_nreve[key]
        for key in remove:
            codper_nreve.pop(key, None)
        return codper_nreve

    def afiseaza_20_evenimente(self):
        # returneaza un dictionar de obiecte de tip DTO
        lista = self.__rep.lista_bilete()
        if not lista:
            raise ServiceException("\nNu exista bilete!\n")
        codeve_nrper = {}
        for bilet in lista:
            codeve = bilet.get_id_eveniment()
            if codeve in codeve_nrper:
                codeve_nrper[codeve].incPer()
            else:
                codeve_nrper[codeve] = BileteveDTO(codeve, 1)
        rez = list(codeve_nrper.values())
        # rez.sort(key=lambda x: x.get_nr_persoane(), reverse=True)
        lista = selection_sort(rez, BileteveDTO.get_nr_persoane, reversed=True)
        l = self.__srve.nr_evenimente()
        nr = round(0.2 * l)
        lista = lista[:nr]
        return lista

    def afiseaza_persoane_zi(self, data):
        e = Eveniment(1200, data, "20:20", "concert")
        v = ValidatorEveniment()
        v.validare(e)
        lista = self.__rep.lista_bilete()
        if not lista:
            raise ServiceException("\nNu exista bilete!\n")
        idper_nreve = {}
        for bilet in lista:
            idper = bilet.get_id_persoana()
            if idper in idper_nreve:
                idper_nreve[idper].incEv()
            else:
                e = self.__srve.cauta_eveniment_id(self.__srve.afisare_evenimente(), b.get_id_eveniment(),
                             [])[0]
                d = e.get_data()
                if d == data:
                    idper_nreve[idper] = BiletperDTO(idper, 1)
        rez = list(idper_nreve.values())
        # rez.sort(key=lambda x: x.get_nr_evenimente(), reverse=True)
        lista = shake_sort(rez, BiletperDTO.get_nr_evenimente, reversed=True)
        return lista
