create or alter procedure deadlock_scenario1(@name varchar(50),@status varchar(50))as
begin
	begin tran 
		UPDATE Angajati SET nume_angajat=@name WHERE id_angajat =3
		INSERT INTO LogTable VALUES('update','Angajati',CURRENT_TIMESTAMP)

		WAITFOR DELAY '00:00:2'
		UPDATE Inchirieri SET status_inchiriere=@status WHERE id_inchiriere=1
		INSERT INTO LogTable VALUES('update','Inchirieri',CURRENT_TIMESTAMP)
	commit tran
end
go


create or alter procedure deadlock_scenario2(@status varchar(50),@name varchar(50))as
begin
	begin tran 
		UPDATE Inchirieri SET status_inchiriere=@status WHERE id_inchiriere=1
		INSERT INTO LogTable VALUES('update','Inchirieri',CURRENT_TIMESTAMP)
		WAITFOR DELAY '00:00:3'

		UPDATE Angajati SET nume_angajat= @name WHERE id_angajat =3
		INSERT INTO LogTable VALUES('update','Angajati',CURRENT_TIMESTAMP)
	commit tran
end

select * from Angajati
select * from Inchirieri
select * from LogTable
delete from LogTable where Lid>0

ALTER DATABASE Inchirieri_Auto  SET READ_COMMITTED_SNAPSHOT ON;ALTER DATABASE Inchirieri_Auto SET ALLOW_SNAPSHOT_ISOLATION ON;