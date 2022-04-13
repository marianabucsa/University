-- 1.numarul de angajati care au salariul >=2000 grupati dupa locatii
select l.id_locatie,count(a.id_angajat) as NumarAngajati
from Angajati a, Locatii l 
where a.salariu>=2000.0 AND a.id_locatie=l.id_locatie
group by l.id_locatie

-- 2.toti clientii  care locuiesc pe "Strada Dobrogei" si au statusul inchirierii "in curs" si au inchiriat masina de la locatia 2
select distinct c.nume_client, c.prenume_client
from Clienti c, Inchirieri i,Locatii l, Masini m
where c.id_client=i.id_client And c.adresa_client='Strada Dobrogei' and i.status_inchiriere='in curs' and i.id_masina=m.id_masina and l.id_locatie=m.id_locatie

-- 3.angajatii care au verificat mai mult de o masina
select a.id_angajat, count(a.id_angajat) NumarDeVerificari
from Angajati a, Verificari v, Angajati_Verificari av
where a.id_angajat=av.id_angajat and v.id_verificare=av.id_verificare
group by a.id_angajat
having count(a.id_angajat)>1

-- 4.locatiile si managerii care care au subordonati mai mult de un angajat
select m.id_manager, l.id_locatie, count(a.id_angajat) as NrAngajati
from Manageri m, Angajati a, Locatii l
where m.id_manager=l.id_manager and a.id_locatie=l.id_locatie
group by m.id_manager,l.id_locatie
having count(a.id_angajat)>1

-- 5.toate locatiile pentru care media salariilor angajatilor este >= 2000
select l.id_locatie Locatii, avg(a.salariu) MedieSalarii
from Locatii l, Angajati a
where a.id_locatie=l.id_locatie
group by l.id_locatie
having avg(a.salariu)>2000.0

-- 6.toate adresele la care locuiesc clientii care au statusul inchirierii "in curs" si au fost inchiriate de angajatul "Cosmin Ilisoi"
select distinct c.adresa_client
from Clienti c, Inchirieri i, Angajati a
where i.id_client=c.id_client and i.status_inchiriere like 'in curs' and i.id_angajat=a.id_angajat and a.nume_angajat like 'Cosmin' and a.prenume_angajat like 'Ilisoi'

-- 7.nr de inchirieri ale clientii de la locatia 1
select  c.id_client, count(i.id_inchiriere) NrInchirieri
from Clienti c, Inchirieri i, Angajati a, Locatii l
where c.id_client=i.id_client and i.id_angajat=a.id_angajat and a.id_locatie=l.id_locatie and l.id_locatie='1'
group by c.id_client

-- 8.angajatii care au salariul maxim pentru locatia la care lucreaza si  au mai putin de 2 inchirieri
select l.id_locatie, a.id_angajat, max(a.salariu) SalariuMaxim
from Angajati a, Locatii l, Inchirieri i
where a.id_locatie=l.id_locatie and i.id_angajat=a.id_angajat
group by l.id_locatie, a.id_angajat
having count(i.id_inchiriere)<2

-- 9.toti angajatii care lucreaza la locatia 3 si au inchirieri in curs si numele de forma "Cosmin"
select distinct a.id_angajat, a.nume_angajat 
from Locatii l, Angajati a, Inchirieri i
where a.id_locatie=l.id_locatie and l.id_locatie='3' and a.id_angajat=i.id_angajat and i.status_inchiriere='in curs' and a.nume_angajat='Cosmin'

-- 10.toti clientii care au inchirierile incheiate
select distinct c.id_client, c.nume_client
from Clienti c,Inchirieri i
where c.id_client=i.id_client and i.status_inchiriere not like 'in curs'
