import unittest

from Bilet import Bilet
from Eveniment import Eveniment
from ListaEvenimente import StocareEvenimente
from Persoana import Persoana
from SRV_Bilet import ServiceBilet, ServiceException
from SRV_Eveniment import ServiceEveniment
from SRV_Persoana import ServicePersoana
from ListaPersoane import RepositoryException, StocarePersoane
from TesteDomain import TestValidatorPersoana, TestValidatorEveniment, TestValidatorBilet
from TesteRepository import TestPersoaneRepo, TestEvenimenteRepo, TestBileteRepo
from Validatori import ValidatorPersoana, ValidatorEveniment, ValidatorBilet, ValidatorException


class TestPersoaneSrv(TestPersoaneRepo, TestValidatorPersoana):
    def setUp(self):
        TestPersoaneRepo.setUp(self)
        TestValidatorPersoana.setUp(self)

    def tearDown(self):
        TestPersoaneRepo.tearDown(self)
        TestValidatorPersoana.tearDown(self)

    def test_persoane_srv(self):
        TestPersoaneRepo.test_persoane_repo(self)
        TestValidatorPersoana.test_validator_persoana(self)
        self._val = ValidatorPersoana()
        self._srv = ServicePersoana(self._repo, self._val)
        self.assertEqual(self._srv.nr_persoane(), 0)
        self._srv.creare_persoana(1, "Vasile", "Bucuresti")
        self.assertEqual(self._srv.nr_persoane(), 1)
        with self.assertRaises(RepositoryException):
            self._srv.creare_persoana(1, "Ion", "Bucuresti")
        with self.assertRaises(ValidatorException):
            self._srv.creare_persoana(-1, "Ion", "Bucuresti")
        self.assertEqual(Persoana(1, "Vasile", "Bucuresti"), self._srv.afisare_persoane()[0])
        self._srv.modificare_persoana(1, "Ion", "Cluj-Napoca")
        with self.assertRaises(RepositoryException):
            self._srv.modificare_persoana(2, "Vasile", "Bucuresti")
        self.assertEqual(Persoana(1, "Ion", "Cluj-Napoca"), self._srv.cauta_persoana_id(1)[0])
        self.assertEqual(Persoana(1, "Ion", "Cluj-Napoca"), self._srv.cauta_persoana_nume("Ion")[0])
        self.assertEqual(Persoana(1, "Ion", "Cluj-Napoca"), self._srv.cauta_persoana_adresa("Cluj-Napoca")[0])


class TestEvenimenteSrv(TestEvenimenteRepo, TestValidatorEveniment):
    def setUp(self):
        TestEvenimenteRepo.setUp(self)
        TestValidatorEveniment.setUp(self)

    def tearDown(self):
        TestEvenimenteRepo.tearDown(self)
        TestValidatorEveniment.tearDown(self)

    def test_evenimente_srv(self):
        TestEvenimenteRepo.test_evenimente_repo(self)
        TestValidatorEveniment.test_validator_eveniment(self)
        self._val = ValidatorEveniment()
        self._srv = ServiceEveniment(self._repo, self._val)
        self.assertEqual(self._srv.nr_evenimente(), 0)
        self._srv.creare_eveniment(123, "23/07/2000", "20:30", "concert")
        self.assertEqual(self._srv.nr_evenimente(), 1)
        with self.assertRaises(RepositoryException):
            self._srv.creare_eveniment(123, "23/07/2000", "20:30", "concert")
        with self.assertRaises(ValidatorException):
            self._srv.creare_eveniment(-123, "23/07/2000", "20:30", "concert")
        self._srv.modificare_eveniment(123, "22/03/2020", "18:30", "teatru")
        self.assertEqual(Eveniment(123, "22/03/2020", "18:30", "teatru"), self._srv.cauta_eveniment_id(123)[0])
        with self.assertRaises(RepositoryException):
            self._srv.modificare_eveniment(12, "22/03/2020", "18:30", "teatru")
        with self.assertRaises(ValidatorException):
            self._srv.modificare_eveniment(-123, "23/07/2000", "20:30", "concert")
        self.assertEqual(Eveniment(123, "22/03/2020", "18:30", "teatru"), self._srv.cauta_eveniment_id(123)[0])
        self.assertEqual(Eveniment(123, "22/03/2020", "18:30", "teatru"),
                         self._srv.cauta_eveniment_data("22/03/2020")[0])
        self.assertEqual(Eveniment(123, "22/03/2020", "18:30", "teatru"), self._srv.cauta_eveniment_ora("18:30")[0])
        self.assertEqual(Eveniment(123, "22/03/2020", "18:30", "teatru"),
                         self._srv.cauta_eveniment_descriere("teatru")[0])


