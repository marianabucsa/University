--Dirty Reads 1
BEGIN TRANSACTION
UPDATE Angajati SET nume_angajat = 'Raul' WHERE id_angajat = 3
INSERT INTO LogTable VALUES('update','Angajati',CURRENT_TIMESTAMP)
WAITFOR DELAY '00:00:10'
ROLLBACK TRANSACTION

-- Non repeatable 1
INSERT INTO Angajati VALUES(106,'Pop','Calin',4564.65,'casier',1,0)
INSERT INTO LogTable VALUES('insert','Angajati',CURRENT_TIMESTAMP)
BEGIN TRAN
WAITFOR DELAY '00:00:10'
UPDATE Angajati SET nume_angajat='Petrescu' where id_angajat = 106
INSERT INTO LogTable VALUES('update','Angajati',CURRENT_TIMESTAMP)
COMMIT TRAN

-- Phantom Reads 1
BEGIN TRAN
WAITFOR DELAY '00:00:10'
INSERT INTO Angajati VALUES(107,'Popescu','Calin',4564.65,'casier',1,0)
INSERT INTO LogTable VALUES('insert','Angajati',CURRENT_TIMESTAMP)
COMMIT TRAN


-- Deadlock 1
BEGIN TRAN
UPDATE Angajati SET nume_angajat='Eminescu' WHERE id_angajat =3
INSERT INTO LogTable VALUES('update','Angajati',CURRENT_TIMESTAMP)
WAITFOR DELAY '00:00:15'
UPDATE Inchirieri SET status_inchiriere='in curs' WHERE id_inchiriere=1
INSERT INTO LogTable VALUES('update','Inchirieri',CURRENT_TIMESTAMP)
COMMIT TRAN

