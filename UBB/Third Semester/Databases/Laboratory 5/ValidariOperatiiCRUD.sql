USE Inchirieri_auto
GO


CREATE OR ALTER FUNCTION dbo.validareAngajat(@nume NVARCHAR(30),@prenume NVARCHAR(60),@salariu FLOAT,@pozitia_curenta NVARCHAR(50),@NrRows INT)
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
	IF @NrRows <=0
		SET @error_string+='Numar de linii invalid!'+CHAR(13)+CHAR(10)
	IF @error_string IS NOT NULL
		RETURN @error_string
	RETURN NULL
END

GO

CREATE OR ALTER FUNCTION dbo.validareClient(@nume NVARCHAR(30),@prenume NVARCHAR(60),@adresa NVARCHAR(300),@telefon CHAR(10),@NrRows INT)
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
	IF @NrRows <=0
		SET @error_string+='Numar de linii invalid!'+CHAR(13)+CHAR(10)
	IF @error_string IS NOT NULL
		RETURN @error_string
	RETURN NULL
END

GO

CREATE OR ALTER FUNCTION dbo.validareInchiriere(@plata MONEY,@data_inchiriere DATE, @data_retur DATE,@status_inchiriere NVARCHAR(50),@NrRows INT)
RETURNS VARCHAR(1000)
AS
BEGIN
	DECLARE @error_string VARCHAR(1000)
	SET @error_string=''
	IF @plata <= 0
		SET @error_string+='Plata invalida!'+CHAR(13)+CHAR(10)
	IF @status_inchiriere IS NULL or @status_inchiriere = ''
		SET @error_string+='Status inchiriere invalid!'+CHAR(13)+CHAR(10)
	IF @NrRows <=0
		SET @error_string+='Numar de linii invalid!'+CHAR(13)+CHAR(10)
	IF @error_string IS NOT NULL
		RETURN @error_string
	RETURN NULL
END

go

CREATE OR ALTER FUNCTION dbo.validareLocatie (@oras NVARCHAR(100),@strada NVARCHAR(200),@nr_strada SMALLINT,@cod_postal INT,@NrRows INT)
RETURNS VARCHAR(1000)
AS
BEGIN
	DECLARE @error_string VARCHAR(1000)
	SET @error_string=''
	IF @oras IS NULL or @oras = ''
		SET @error_string+='Oras invalid!'+CHAR(13)+CHAR(10)
	IF @strada IS NULL or @strada = ''
		SET @error_string+='Strada invalida!'+CHAR(13)+CHAR(10)
	IF @nr_strada <=0
		SET @error_string+='Nr. strada invalid!'+CHAR(13)+CHAR(10)
	IF @cod_postal <=0
		SET @error_string+='Cod postal invalid!'+CHAR(13)+CHAR(10)
	IF @NrRows <=0
		SET @error_string+='Numar de linii invalid!'+CHAR(13)+CHAR(10)
	IF @error_string IS NOT NULL
		RETURN @error_string
	RETURN NULL
END
