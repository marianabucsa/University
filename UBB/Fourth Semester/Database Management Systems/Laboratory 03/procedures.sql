USE Inchirieri_auto
go
/*procedura ce contine o singura tranzactie pentru toate inserarile*/
create or alter procedure adaugaAngajatiClientiInchirieri(@nume_angajat NVARCHAR(30),@prenume_angajat NVARCHAR(60),@salariu_angajat FLOAT,@pozitia_curenta_angajat NVARCHAR(50),
@nume_client NVARCHAR(30),@prenume_client NVARCHAR(60),@adresa_client NVARCHAR(300),@telefon_client CHAR(10),@plata_inchiriere MONEY,@data_inchiriere DATE, @data_retur DATE,@status_inchiriere NVARCHAR(50))
as
begin
	set nocount on
	begin tran
	declare @id_angajat int
	declare @id_client int
	declare @id_inchiriere int
	declare @id_locatie int
	declare @id_masina int
		begin try
			/*validare angajat*/
			if([dbo].validareAngajat(@nume_angajat,@prenume_angajat,@salariu_angajat,@pozitia_curenta_angajat)<> '')
				raiserror('Angajat invalid!',14,1)

			select @id_angajat=MAX(a.id_angajat) from Angajati a
			select @id_locatie=MAX(l.id_locatie) from Locatii l 
			set @id_angajat=@id_angajat+1

			/*introducere in tabela Angajati*/
			insert into Angajati values(@id_angajat,@nume_angajat,@prenume_angajat,@salariu_angajat,@pozitia_curenta_angajat,@id_locatie,0)
			print 'S-a inserat in tabela Angajati'

			/*validare client*/
			if(dbo.validareClient(@nume_client,@prenume_client,@adresa_client ,@telefon_client )<>'')
				raiserror('Client invalid!',15,1)

			select @id_client=MAX(c.id_client) from Clienti c
			set @id_client=@id_client+1

			/*introducere in tabela Clienti*/
			insert into Clienti values(@id_client,@nume_client,@prenume_client,@adresa_client,@telefon_client)
			print 'S-a inserat in tabela Clienti'

			/*validare inchiriere*/
			if(dbo.validareInchiriere(@plata_inchiriere,@data_inchiriere, @data_retur ,@status_inchiriere)<>'')
				raiserror('Inchiriere invalida',15,1)

			/*introducere in tabela Implicari*/
			select @id_masina=MAX(m.id_masina) from Masini m 
			select @id_inchiriere=MAX(i.id_inchiriere) from Inchirieri i
			set @id_inchiriere=@id_inchiriere+1
			insert into Inchirieri values(@id_inchiriere,@id_masina,@id_client,@id_angajat,@plata_inchiriere,@data_inchiriere,@data_retur,@status_inchiriere)
			print 'S-a inserat in tabela Inchirieri'
			commit tran
			print 'Transaction commited'
		end try

		begin catch
			rollback tran
			print 'Transaction rollbacked'
		end catch
end
go



