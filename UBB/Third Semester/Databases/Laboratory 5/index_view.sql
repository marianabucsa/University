USE Inchirieri_auto
GO

exec CRUDLocatii 'Bucuresti','Avram Iancu', 8, 30000,100
GO
exec CRUDAngajati 'Andrei','Stan',1500,'casier',900
GO
exec CRUDClienti 'Dana','Petrescu','Strada Dobrogei','0734567898',900
GO
exec CRUDInchirieri 400,'2021-09-23','2022-03-01','in curs',100
GO
SELECT salariu FROM Angajati where salariu=2000
GO
SELECT adresa_client FROM Clienti where adresa_client='Strada Dobrogei'

GO
CREATE OR ALTER VIEW index_view1 AS
SELECT l.id_locatie,count(a.id_angajat) as NumarAngajati
FROM  Angajati a INNER JOIN
             Inchirieri i ON a.id_angajat = i.id_angajat INNER JOIN
             Locatii l ON a.id_locatie = l.id_locatie 
WHERE a.salariu>=2000.0
GROUP BY l.id_locatie 
GO


CREATE OR ALTER VIEW index_view2 AS
SELECT DISTINCT c.nume_client, c.prenume_client
FROM  Clienti c INNER JOIN
             Inchirieri i ON c.id_client = i.id_Client INNER JOIN
			 Angajati a ON i.id_angajat=a.id_angajat INNER JOIN
             Locatii l ON a.id_locatie = l.id_locatie 
WHERE c.adresa_client='Strada Dobrogei' and i.status_inchiriere='in curs'
GROUP BY c.nume_client,c.prenume_client
GO

IF EXISTS (SELECT name FROM sys.indexes
			WHERE name='N_idx_Clienti_Adresa')
	DROP INDEX N_idx_Clienti_Adresa ON Clienti

CREATE NONCLUSTERED INDEX N_idx_Clienti_Adresa
	ON Clienti(adresa_client)	


IF EXISTS (SELECT name FROM sys.indexes
			WHERE name='N_idx_Angajati_Salariu')
	DROP INDEX N_idx_Angajati_Salariu ON Angajati
ALter index N_idx_Angajati_Salariu on Angajati Disable
ALter index N_idx_Angajati_Salariu on Angajati rebuild

CREATE NONCLUSTERED INDEX N_idx_Angajati_Salariu
	ON Angajati(salariu ASC)	
