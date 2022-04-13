CREATE PROCEDURE Next1
AS
BEGIN
ALTER TABLE Angajati 
ALTER COLUMN nume_angajat nvarchar(60) NOT NULL
PRINT 'Coloana nume_angajat din tabela Angajati a fost modificata cu succes!(MODIFICA TIPUL UNEI COLOANE)'
END
GO

CREATE PROCEDURE Previous1
AS 
BEGIN
ALTER TABLE Angajati
ALTER COLUMN nume_angajat nvarchar(30) NOT NULL
PRINT 'Coloana nume_anagajat din tabela Angajati a fost modificata cu succes!(MODIFICA TIPUL UNEI COLOANE)'
END
GO

CREATE PROCEDURE Next2
AS
BEGIN
ALTER TABLE Inchirieri
ADD CONSTRAINT df_plata DEFAULT 0 FOR plata
PRINT 'Coloana plata din tabela Inchirieri a fost modificata cu succes!(ADAUGA CONSTRANGERE-VALOARE IMPLICITA)'
END
GO

CREATE PROCEDURE Previous2
AS
BEGIN
ALTER TABLE Inchirieri
DROP df_plata
PRINT 'Coloana plata din tabela Inchirieri a fost modificata cu succes!(STERGE CONSTRANGERE-VALOARE IMPLICITA)'
END
GO

CREATE PROCEDURE Next3
AS
BEGIN
CREATE TABLE IstoricPlati(
id_plata INT PRIMARY KEY,
valoare FLOAT,
id_inchiriere SMALLINT
)
PRINT 'Tabela IstoricPlati a fost creata cu succes!(CREARE TABELA)'
END
GO

CREATE PROCEDURE Previous3
AS
BEGIN
DROP TABLE IF EXISTS IstoricPlati
PRINT 'Tabela IstoricPlati a fost stearsa cu succes!(STERGERE TABELA)'
END
GO

CREATE PROCEDURE Next4
AS 
BEGIN
ALTER TABLE IstoricPlati
ADD data_plata DATETIME
PRINT 'Campul data_plata a fost adaugat cu succes!(ADAUGARE CAMP NOU)'
END
GO

CREATE PROCEDURE Previous4
AS 
BEGIN
ALTER TABLE IstoricPlati
DROP COLUMN data_plata
PRINT 'Campul data_plata a fost sters cu succes!(STERGERE CAMP NOU)'
END
GO


CREATE PROCEDURE Next5
AS
BEGIN
ALTER TABLE IstoricPlati
ADD CONSTRAINT fk_IstoricPlati FOREIGN KEY(id_inchiriere) REFERENCES Inchirieri(id_inchiriere)
PRINT 'In tabela IstoricPlati a fost adaugata o cheie straina!(CREARE CONSTRANGERE-CHEIE STRAINA)'
END
GO

CREATE PROCEDURE Previous5
AS
BEGIN
ALTER TABLE IstoricPlati
DROP CONSTRAINT fk_IstoricPlati
PRINT 'Cheia straina din tabela IstoricPlati a fost stearsa cu succes!(STERGERE CONSTRANGERE-CHEIE STRAINA)'
END
