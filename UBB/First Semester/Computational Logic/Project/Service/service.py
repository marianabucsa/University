import math
import textwrap as tw
import unittest


class Service:
    def __init__(self):
        self.__digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVXZ"
        self.__to_base_4 = {"00": "0", "01": "1", "10": "2", "11": "3"}
        self.__to_base_8 = {"000": "0", "001": "1", "010": "2", "011": "3", "100": "4", "101": "5", "110": "6",
                            "111": "7"}
        self.__to_base_16 = {"0000": "0", "0001": "1", "0010": "2", "0011": "3", "0100": "4", "0101": "5", "0110": "6",
                             "0111": "7", "1000": "8", "1001": "9", "1010": "A", "1011": "B", "1100": "C", "1101": "D",
                             "1110": "E", "1111": "F"}

    def __convert_inbaza10(self, nr, baza):
        # input: nr- a string that represents a number
        #        baza- an integer that represents the base in which the number is represented
        # output: result- a string that represents the conversion in base 10 of the number
        result = 0
        for i, n in enumerate(nr[::-1]):
            result += self.__digits.find(n) * baza ** i
        return str(result)

    def __convert_dinbaza10(self, nr, baza):
        # input: nr- a string that represents a number
        #        baza- an integer that represents the base in which the number will be converted
        # output: rez- a string that represents the conversion in that base of the number
        rez = ""
        nr = int(nr)
        while nr:
            rez += self.__digits[nr % baza]
            nr //= baza
        return rez[::-1]

    def __inmultire_cu_un_nr(self, nr1, nr2, baza):
        # input: nr1- a string that represents a number
        #        nr2- a string that represents a number
        #        baza- an integer that represents the base in which the numbers are represented
        # output: rez- a string that represents the multiplication of the numbers in that base
        p = 0
        l = []
        for elem in reversed(nr2):
            rez = self.inmultire_cu_o_cifra(nr1, elem, baza)
            rez = rez.lstrip("0")
            for j in range(0, p):
                rez = rez + "0"
            p += 1
            l.append(rez)
        suma = ""
        for elem in l:
            suma = self.__adunare_in_aceeasi_baza(suma, elem, baza)
        return suma

    def __adunare_in_aceeasi_baza(self, nr1, nr2, baza):
        # input: nr1- a string that represents a number
        #        nr2- a string that represents a number
        #        baza- an integer that represents the base in which the numbers are represented
        # output: suma- a string that represents the sum of the numbers in that base
        carry = 0
        if len(nr1) < len(nr2):
            nr1, nr2 = nr2, nr1
        n = abs(len(nr1) - len(nr2))
        for _ in range(0, n):
            nr2 = "0" + nr2
        nr1 = nr1[::-1]
        nr2 = nr2[::-1]
        suma = ""
        for i in range(0, len(nr1)):
            s = self.__digits.find(nr1[i]) + self.__digits.find(nr2[i]) + carry
            suma += self.__digits[s % baza]
            carry = s // baza
        if carry != 0:
            suma += self.__digits[carry]
        return suma[::-1]

    def __scadere_in_aceeasi_baza(self, nr1, nr2, baza):
        # input: nr1- a string that represents a number
        #                  nr2- a string that represents a number
        #                  baza- an integer that represents the base in which the numbers are represented
        # output: suma- a string that represents the subtraction of the numbers in that base
        carry = 0
        if len(nr1) < len(nr2):
            nr1, nr2 = nr2, nr1
        n = abs(len(nr1) - len(nr2))
        for _ in range(0, n):
            nr2 = "0" + nr2
        nr1 = nr1[::-1]
        nr2 = nr2[::-1]
        rez = ""
        for i in range(0, len(nr1)):
            if self.__digits.find(nr1[i]) + carry < self.__digits.find(nr2[i]):
                rez += self.__digits[baza + self.__digits.find(nr1[i]) - self.__digits.find(nr2[i]) + carry]
                carry = -1
            else:
                rez += self.__digits[self.__digits.find(nr1[i]) - self.__digits.find(nr2[i]) + carry]
                carry = 0
        rez = rez[::-1]
        rez = rez.lstrip("0")
        return rez

    def c_impartiri_succesive(self, baza_nr, nr, baza_rez):
        # input: baza_nr- an integer that represents the base in which the number is represented
        #        nr - a string that represents the number
        #        baza_rez- an integer that represents the base in which the number will be converted
        # output: rez-  a string that represents the result of the conversion
        rez = ""
        m = self.__convert_inbaza10(nr, baza_nr)
        m = int(m)
        while m:
            rez += self.__digits[m % baza_rez]
            m = m // baza_rez
        return rez[::-1]

    def c_substitutie(self, baza_veche, nr, baza_noua):
        # input: baza_veche- an integer that represents the base in which the number is represented
        #        nr - a string that represents the number
        #        baza_noua- an integer that represents the base in which the number will be converted
        # output: rez-  a string that represents the result of the conversion
        rez = 0
        for i, n in enumerate(nr[::-1]):
            rez += self.__digits.find(n) * baza_veche ** i
        rez = str(rez)
        rez = self.__convert_dinbaza10(rez, baza_noua)
        return rez

    def c_baza_intermediara(self, baza_nr, nr, baza_rez):
        # input: baza_nr- an integer that represents the base in which the number is represented
        #        nr - a string that represents the number
        #        baza_rez- an integer that represents the base in which the number will be converted
        # output: rez-  a string that represents the result of the conversion
        nr = self.__convert_inbaza10(nr, baza_nr)
        nr = self.__convert_dinbaza10(nr, baza_rez)
        return nr

    def c_din_baza_2(self, number, new_base):
        # input: number -a string that represents the number in base 2
        #        new_base -an integer (4,8,16) that represents the base in which the number will be converted
        # output: result- a string that represents the result of the conversion
        result = ""
        powof2 = int(math.log(new_base, 2))
        no_zeros = int(len(number) % powof2)
        for _ in range(powof2 - no_zeros):
            number = "0" + number
        for elem in tw.wrap(number, int(math.log(new_base, 2))):
            if elem in self.__to_base_4:
                result += self.__to_base_4[elem]
            elif elem in self.__to_base_8:
                result += self.__to_base_8[elem]
            else:
                result += self.__to_base_16[elem]
        return result.lstrip("0")

    def c_in_baza_2(self, number, old_base):
        # input: number- a string that represents a number in a base (4,8,16)
        #        old_base- an integer that represents the base of the number
        # output: result-  a string that represents result of the conversion in base 2
        result = ""
        if old_base == 4:
            map = dict([(value, key) for key, value in self.__to_base_4.items()])
        elif old_base == 8:
            map = dict([(value, key) for key, value in self.__to_base_8.items()])
        else:
            map = dict([(value, key) for key, value in self.__to_base_16.items()])
        for elem in number:
            result += map[elem]
        return result.lstrip("0")

    def adunare(self, nr1, b1, nr2, b2, baza_rez):
        # input: nr1- a string that represents a number
        #        b1- an integer that represents the base of nr1
        #        nr2- a string that represents a number
        #        b2- an integer that represents the base of nr2
        #        baza_rez: an integer that represents the base of the result
        # output: rez- a string that represents the sum of the numbers in base baza_rez
        rez = self.c_baza_intermediara(b2, nr2, b1)
        rez = self.__adunare_in_aceeasi_baza(nr1, rez, b1)
        rez = self.c_baza_intermediara(b1, rez, baza_rez)
        return rez

    def scadere(self, nr1, b1, nr2, b2, baza_rez):
        # input: nr1- a string that represents a number
        #        b1- an integer that represents the base of nr1
        #        nr2- a string that represents a number
        #        b2- an integer that represents the base of nr2
        #        baza_rez: an integer that represents the base of the result
        # output: rez- a string that represents the subtraction of the numbers in base baza_rez
        rez = self.c_baza_intermediara(b2, nr2, b1)
        rez = self.__scadere_in_aceeasi_baza(nr1, rez, b1)
        rez = self.c_baza_intermediara(b1, rez, baza_rez)
        return rez

    def inmultire_cu_o_cifra(self, nr, cifra, baza):
        # input: nr-a string that represents a number
        #        cifra- an integer that is <10
        #        baza- an integer that represents the base of nr
        # output: rest-  a string that represents the result of the multiplication in that base
        cat = 0
        rest = ""
        for elem in reversed(nr):
            m = self.__digits.find(elem) * cifra + cat
            rest += self.__digits[m % baza]
            cat = m // baza
        rest += str(cat)
        rest = rest[::-1]
        rest = rest.lstrip("0")
        return rest

    def impartire_cu_o_cifra(self, nr, cifra, baza):
        # input: nr-a string that represents a number
        #        cifra- an integer that is <10
        #        baza- an integer that represents the base of nr
        # output: rest-  a string that represents the result of the division in that base
        cat = ""
        rest = 0
        for elem in nr:
            m = (rest * baza + self.__digits.find(elem))
            cat += self.__digits[m // cifra]
            rest = m % cifra
        return cat


# tests
class TestService(unittest.TestCase):
    def setUp(self):
        self.__srv = Service()

    def tearDown(self):
        pass

    def test_c_impartiri_succesive(self):
        rez = self.__srv.c_impartiri_succesive(8, "70", 16)
        self.assertEqual(rez, "38")
        rez = self.__srv.c_impartiri_succesive(16, "30", 2)
        self.assertEqual(rez, "110000")

    def test_c_substitutie(self):
        rez = self.__srv.c_substitutie(8, "70", 16)
        self.assertEqual(rez, "38")
        rez = self.__srv.c_substitutie(16, "30", 2)
        self.assertEqual(rez, "110000")

    def test_c_baza_intermediara(self):
        rez = self.__srv.c_baza_intermediara(8, "70", 16)
        self.assertEqual(rez, "38")
        rez = self.__srv.c_baza_intermediara(16, "30", 2)
        self.assertEqual(rez, "110000")

    def test_c_rapida(self):
        rez = self.__srv.c_din_baza_2("110000", 16)
        self.assertEqual(rez, "30")
        rez = self.__srv.c_in_baza_2("30", 16)
        self.assertEqual(rez, "110000")

    def test_inmultire_cu_o_cifra(self):
        rez = self.__srv.inmultire_cu_o_cifra("1274", 3, 8)
        self.assertEqual(rez, "4064")
        rez = self.__srv.inmultire_cu_o_cifra("A27B93", 8, 16)
        self.assertEqual(rez, "513DC98")

    def test_impartire_cu_o_cifra(self):
        rez = self.__srv.impartire_cu_o_cifra("6243", 3, 7)
        self.assertEqual(rez, "2061")
        rez = self.__srv.impartire_cu_o_cifra("5410", 4, 8)
        self.assertEqual(rez, "1302")

    def test_scadere(self):
        rez = self.__srv.scadere("2453", 8, "39F", 16, 8)
        self.assertEqual(rez, "614")
        rez = self.__srv.scadere("A3AF", 16, "70704", 8, 16)
        self.assertEqual(rez, "31EB")

    def test_adunare(self):
        rez = self.__srv.adunare("56031", 8, "CAF", 16, 8)
        self.assertEqual(rez, "64310")
        rez = self.__srv.adunare("BF433", 16, "CD2A1", 16, 16)
        self.assertEqual(rez, "18C6D4")
