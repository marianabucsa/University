from ListaPersoane import RepositoryException
from SRV_Bilet import ServiceException
from Validatori import ValidatorException
import random


class ConsolaException(Exception):
    def __init__(self, eroare):
        self.__eroare = eroare

    def getEroare(self):
        return self.__eroare


class Comanda:
    def __init__(self, functie, text):
        self.__functie = functie
        self.__text = text

    def executa(self):
        # executa functia corespunzatoare
        self.__functie()

    def get_text(self):
        # returneaza textul functiei
        return self.__text


class Consola:
    def __init__(self, srvp, srve, srvb):
        self.__srvp = srvp
        self.__srve = srve
        self.__srvb = srvb

    def __afiseaza_persoane(self):
        # printeaza persoanele stocate sau daca nu exista printeaza un mesaj
        persoane = self.__srvp.afisare_persoane()
        if len(persoane) == 0:
            print("Nu exista persoane!\n")
        else:
            for p in persoane:
                print("ID: " + str(p.get_personID()) + " Nume: " + str(p.get_name()) + " Adresa: " + str(
                    p.get_address()))

    def __afiseaza_evenimente(self):
        # printeaza evenimentele stocate sau daca nu exista printeaza un mesaj
        evenimente = self.__srve.afisare_evenimente()
        if len(evenimente) == 0:
            print("Nu exista evenimente!\n")
        else:
            for e in evenimente:
                print(
                    "ID: " + str(e.get_ID()) + " Data: " + str(e.get_data()) + " Ora: " + str(
                        e.get_ora()) + " Descriere: " + str(e.get_descriere()))

    def __adauga_persoana(self):
        # citeste ID_ul, nume, adresa de la tastatura
        # printeaza mesaj in caz de exceptie
        try:
            ID_ul = int(input("Dati ID persoana: "))
            nume = input("Dati numele persoanei: ")
            adresa = input("Dati adresa persoanei: ")
            p = self.__srvp.creare_persoana(ID_ul, nume, adresa)
            print("Persoana " + str(p.get_name()) + " a fost adaugat!\n")
        except ValueError:
            print("ID-ul trebuie sa fie nr intreg!\n")
        except RepositoryException as re:
            print(str(re))
        except ValidatorException as ve:
            print(str(ve))

    def __adauga_eveniment(self):
        # citeste ID_ul, data, ora, descriere de la tastatura
        # printeaza mesaj in caz de exceptie
        try:
            ID_ul = int(input("Dati ID eveniment: "))
            data = input("Dati data eveniment: ")
            ora = input("Dati ora eveniment: ")
            descriere = input("Dati descriere eveniment: ")
            e = self.__srve.creare_eveniment(ID_ul, data, ora, descriere)
            print("Evenimentul " + str(e.get_ID()) + " a fost adaugat!\n")
        except ValueError as ve:
            print("Datele introduse sunt incorecte!\n")
        except RepositoryException as re:
            print(str(re))
        except ValidatorException as ve:
            print(str(ve))

    def __stergere_persoana(self):
        # citeste ID_ul de la tastatura
        # printeaza mesaj in caz de exceptie
        try:
            ID_ul = int(input("Dati ID-ul persoanei: "))
            p = self.__srvp.stergere_persoana(ID_ul, self.__srvb)
            print("Persoana cu ID-ul: " + str(p.get_personID()) + " a fost stearsa!\n")
        except RepositoryException as re:
            print(str(re))
        except ValueError:
            print("\nID-ul trebuie sa fie nr intreg!\n")

    def __stergere_eveniment(self):
        # citeste ID_ul de la tastatura
        # printeaza mesaj in caz de exceptie
        try:
            ID_ul = int(input("Dati ID-ul evenimentului: "))
            e = self.__srve.stergere_eveniment(ID_ul, self.__srvb)
            print("Evenimentul cu ID-ul: " + str(e.get_ID()) + " a fost sters!\n")
        except RepositoryException as re:
            print(str(re))
        except ValueError:
            print("\nID-ul trebuie sa fie nr intreg!\n")

    def __modifica_persoana(self):
        # citeste ID_ul, noul nume, noua adresa de la tastatura
        # printeaza mesaj in caz de exceptie
        try:
            ID_ul = int(input("Dati ID-ul persoanei: "))
            nume = input("Dati noul nume: ")
            adresa = input("Dati noua adresa: ")
            p = self.__srvp.modificare_persoana(ID_ul, nume, adresa)
            print("Persoana cu ID-ul " + str(p.get_personID()) + " a fost modificata!\n")
        except RepositoryException as re:
            print(str(re))
        except ValidatorException as ve:
            print(str(ve))
        except ValueError:
            print("\nID-ul trebuie sa fie nr intreg!\n")

    def __modifica_eveniment(self):
        # citeste ID_ul, noua data, noua ora, noua descriere de la tastatura
        # printeaza mesaj in caz de exceptie
        try:
            ID_ul = int(input("Dati ID eveniment: "))
            data = input("Dati noua data: ")
            ora = input("Dati noua ora: ")
            descriere = input("Dati noua descriere: ")
            e = self.__srve.modificare_eveniment(ID_ul, data, ora, descriere)
            print("Evenimentul cu ID-ul: " + str(e.get_ID()) + " a fost modificat!\n")
        except RepositoryException as re:
            print(str(re))
        except ValidatorException as ve:
            print(str(ve))
        except ValueError:
            print("\nID-ul trebuie sa fie nr intreg!\n")

    def __cauta_persoana(self):
        # citeste modul de cautare si informatia cautata
        # afiseaza persoanele cautate
        c = input("Dati modul de cautare(id/nume/adresa): ")
        if (c == "id"):
            try:
                ID_ul = int(input("Dati ID persoana: "))
                l = self.__srvp.cauta_persoana_id(ID_ul)
            except ValueError:
                print("Date invalide!")
            except RepositoryException as re:
                print(str(re))
            except ValidatorException as ve:
                print(str(ve))
        elif (c == "nume"):
            try:
                nume = input("Dati nume persoana: ")
                l = self.__srvp.cauta_persoana_nume(nume)
            except RepositoryException as re:
                print(str(re))
            except ValidatorException as ve:
                print(str(ve))
        elif (c == "adresa"):
            try:
                adresa = input("Dati adresa persoana: ")
                l = self.__srvp.cauta_persoana_adresa(adresa)
            except RepositoryException as re:
                print(str(re))
            except ValidatorException as ve:
                print(str(ve))
        else:
            print("\nModul de cautare este invalid!\n")
            return

        if len(l) == 0:
            print("\nPersoanele cautate nu exista!\n")
        else:
            for p in l:
                print("ID: " + str(p.get_personID()) + " Nume: " + p.get_name() + " Adresa: " + p.get_address())

    def __cauta_eveniment(self):
        # citeste modul de cautare si informatia cautata
        # afiseaza evenimentele cautate
        c = input("Dati modul de cautare(id/data/ora/descriere): ")
        if (c == "id"):
            try:
                ID_ul = int(input("Dati ID eveniment: "))
                l = self.__srve.cauta_eveniment_id(self.__srve.afisare_evenimente(),ID_ul,[])
            except ValueError:
                print("Date invalide!")
            except RepositoryException as re:
                print(str(re))
            except ValidatorException as ve:
                print(str(ve))
        elif (c == "data"):
            try:
                data = input("Dati data eveniment: ")
                l = self.__srve.cauta_eveniment_data(self.__srve.afisare_evenimente(),data,[])
            except RepositoryException as re:
                print(str(re))
            except ValidatorException as ve:
                print(str(ve))
        elif (c == "ora"):
            try:
                ora = input("Dati ora eveniment: ")
                l = self.__srve.cauta_eveniment_ora(ora)
            except RepositoryException as re:
                print(str(re))
            except ValidatorException as ve:
                print(str(ve))
        elif (c == "descriere"):
            try:
                descriere = input("Dati descriere eveniment: ")
                l = self.__srve.cauta_eveniment_descriere(descriere)
            except RepositoryException as re:
                print(str(re))
            except ValidatorException as ve:
                print(str(ve))
        else:
            print("\nModul de cautare este invalid!\n")
            return
        if len(l) == 0:
            print("\nEvenimentele cautate nu exista!\n")
        else:
            for e in l:
                print("ID: " + str(
                    e.get_ID()) + " Data: " + e.get_data() + " Ora: " + e.get_ora() + " Descriere: " + e.get_descriere())

    def __adauga_bilet(self):
        # citeste ID_ul persoanei si ID_ul evenimentului de la tastatura
        # printeaza mesaj in caz de exceptie
        try:
            id_persoana = int(input("Dati ID persoana: "))
            id_eveniment = int(input("Dati ID eveniment: "))
            pret = int(input("Dati pretul biletului: "))
            b = self.__srvb.creare_bilet(id_persoana, id_eveniment, pret)
            print("\nBiletul a fost cumparat!\n")
        except ValueError:
            print("Date invalide!\n")
        except RepositoryException as re:
            print(str(re))
        except ValidatorException as ve:
            print(str(ve))
        except ServiceException as se:
            print(str(se))

    def __sterge_bilet(self):
        # citeste ID_ul persoanei si ID_ul evenimentului de la tastatura
        # printeaza mesaj in caz de exceptie
        try:
            id_persoana = int(input("Dati ID persoana: "))
            id_eveniment = int(input("Dati ID eveniment: "))
            b = self.__srvb.stergere_bilet(id_persoana, id_eveniment)
            print("Biletul a fost sters!\n")
        except ValueError:
            print("ID-ul trebuie sa fie nr intreg!\n")
        except RepositoryException as re:
            print(str(re))
        except ValidatorException as ve:
            print(str(ve))
        except ServiceException as se:
            print(str(se))

    def __modifica_bilet(self):
        # citeste ID_ul persoanei si ID_ul evenimentului de la tastatura
        # printeaza mesaj in caz de exceptie
        try:
            id_persoana = int(input("Dati ID persoana: "))
            id_eveniment = int(input("Dati ID eveniment: "))
            nou_persoana = int(input("Dati ID-ul persoanei noi: "))
            nou_eveniment = int(input("Dati ID-ul evenimentului nou: "))
            nou_pret = int(input("Dati pretul biletului: "))
            b = self.__srvb.modificare_bilet(id_persoana, id_eveniment, nou_persoana, nou_eveniment, nou_pret)
            print("\nBiletul a fost modificat!\n")
        except RepositoryException as re:
            print(str(re))
        except ValidatorException as ve:
            print(str(ve))
        except ValueError:
            print("\nID-ul trebuie sa fie nr intreg!\n")
        except ServiceException as se:
            print(str(se))

    def __afiseaza_bilete(self):
        # printeaza biletele stocate sau daca nu exista printeaza un mesaj
        bilete = self.__srvb.afisare_bilete()
        if len(bilete) == 0:
            print("Nu exista bilete!\n")
        else:
            for b in bilete:
                p = self.__srvp.cauta_persoana_id(b.get_id_persoana())[0]
                e = self.__srve.cauta_eveniment_id(b.get_id_eveniment())[0]
                print("BILET: ")
                print("ID persoana: " + str(
                    p.get_personID()) + "   Nume: " + p.get_name() + "  Adresa: " + p.get_address())
                print("ID eveniment: " + str(
                    e.get_ID()) + "  Data: " + e.get_data() + "  Ora: " + e.get_ora() + "  Descriere: " + e.get_descriere())
                print("Pretul : " + str(b.get_pret()) + "\n")

    def __genereaza_persoane(self):
        # genereaza un nr de persoane
        names = ["Ion", "Ana", "Mara", "Ghita", "Vasile"]
        adrese = ["strada Morarului", "strada 21 Decembrie"]
        try:
            nr = int(input("Dati nr de persoane: "))
            if nr <= 0:
                raise ValidatorException("Nr nu poate fi negativ!\n")
            while nr:
                l = self.__srvp.afisare_persoane()
                bun = 1
                ID_ul = random.randint(1, 100)
                for p in l:
                    if p.get_personID() == ID_ul:
                        bun = 0
                if bun == 1:
                    nume = random.choice(names)
                    adresa = random.choice(adrese)
                    self.__srvp.creare_persoana(ID_ul, nume, adresa)
                    nr = nr - 1
            print("Persoanele au fost adaugate!\n")
        except RepositoryException as re:
            print(str(re))
        except ValidatorException as ve:
            print(str(ve))
        except ValueError:
            print("\nID-ul trebuie sa fie nr intreg!\n")

    def __genereaza_evenimente(self):
        # genereaza un nr de persoane
        dates = ["31/07/2020", "20/03/2000", "12/04/2010", "17/11/2020", "3/04/2012"]
        ore = ["20:30", "12:30", "14:40", "10:20", "13:10"]
        descrieri = ["concert", "targ de carte", "film", "club de carte"]
        try:
            nr = int(input("Dati nr de evenimente: "))
            if nr <= 0:
                raise ValidatorException("Nr nu poate fi negativ!\n")
            while nr:
                l = self.__srve.afisare_evenimente()
                bun = 1
                ID_ul = random.randint(1, 100)
                for e in l:
                    if e.get_ID() == ID_ul:
                        bun = 0
                if bun == 1:
                    data = random.choice(dates)
                    ora = random.choice(ore)
                    descriere = random.choice(descrieri)
                    self.__srve.creare_eveniment(ID_ul, data, ora, descriere)
                    nr = nr - 1
            print("Evenimentele au fost adaugate!\n")
        except RepositoryException as re:
            print(str(re))
        except ValidatorException as ve:
            print(str(ve))
        except ValueError:
            print("\nID-ul trebuie sa fie nr intreg!\n")

    def __afisare_evenimente_persoana(self):
        try:
            ID_ul = int(input("Dati id-ul persoanei: "))
            mod = input("Dati modul(data/descriere): ")
            dic = {}
            if (mod == "data"):
                dic = self.__srvb.afiseaza_evenimente_persoana_data(ID_ul)
            elif (mod == "descriere"):
                dic = self.__srvb.afiseaza_evenimente_persoana_descriere(ID_ul)
            else:
                print("Modul introdus invalid!")
            for key in dic:
                print(
                    "ID: " + str(key.get_ID()) + " Data: " + str(key.get_data()) + " Ora: " + str(
                        key.get_ora()) + " Descriere: " + str(key.get_descriere()))
        except ValueError:
            print("Date invalide!")
        except RepositoryException as re:
            print(str(re))
        except ValidatorException as ve:
            print(str(ve))
        except ServiceException as se:
            print(str(se))

    def __afiseaza_persoane_cu_maxim_evenimente(self):
        try:
            dic = self.__srvb.cele_mai_multe_evenimente()
            for key in dic:
                p = self.__srvp.cauta_persoana_id(dic[key].get_id_persoana())[0]
                print("ID: " + str(
                    p.get_personID()) + " Nume: " + p.get_name() + " Adresa: " + p.get_address() + " Nr de evenimente: " + str(
                    dic[key].get_nr_evenimente()) + "\n")
        except ServiceException as se:
            print(str(se))
        except RepositoryException as re:
            print(str(re))
        except ConsolaException as ce:
            print(str(ce))

    def __afisare_20_evenimente(self):
        try:
            lista = self.__srvb.afiseaza_20_evenimente()
            for ele in lista:
                e = self.__srve.cauta_eveniment_id(ele.get_id_eveniment())[0]
                print("Descriere: " + e.get_descriere() + " Nr participanti: " + str(ele.get_nr_persoane()))
        except ServiceException as se:
            print(str(se))
        except RepositoryException as re:
            print(str(re))
        except ConsolaException as ce:
            print(str(ce))

    def __afiseaza_persoane_zi(self):
        try:
            data = input("Dati o data: ")
            lista = self.__srvb.afiseaza_persoane_zi(data)
            for ele in lista:
                p = self.__srvp.cauta_persoana_id(ele.get_id_persoana())[0]
                print("ID: "+str(p.get_personID())+" Nume: "+p.get_name()+" Adresa: "+p.get_address()+" Nr evenimente: "+str(ele.get_nr_evenimente()))
        except RepositoryException as re:
            print(str(re))
        except ValidatorException as ve:
            print(str(ve))
        except ValueError:
            print("\nDate invalide!\n")
        except ConsolaException as ce:
            print(str(ce))
        except ServiceException as se:
            print(str(se))

    def __afisare_meniu(self, comenzi):
        # se afiseaza meniul
        # date de intrare: comenzi- dictionar
        # date de iesire: tipareste pe ecran
        print("\nWelcome\n")
        print("Comenzi:\n")
        print("---------------------------------------------------------------------")
        for i in comenzi:
            print(comenzi[i].get_text())
        print("---------------------------------------------------------------------")

    def __citire_comanda(self, ):
        # verifica daca comanda citita este un nr intreg
        # date de intrare: -
        # date de iesire: x- intreg
        try:
            x = int(input("Introduceti comanda: "))
            return x
        except ValueError:
            print("\nValoare intreaga nevalida!\n")

    def meniu(self):
        # se defineste meniul: se apeleaza comanda corespunzatoare
        # date de intrare:-
        # date de iesire:-

        comenzi = {1: Comanda(self.__adauga_persoana,
                              "| 1.Adauga persoana.                                                |"),
                   2: Comanda(self.__adauga_eveniment,
                              "| 2.Adauga eveniment.                                               |"),
                   3: Comanda(self.__stergere_persoana,
                              "| 3.Stergere persoana.                                              |"),
                   4: Comanda(self.__stergere_eveniment,
                              "| 4.Stergere eveniment.                                             |"),
                   5: Comanda(self.__modifica_persoana,
                              "| 5.Modifica persoana.                                              |"),
                   6: Comanda(self.__modifica_eveniment,
                              "| 6.Modifica eveniment.                                             |"),
                   7: Comanda(self.__afiseaza_persoane,
                              "| 7.Afiseaza persoane.                                              |"),
                   8: Comanda(self.__afiseaza_evenimente,
                              "| 8.Afiseaza evenimente.                                            |"),
                   9: Comanda(self.__cauta_persoana,
                              "| 9.Cauta persoane.                                                 |"),
                   10: Comanda(self.__cauta_eveniment,
                               "| 10.Cauta eveniment.                                               |"),
                   11: Comanda(self.__adauga_bilet,
                               "| 11.Adauga bilet.                                                  |"),
                   12: Comanda(self.__sterge_bilet,
                               "| 12.Sterge bilet.                                                  |"),
                   13: Comanda(self.__modifica_bilet,
                               "| 13.Modifica bilet.                                                |"),
                   14: Comanda(self.__afiseaza_bilete,
                               "| 14.Afiseaza bilete.                                               |"),
                   15: Comanda(self.__genereaza_persoane,
                               "| 15.Genereaza persoane.                                            |"),
                   16: Comanda(self.__genereaza_evenimente,
                               "| 16.Genereaza evenimente.                                          |"),
                   17: Comanda(self.__afisare_evenimente_persoana,
                               "| 17.Afiseaza evenimentele ordonate ale unei persoane.              |"),
                   18: Comanda(self.__afiseaza_persoane_cu_maxim_evenimente,
                               "| 18.Afiseaza persoane care participa la cele mai multe evenimente. |"),
                   19: Comanda(self.__afisare_20_evenimente,
                               "| 19.Afiseaza 20% dintre evenimentele cu cei mai multi participanti.|"),
                   20: Comanda(self.__afiseaza_persoane_zi,
                               "| 20.Afiseaza persoanele participante la evenimente intr-o zi.      |")
                   }
        while True:
            self.__afisare_meniu(comenzi)
            cmd = self.__citire_comanda()
            if cmd in comenzi:
                try:
                    comenzi[cmd].executa()
                except RepositoryException as re:
                    print(str(re))
                except ValidatorException as ve:
                    print(str(ve))
            else:
                print("\nComanda invalida!\n")
