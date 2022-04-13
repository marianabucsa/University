USE Inchirieri_auto
GO

CREATE OR ALTER PROCEDURE [dbo].[CRUDAngajati] @nume NVARCHAR(30),@prenume NVARCHAR(60),@salariu FLOAT,@pozitia_curenta NVARCHAR(50),@NrRows INT
AS
BEGIN
	SET NOCOUNT ON
	DECLARE @error_string VARCHAR(1000)
	SELECT @error_string=dbo.validareAngajat(@nume,@prenume,@salariu,@pozitia_curenta,@NrRows)
	IF @error_string IS NOT NULL or @error_string!=''
		PRINT @error_string
	ELSE 
		BEGIN
			--insert
			DECLARE @Lid INT, @Aid INT, @id INT
			SELECT @id=MAX(id_angajat) FROM Angajati
			SET @Aid=@id+1
			SELECT TOP 1 @Lid=id_locatie FROM Locatii
			WHILE @NrRows>0
				BEGIN
					INSERT INTO Angajati VALUES (@Aid,@nume,@prenume,@salariu,@pozitia_curenta,1,@Lid)
					SET @NrRows=@NrRows-1
					SET @Aid=@Aid+1
				END
			--select
			SELECT * FROM Angajati WHERE id_angajat>@id
			--update
			UPDATE Angajati SET salariu=2000 WHERE id_angajat>@id
			--delete
			DELETE FROM Angajati WHERE id_angajat>@id

			PRINT 'Au fost executate operatiile CRUD pe tabela Angajati'
		END
END

GO

CREATE OR ALTER PROCEDURE [dbo].[CRUDClienti] @nume VARCHAR(30),@prenume VARCHAR(60), @adresa VARCHAR(300),@telefon CHAR(10),@NrRows INT 
AS
BEGIN
	SET NOCOUNT ON 
	DECLARE @error_string VARCHAR(1000)
	SELECT @error_string=dbo.validareClient(@nume,@prenume,@adresa,@telefon,@NrRows)
	IF @error_string IS NOT NULL or @error_string!=''
		PRINT @error_string
	ELSE
		BEGIN
			--insert
			DECLARE @Cid INT,@id INT
			SELECT @Cid=MAX(id_client) FROM Clienti
			SET @Cid=@Cid+1
			SET @id=@Cid
			WHILE @NrRows >0
				BEGIN
					INSERT INTO Clienti VALUES (@Cid,@nume,@prenume,@adresa,@telefon)
					SET @NrRows=@NrRows-1
					SET @Cid=@Cid+1
				END
			--select
			SELECT * FROM Clienti WHERE id_client>=@id
			--update
			UPDATE Clienti SET prenume_client='Liviu' where id_client>=@id
			--delete
			DELETE FROM Clienti WHERE id_client>=@id

			PRINT 'Au fost executate operatiile CRUD pe tabela Clienti'
		END
END

GO

CREATE OR ALTER PROCEDURE [dbo].[CRUDInchirieri] @plata MONEY,@data_inchiriere DATE,@data_retur DATE,@status_inchiriere NVARCHAR(50),@NrRows INT
AS
BEGIN
	SET NOCOUNT ON 
	DECLARE @error_string VARCHAR(1000)
	SELECT @error_string=dbo.validareInchiriere(@plata,@data_inchiriere,@data_retur,@status_inchiriere,@NrRows)
	IF @error_string IS NOT NULL or @error_string!=''
		PRINT @error_string
	ELSE
		BEGIN
			--insert
			DECLARE @Iid INT,@Mid INT,@Cid INT,@Aid INT,@id INT
			SELECT TOP 1 @Mid=id_masina FROM Masini
			SELECT TOP 1 @Cid=id_client FROM Clienti
			SELECT TOP 1 @Aid=id_angajat FROM Angajati
			SELECT @Iid=MAX(id_inchiriere) FROM Inchirieri
			SET @Iid=@Iid+1
			SET @id=@Iid
			WHILE @NrRows >0
				BEGIN
					INSERT INTO Inchirieri VALUES (@Iid,@Mid,@Cid,@Aid,@plata,@data_inchiriere,@data_retur,@status_inchiriere)
					SET @NrRows=@NrRows-1
					SET @Iid=@Iid+1
				END
			--select
			SELECT * FROM Inchirieri WHERE id_inchiriere>=@id
			--update
			UPDATE Inchirieri SET plata=100 WHERE id_inchiriere>=@id
			--delete
			DELETE FROM Inchirieri WHERE id_inchiriere>=@id

			PRINT 'Au fost executate operatiile CRUD pe tabela Inchirieri'
		END
END
GO

CREATE OR ALTER PROCEDURE [dbo].[CRUDLocatii] @oras NVARCHAR(100),@strada NVARCHAR(200),@nr_strada SMALLINT,@cod_postal INT,@NrRows INT
AS
BEGIN
	SET NOCOUNT ON 
	DECLARE @error_string VARCHAR(1000)
	SELECT @error_string=dbo.validareLocatie(@oras,@strada,@nr_strada,@cod_postal,@NrRows)
	IF @error_string IS NOT NULL or @error_string!=''
		PRINT @error_string
	ELSE
		BEGIN
			--insert
			DECLARE @Mid INT,@Lid INT,@id INT
			SELECT TOP 1 @Mid=id_manager FROM Manageri
			SELECT TOP 1 @Lid=id_locatie FROM Locatii
			SELECT @Lid=MAX(id_locatie) FROM Locatii
			SET @Lid=@Lid+1
			SET @id=@Lid
			WHILE @NrRows >0
				BEGIN
					INSERT INTO Locatii VALUES (@Lid,@oras,@strada,@nr_strada,@cod_postal,@Mid)
					SET @NrRows=@NrRows-1
					SET @Lid=@Lid+1
				END
			--select
			SELECT * FROM Locatii WHERE id_locatie>=@id
			--update
			UPDATE Locatii SET nr_strada=10 WHERE id_locatie>=@id
			--delete
			DELETE FROM Locatii WHERE id_locatie>=@id

			PRINT 'Au fost executate operatiile CRUD pe tabela Locatii'
		END
END