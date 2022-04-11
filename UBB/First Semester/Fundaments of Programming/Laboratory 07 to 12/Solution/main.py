import unittest

from Consola import Consola
from ListaBilete import FileStocareBilete
from ListaEvenimente import FileStocareEvenimente
from ListaPersoane import FileStocarePersoane, FilePersoane
from SRV_Bilet import ServiceBilet
from SRV_Eveniment import ServiceEveniment
from SRV_Persoana import ServicePersoana
from Validatori import ValidatorPersoana, ValidatorEveniment, ValidatorBilet

rep = FileStocarePersoane("persoane.txt")
val = ValidatorPersoana()
srvp = ServicePersoana(rep, val)
rep = FileStocareEvenimente("evenimente.txt")
val = ValidatorEveniment()
srve = ServiceEveniment(rep, val)
rep = FileStocareBilete("bilete.txt")
val = ValidatorBilet()
srvb = ServiceBilet(rep, val, srvp, srve)
consola = Consola(srvp, srve, srvb)
consola.meniu()
