class Comanda:
    def __init__(self, functie, text):
        self.__functie = functie
        self.__text = text

    def executa(self):
        # executes the command's function
        self.__functie()

    def get_text(self):
        # returns the command's text
        return self.__text


class Consola:
    def __init__(self, srv):
        self.__srv = srv

    def __c_impartiri_succesive(self):
        # function for command 1
        # reads data and prints the result
        try:
            b1 = int(input("Dati baza numarului: "))
            nr = input("Dati numarul: ")
            b2 = int(input("Dati baza in care se reprezinta: "))
            nr = nr.upper()
            rez = self.__srv.c_impartiri_succesive(b1, nr, b2)
            print("Rezultatul in baza " + str(b2) + ": " + str(rez))
        except ValueError:
            print("\nValoare invalida!\n")

    def __c_substitutie(self):
        # function for command 2
        # reads data and prints the result
        try:
            b1 = int(input("Dati baza numarului: "))
            nr = input("Dati numarul: ")
            b2 = int(input("Dati baza in care se reprezinta: "))
            nr = nr.upper()
            rez = self.__srv.c_substitutie(b1, nr, b2)
            print("Rezultatul in baza " + str(b2) + ": " + str(rez))
        except ValueError:
            print("\nValoare invalida!\n")

    def __c_baza_intermediara(self):
        # function for command 3
        # reads data and prints the result
        try:
            b1 = int(input("Dati baza numarului: "))
            nr = input("Dati numarul: ")
            b2 = int(input("Dati baza in care se reprezinta: "))
            nr = nr.upper()
            rez = self.__srv.c_baza_intermediara(b1, nr, b2)
            print("Rezultatul in baza " + str(b2) + ": " + str(rez))
        except ValueError:
            print("\nValoare invalida!\n")

    def __c_rapida(self):
        # function for command 4
        # reads data and prints the result
        try:
            b1 = int(input("Dati baza numarului: "))
            nr = input("Dati numarul: ")
            b2 = int(input("Dati baza in care se reprezinta: "))
            nr = nr.upper()
            if b1 == 2:
                rez = self.__srv.c_din_baza_2(nr, b2)
            else:
                if b2 == 2:
                    rez = self.__srv.c_in_baza_2(nr, b1)
            print("Rezultatul in baza " + str(b2) + ": " + str(rez))
        except ValueError:
            print("\nValoare invalida!\n")

    def __adunare(self):
        # function for command 5
        # reads data and prints the result
        try:
            b1 = int(input("Dati baza primului numar: "))
            nr1 = input("Dati primul numar: ")
            b2 = int(input("Dati baza celui de-al doilea numar: "))
            nr2 = input("Dati al doilea numarul: ")
            b = int(input("Dati baza in care se reprezinta rezultatul: "))
            nr1 = nr1.upper()
            nr2 = nr2.upper()
            rez = self.__srv.adunare(nr1, b1, nr2, b2, b)
            print("Rezultatul in baza " + str(b) + ": " + str(rez))
        except ValueError:
            print("\nValoare invalida!\n")

    def __scadere(self):
        # function for command 6
        # reads data and prints the result
        try:
            b1 = int(input("Dati baza primului numar: "))
            nr1 = input("Dati primul numar: ")
            b2 = int(input("Dati baza celui de-al doilea numar: "))
            nr2 = input("Dati al doilea numarul: ")
            b = int(input("Dati baza in care se reprezinta rezultatul: "))
            nr1 = nr1.upper()
            nr2 = nr2.upper()
            rez = self.__srv.scadere(nr1, b1, nr2, b2, b)
            print("Rezultatul in baza " + str(b) + ": " + str(rez))
        except ValueError:
            print("\nValoare invalida!\n")

    def __inmultirea_cu_o_cifra(self):
        # function for command 7
        # reads data and prints the result
        try:
            b = int(input("Dati baza numarului: "))
            nr = input("Dati numarul: ")
            c = int(input("Dati cifra: "))
            rez = self.__srv.inmultire_cu_o_cifra(nr, c, b)
            nr = nr.upper()
            print("Rezultatul in baza " + str(b) + ": " + rez)
        except ValueError:
            print("\nValoare invalida!\n")

    def __impartirea_cu_o_cifra(self):
        # function for command 8
        # reads data and prints the result
        try:
            b = int(input("Dati baza numarului: "))
            nr = input("Dati numarul: ")
            c = int(input("Dati cifra: "))
            nr = nr.upper()
            rez = self.__srv.impartire_cu_o_cifra(nr, c, b)
            print("Rezultatul in baza " + str(b) + ": " + rez)
        except ValueError:
            print("\nValoare invalida!\n")

    def __afisare_meniu(self, comenzi):
        # prints menu
        print("-------------------------------------------------")
        print("|                    Meniu                      |")
        print("-------------------------------------------------")
        for c in comenzi:
            print(comenzi[c].get_text())
        print("-------------------------------------------------")

    def __citire_comanda(self):
        # reads a command
        try:
            c = int(input("Introduceti comanda: "))
            return c
        except ValueError:
            print("Valoare invalida!\n")

    def meniu(self):
        # application launch
        print("Aplicatie creata de Bucsa Mariana Domnica")
        comenzi = {1: Comanda(self.__c_impartiri_succesive, "| 1.Conversie prin impartiri succesive.         |"),
                   2: Comanda(self.__c_substitutie, "| 2.Conversie prin substitutie.                 |"),
                   3: Comanda(self.__c_baza_intermediara, "| 3.Conversie prin baza intermediara.           |"),
                   4: Comanda(self.__c_rapida, "| 4.Conversie rapida intre doua baze(2,4,8,16). |"),
                   5: Comanda(self.__adunare, "| 5.Adunare intr-o baza oarecare.               |"),
                   6: Comanda(self.__scadere, "| 6.Scaderea intr-o baza oarecare.              |"),
                   7: Comanda(self.__inmultirea_cu_o_cifra, "| 7.Inmultirea cu o cifra intr-o baza oarecare. |"),
                   8: Comanda(self.__impartirea_cu_o_cifra, "| 8.Impartirea cu o cifra intr-o baza oarecare. |")}
        while True:
            self.__afisare_meniu(comenzi)
            c = self.__citire_comanda()
            if c in comenzi:
                comenzi[c].executa()
            else:
                print("Comanda nu exista!\n")