class TestBileteSrv(TestBileteRepo, TestValidatorBilet):
    def setUp(self):
        TestBileteRepo.setUp(self)
        TestValidatorBilet.setUp(self)

    def tearDown(self):
        TestBileteRepo.tearDown(self)
        TestValidatorBilet.tearDown(self)

    def test_bilete_srv(self):
        TestBileteRepo.test_bilete_repo(self)
        TestValidatorBilet.test_validator_bilet(self)
        self._val = ValidatorBilet()
        self._repop = StocarePersoane()
        self._valp = ValidatorPersoana()
        self._srvp = ServicePersoana(self._repop, self._valp)
        self._repoe = StocareEvenimente()
        self._vale = ValidatorEveniment()
        self._srve = ServiceEveniment(self._repoe, self._vale)
        self._srv = ServiceBilet(self._repo, self._val, self._srvp, self._srve)
        self.assertEqual(self._srv.nr_bilete(), 0)
        self._srvp.creare_persoana(123, "Vasile", "nr 209")
        self._srve.creare_eveniment(123, "10/03/2020", "10:30", "teatru")
        self._srvp.creare_persoana(12, "Ion", "nr 209")
        self._srve.creare_eveniment(12, "10/03/2020", "10:30", "concert")
        self._srv.creare_bilet(123, 123, 10)
        self.assertEqual(self._srv.nr_bilete(), 1)
        self._srv.modificare_bilet(123, 123,12, 12, 20)
        self.assertEqual(Bilet(12, 12, 20), self._srv.afisare_bilete()[0])
        with self.assertRaises(ServiceException):
            self._srv.modificare_bilet(4, 4, 5, 5, 20)
        self._srv.stergere_bilet(12, 12)
        self.assertEqual(self._srv.nr_bilete(), 0)
        self._srv.creare_bilet(123, 123, 10)
        self._srv.creare_bilet(12, 12, 10)
        self.assertEqual(self._srv.nr_bilete(), 2)
        self._srv.stergere_bilet_id_eveniment(123)
        self.assertEqual(self._srv.nr_bilete(), 1)
        self._srv.stergere_bilet_id_persoana(12)
        self.assertEqual(self._srv.nr_bilete(), 0)
        self._srvp.creare_persoana(10, "Vasile", "nr 209")
        self._srvp.creare_persoana(11, "Vasile", "nr 209")
        self._srve.creare_eveniment(1, "13/03/2020", "10:30", "b")
        self._srve.creare_eveniment(2, "10/03/2019", "10:30", "a")
        self._srve.creare_eveniment(3, "1/03/2018", "10:30", "e")
        self._srve.creare_eveniment(4, "7/04/2020", "10:30", "f")
        self._srve.creare_eveniment(5, "11/05/2019", "10:30", "d")
        self._srv.creare_bilet(123, 1, 10)
        self._srv.creare_bilet(10, 1, 10)
        self._srv.creare_bilet(123, 2, 10)
        self._srv.creare_bilet(11, 2, 10)
        self._srv.creare_bilet(123, 3, 10)
        self._srv.creare_bilet(123, 4, 10)
        self._srv.creare_bilet(123, 5, 10)
        self._srv.creare_bilet(12, 1, 10)
        self._srv.creare_bilet(12, 2, 10)
        self._srv.creare_bilet(12, 3, 10)
        self._srv.creare_bilet(12, 4, 10)
        self._srv.creare_bilet(12, 5, 10)
        self.assertEqual(len(self._srv.afiseaza_evenimente_persoana_data(123)), 5)
        self.assertEqual(self._srv.afiseaza_evenimente_persoana_data(123)[4].get_ID(), 4)
        self.assertEqual(self._srv.afiseaza_evenimente_persoana_data(123)[0].get_ID(), 3)
        self.assertEqual(self._srv.afiseaza_evenimente_persoana_data(123)[1].get_ID(), 2)
        self.assertEqual(self._srv.afiseaza_evenimente_persoana_data(123)[2].get_ID(), 5)
        self.assertEqual(self._srv.afiseaza_evenimente_persoana_data(123)[3].get_ID(), 1)
        self.assertEqual(len(self._srv.afiseaza_evenimente_persoana_descriere(123)), 5)
        self.assertEqual(self._srv.afiseaza_evenimente_persoana_descriere(123)[0].get_ID(), 2)
        self.assertEqual(self._srv.afiseaza_evenimente_persoana_descriere(123)[1].get_ID(), 1)
        self.assertEqual(self._srv.afiseaza_evenimente_persoana_descriere(123)[2].get_ID(), 5)
        self.assertEqual(self._srv.afiseaza_evenimente_persoana_descriere(123)[3].get_ID(), 3)
        self.assertEqual(self._srv.afiseaza_evenimente_persoana_descriere(123)[4].get_ID(), 4)
        self.assertEqual(len(self._srv.cele_mai_multe_evenimente()), 2)
        self.assertEqual(self._srv.cele_mai_multe_evenimente()[123].get_nr_evenimente(), 5)
        self.assertEqual(self._srv.cele_mai_multe_evenimente()[12].get_nr_evenimente(), 5)
        self.assertEqual(len(self._srv.afiseaza_20_evenimente()), 1)
        self.assertEqual(self._srv.afiseaza_20_evenimente()[0].get_nr_persoane(), 3)


if __name__ == '__main__':
    unittest.main()
