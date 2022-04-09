import unittest

from Eveniment import Eveniment
from ListaBilete import FileStocareBilete
from ListaEvenimente import FileStocareEvenimente
from ListaPersoane import RepositoryException, FileStocarePersoane
from Persoana import Persoana
from TesteDomain import TestPersoana, TestEveniment, TestBilet


class TestPersoaneRepo(TestPersoana):

    def setUp(self):
        TestPersoana.setUp(self)
        self._numef = "persoane.txt"

    def tearDown(self):
        with open(self._numef, "w") as fisier:
            fisier.write('')

    def test_persoane_repo(self):
        TestPersoana.test_creeaza_persoana(self)
        self._repo = FileStocarePersoane(self._numef)
        self.assertEqual(len(self._repo), 0)
        self._repo.stocare(self._persoana)
        self.assertEqual(len(self._repo), 1)
        p = self._repo.lista_persoane()[0]
        self.assertEqual(p.get_personID(), 1234)
        self.assertEqual(p.get_name(), "Vasile")
        self.assertEqual(p.get_address(), "strada Parang nr. 23")
        with self.assertRaises(RepositoryException):
            self._repo.stocare(self._persoana)
        self._repo.stocare(Persoana(123, "Ion", "Bucuresti"))
        self.assertEqual(len(self._repo), 2)
        self._repo.stergere(Persoana(123, "Ion", "Bucuresti"))
        self.assertEqual(len(self._repo), 1)
        with self.assertRaises(RepositoryException):
            self._repo.stergere(Persoana(123, "Ion", "Bucuresti"))
        self._repo.stergere(self._persoana)
        self.assertEqual(len(self._repo), 0)
        self._repo.stocare(Persoana(123, "Ion", "Bucuresti"))
        self._repo.modificare(Persoana(123, "Vasile", "strada Parang nr. 23"))
        p = self._repo.lista_persoane()[0]
        self.assertEqual(p.get_personID(), 123)
        self.assertEqual(p.get_name(), "Vasile")
        self.assertEqual(p.get_address(), "strada Parang nr. 23")
        with self.assertRaises((RepositoryException)):
            self._repo.modificare(Persoana(1234, "Ion", "Bucuresti"))
        self._repo.stergere(Persoana(123, "Vasile", "strada Parang nr. 23"))
        self.assertEqual(len(self._repo), 0)


class TestEvenimenteRepo(TestEveniment):
    def setUp(self):
        TestEveniment.setUp(self)
        self._numef = "evenimente.txt"

    def tearDown(self):
        with open(self._numef, "w") as fisier:
            fisier.write('')

    def test_evenimente_repo(self):
        TestEveniment.test_creeaza_eveniment(self)
        self._repo = FileStocareEvenimente(self._numef)
        self.assertEqual(len(self._repo), 0)
        self._repo.stocare(self._eveniment)
        self.assertEqual(len(self._repo), 1)
        e = self._repo.lista_evenimente()[0]
        self.assertEqual(e.get_ID(), 1234)
        self.assertEqual(e.get_data(), "12/03/2020")
        self.assertEqual(e.get_ora(), "23:46")
        self.assertEqual(e.get_descriere(), "mama are mere")
        with self.assertRaises(RepositoryException):
            self._repo.stocare(self._eveniment)
        self._repo.stocare(Eveniment(123, "10/03/2020", "10:30", "teatru"))
        self.assertEqual(len(self._repo), 2)
        self._repo.stergere(Eveniment(123, "10/03/2020", "10:30", "teatru"))
        self.assertEqual(len(self._repo), 1)
        with self.assertRaises(RepositoryException):
            self._repo.stergere(Eveniment(123, "10/03/2020", "10:30", "teatru"))
        self._repo.stergere(self._eveniment)
        self.assertEqual(len(self._repo), 0)
        self._repo.stocare(Eveniment(345, "13/07/2019", "20:30", "concert"))
        self._repo.modificare(Eveniment(345, "12/03/2020", "23:46", "teatru"))
        e = self._repo.lista_evenimente()[0]
        self.assertEqual(e.get_ID(), 345)
        self.assertEqual(e.get_data(), "12/03/2020")
        self.assertEqual(e.get_ora(), "23:46")
        self.assertEqual(e.get_descriere(), "teatru")
        with self.assertRaises(RepositoryException):
            self._repo.modificare(Eveniment(123, "10/03/2020", "10:30", "teatru"))
        self._repo.stergere(Eveniment(345, "12/03/2020", "23:46", "teatru"))
        self.assertEqual(len(self._repo), 0)


class TestBileteRepo(TestBilet):
    def setUp(self):
        TestBilet.setUp(self)
        self._numef = "bilete.txt"
        self._numef1 = "persoane.txt"
        self._numef2 = "evenimente.txt"

    def tearDown(self):
        with open(self._numef, "w") as fisier:
            fisier.write("")

    def test_bilete_repo(self):
        TestBilet.test_creeaza_bilet(self)
        self._repo = FileStocareBilete(self._numef)
        self.assertEqual(len(self._repo), 0)
        self._repo.stocare(self._bilet)
        b = self._repo.lista_bilete()[0]
        self.assertEqual(b.get_id_persoana(), 1234)
        self.assertEqual(b.get_id_eveniment(), 1234)
        self.assertEqual(b.get_pret(), 20)
        self.assertEqual(len(self._repo), 1)
        with self.assertRaises(RepositoryException):
            self._repo.stocare(self._bilet)
        self._repo.modificare(self._bilet, self._bilet1)
        b = self._repo.lista_bilete()[0]
        self.assertEqual(b.get_id_persoana(), 1)
        self.assertEqual(b.get_id_eveniment(), 1)
        self.assertEqual(b.get_pret(), 30)
        with self.assertRaises(RepositoryException):
            self._repo.modificare(self._bilet, self._bilet1)
        self._repo.stergere(self._bilet1)
        with self.assertRaises(RepositoryException):
            self._repo.stergere(self._bilet1)
        self.assertEqual(len(self._repo), 0)
        self._repo.stocare(self._bilet)
        self._repo.stocare(self._bilet1)
        self.assertEqual(len(self._repo), 2)
        self._repo.stergere_by_persoana(1234)
        self.assertEqual(len(self._repo), 1)
        self._repo.stergere_by_eveniment(1)
        self.assertEqual(len(self._repo), 0)


if __name__ == '__main__':
    unittest.main()
