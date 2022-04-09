import unittest

from Bilet import Bilet
from Eveniment import Eveniment
from Persoana import Persoana
from Validatori import ValidatorException, ValidatorPersoana, ValidatorEveniment, ValidatorBilet


class TestPersoana(unittest.TestCase):

    def setUp(self):
        self._id1 = 1234
        self._nume1 = "Vasile"
        self._adresa1 = "strada Parang nr. 23"
        self._id2 = 1
        self._nume2 = "Ion"
        self._adresa2 = "Bucuresti"
        self._persoana = Persoana(1234, "Vasile", "strada Parang nr. 23")
        self._persoana1 = Persoana(1, "Ion", "Bucuresti")

    def tearDown(self):
        pass

    def test_creeaza_persoana(self):
        self.assertEqual(self._persoana.get_personID(), 1234)
        self.assertEqual(self._persoana.get_name(), "Vasile")
        self.assertEqual(self._persoana.get_address(), "strada Parang nr. 23")


class TestValidatorPersoana(TestPersoana):

    def setUp(self):
        TestPersoana.setUp(self)

    def tearDown(self):
        TestPersoana.tearDown(self)

    def test_validator_persoana(self):
        self._validator = ValidatorPersoana()
        self._validator.validare(self._persoana)
        self._validator.validare(self._persoana1)
        with self.assertRaises(ValidatorException):
            self._validator.validare(Persoana(-1, "Vasile", "strada Parang nr. 23"))
        with self.assertRaises(ValidatorException):
            self._validator.validare(Persoana(1234, "", "strada Parang nr. 23"))
        with self.assertRaises(ValidatorException):
            self._validator.validare(Persoana(1234, "Vasile", ""))


class TestEveniment(unittest.TestCase):

    def setUp(self):
        self._id3 = 1234
        self._data = "12/03/2020"
        self._ora = "23:46"
        self._descriere = "mama are mere"
        self._id4 = 1
        self._data = "13/07/2020"
        self._ora = "20:40"
        self._descriere = "teatru"
        self._eveniment = Eveniment(1234, "12/03/2020", "23:46", "mama are mere")
        self._eveniment1 = Eveniment(1, "13/07/2020", "20:40", "teatru")

    def tearDown(self):
        pass

    def test_creeaza_eveniment(self):
        self.assertEqual(self._eveniment.get_ID(), 1234)
        self.assertEqual(self._eveniment.get_data(), "12/03/2020")
        self.assertEqual(self._eveniment.get_ora(), "23:46")
        self.assertEqual(self._eveniment.get_descriere(), "mama are mere")


class TestValidatorEveniment(TestEveniment):
    def setUp(self):
        TestEveniment.setUp(self)

    def tearDown(self):
        TestEveniment.tearDown(self)

    def test_validator_eveniment(self):
        self._validator = ValidatorEveniment()
        self._validator.validare(self._eveniment)
        self._validator.validare(self._eveniment1)
        with self.assertRaises(ValidatorException):
            self._validator.validare(Eveniment(-1, "12/03/2020", "23:46", "mama are mere"))
        with self.assertRaises(ValidatorException):
            self._validator.validare(Eveniment(1982, "1232020", "23:46", "mama are mere"))
        with self.assertRaises(ValidatorException):
            self._validator.validare(Eveniment(1982, "12/3/2020", "2346", "mama are mere"))
        with self.assertRaises(ValidatorException):
            self._validator.validare(Eveniment(1982, "12/3/2020", "23:46", ""))


class TestBilet(TestPersoana, TestEveniment):

    def setUp(self):
        TestPersoana.setUp(self)
        TestEveniment.setUp(self)
        self._pret = 20
        self._pret1 = 30
        self._bilet = Bilet(self._id1, self._id3, self._pret)
        self._bilet1 = Bilet(self._id2, self._id4, self._pret1)

    def tearDown(self):
        TestPersoana.tearDown(self)
        TestEveniment.tearDown(self)

    def test_creeaza_bilet(self):
        self.assertEqual(self._bilet.get_id_persoana(), 1234)
        self.assertEqual(self._bilet.get_id_eveniment(), 1234)
        self.assertEqual(self._bilet.get_pret(), 20)


class TestValidatorBilet(TestBilet):

    def setUp(self):
        TestBilet.setUp(self)

    def tearDown(self):
        TestBilet.tearDown(self)

    def test_validator_bilet(self):
        TestBilet.test_creeaza_bilet(self)
        self._validator = ValidatorBilet()
        self._validator.validare(self._bilet)
        self._validator.validare(self._bilet1)
        with self.assertRaises(ValidatorException):
            self._validator.validare(Bilet(-120, 120, 20))
        with self.assertRaises(ValidatorException):
            self._validator.validare(Bilet(120, -120, 20))
        with self.assertRaises(ValidatorException):
            self._validator.validare(Bilet(120, 120, -20))


if __name__ == '__main__':
    unittest.main()