/*procedura in care fiecare insert presupune o noua tranzactie*/
create or alter procedure adaugaAngajatiClientiInchirieri2(@nume_angajat NVARCHAR(30),@prenume_angajat NVARCHAR(60),@salariu_angajat FLOAT,@pozitia_curenta_angajat NVARCHAR(50),
@nume_client NVARCHAR(30),@prenume_client NVARCHAR(60),@adresa_client NVARCHAR(300),@telefon_client CHAR(10),@plata_inchiriere MONEY,@data_inchiriere DATE, @data_retur DATE,@status_inchiriere NVARCHAR(50))
as
begin
	set nocount on
	declare @id_angajat int
	declare @id_client int
	declare @id_inchiriere int
	declare @id_locatie int
	declare @id_masina int
		begin try
			begin tran
			/*validare angajat*/
			if([dbo].validareAngajat(@nume_angajat,@prenume_angajat,@salariu_angajat,@pozitia_curenta_angajat)<> '')
				raiserror('Angajat invalid!',14,1)

			select @id_angajat=MAX(a.id_angajat) from Angajati a
			select @id_locatie=MAX(l.id_locatie) from Locatii l 
			set @id_angajat=@id_angajat+1

			/*introducere in tabela Angajati*/
			insert into Angajati values(@id_angajat,@nume_angajat,@prenume_angajat,@salariu_angajat,@pozitia_curenta_angajat,@id_locatie,0)
			print 'S-a inserat in tabela Angajati'
			commit tran		/*prima tranzactie*/
		end try
		begin catch
			rollback tran
			print 'Rollback pentru tabela Angajati'
		end catch

		begin try
			begin tran
			/*validare client*/
			if(dbo.validareClient(@nume_client,@prenume_client,@adresa_client ,@telefon_client )<>'')
				raiserror('Client invalid!',15,1)

			select @id_client=MAX(c.id_client) from Clienti c
			set @id_client=@id_client+1

			/*introducere in tabela Clienti*/
			insert into Clienti values(@id_client,@nume_client,@prenume_client,@adresa_client,@telefon_client)
			print 'S-a inserat in tabela Clienti'
			commit tran		/*a 2-a tranzactie*/
		end try
		begin catch
			rollback tran
			print 'Rollback pentru tabela Clienti'
		end catch

		begin try
			begin tran
			
			/*validare inchiriere*/
			if(dbo.validareInchiriere(@plata_inchiriere,@data_inchiriere, @data_retur ,@status_inchiriere)<>'')
				raiserror('Inchiriere invalida',15,1)

			/*introducere in tabela Implicari*/
			select @id_masina=MAX(m.id_masina) from Masini m 
			select @id_inchiriere=MAX(i.id_inchiriere) from Inchirieri i
			set @id_inchiriere=@id_inchiriere+1
			insert into Inchirieri values(@id_inchiriere,@id_masina,@id_client,@id_angajat,@plata_inchiriere,@data_inchiriere,@data_retur,@status_inchiriere)
			print 'S-a inserat in tabela Inchirieri'
			commit tran /*a 3-a tranzactie*/
		end try
		begin catch
			rollback tran
			print 'Rollback pentru tabela Inchirieri'
		end catch
end
go


CREATE OR ALTER FUNCTION [dbo].validareAngajat(@nume NVARCHAR(30),@prenume NVARCHAR(60),@salariu FLOAT,@pozitia_curenta NVARCHAR(50))
RETURNS VARCHAR(1000)
AS
BEGIN
	DECLARE @error_string VARCHAR(1000)
	SET @error_string=''
	IF @nume IS NULL or @nume = ''
		SET @error_string+='Nume invalid!'+CHAR(13)+CHAR(10)
	IF @prenume IS NULL or @prenume = ''
		SET @error_string+='Prenume invalid!'+CHAR(13)+CHAR(10)
	IF @salariu <=0
		SET @error_string+='Salariu invalid!'+CHAR(13)+CHAR(10)
	IF @pozitia_curenta IS NULL or @pozitia_curenta = ''
		SET @error_string+='Pozitia curenta invalida!'+CHAR(13)+CHAR(10)
	IF @error_string IS NOT NULL
		RETURN @error_string
	RETURN NULL
END

GO

CREATE OR ALTER FUNCTION dbo.validareClient(@nume NVARCHAR(30),@prenume NVARCHAR(60),@adresa NVARCHAR(300),@telefon CHAR(10))
RETURNS VARCHAR(1000)
AS
BEGIN
	DECLARE @error_string VARCHAR(1000)
	SET @error_string = ''
	IF @nume IS NULL or @nume = ''
		SET @error_string+='Nume invalid!'+CHAR(13)+CHAR(10)
	IF @prenume IS NULL or @prenume = ''
		SET @error_string+='Prenume invalid!'+CHAR(13)+CHAR(10)
	IF @adresa IS NULL or @adresa = ''
		SET @error_string+='Adresa invalida!'+CHAR(13)+CHAR(10)
	IF len(@telefon) <> 10
		SET @error_string+='Numar de telefon invalid!'+CHAR(13)+CHAR(10)
	IF @error_string IS NOT NULL
		RETURN @error_string
	RETURN NULL
END

GO

CREATE OR ALTER FUNCTION dbo.validareInchiriere(@plata MONEY,@data_inchiriere DATE, @data_retur DATE,@status_inchiriere NVARCHAR(50))
RETURNS VARCHAR(1000)
AS
BEGIN
	DECLARE @error_string VARCHAR(1000)
	SET @error_string=''
	IF @plata <= 0
		SET @error_string+='Plata invalida!'+CHAR(13)+CHAR(10)
	IF @status_inchiriere IS NULL or @status_inchiriere = ''
		SET @error_string+='Status inchiriere invalid!'+CHAR(13)+CHAR(10)
	IF @error_string IS NOT NULL
		RETURN @error_string
	RETURN NULL
END