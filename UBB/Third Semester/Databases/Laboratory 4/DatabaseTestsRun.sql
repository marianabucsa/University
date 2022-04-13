create or alter procedure DatabaseTestsRun
as 
begin
	declare @TestID int
	declare @TestName varchar(30)
	declare @TableName varchar(30)
	declare @NoOfRows int
	declare @TableID int
	declare @TestRunID int
	declare @ViewID int
	declare @ViewName varchar(30)
	declare @TimpStart datetime
	declare @TimpStart1 datetime

	declare cursor_teste cursor scroll for select TestId, name from Tests
	open cursor_teste
	fetch next from cursor_teste into @TestId, @TestName
	while @@FETCH_STATUS=0 
	begin
		--delete- uri
		set @TimpStart1= getdate()
		insert into TestRuns values (@TestName,@TimpStart1,getdate())  
		declare cursor_tabele cursor scroll for select T.TableID, Name, NoOfRows from Tables T inner join TestTables TT on T.TableID=tt.TableID where @TestID=TT.TestID order by Position asc
		open cursor_tabele
		fetch next from cursor_tabele into @TableID, @TableName, @NoOfRows
		while @@FETCH_STATUS=0
		begin
			exec('delete from '+ @TableName)
			fetch next from cursor_tabele into @TableID, @TableName, @NoOfRows
		end
		-- insert- uri
		set @TestRunID = @@IDENTITY
		fetch prior from cursor_tabele into @TableID, @TableName, @NoOfRows
		while @@FETCH_STATUS=0 
		begin
			set @TimpStart = GETDATE()
			exec('insert'+@TableName+' '+@NoOfRows)
			insert into TestRunTables values (@TestRunID, @TableID,@TimpStart,getdate())  
			fetch prior from cursor_tabele into @TableID, @TableName, @NoOfRows
		end
		close cursor_tabele
		deallocate cursor_tabele
		
		--select- uri
		declare cursor_views cursor scroll for select V.ViewID, V.Name from Views V inner join TestViews VV on V.ViewID=VV.ViewID where @TestID=VV.TestID
		open cursor_views
		fetch next from cursor_views into @ViewID, @ViewName
		Print @ViewID
		while @@FETCH_STATUS=0
		begin
			set @TimpStart = GETDATE()
			exec('select * from '+ @ViewName)
			insert into TestRunViews values (@TestRunID, @ViewID, @TimpStart, GETDATE())  
			fetch next from cursor_views into @ViewID, @ViewName
		end
		insert into TestRuns values (@TestName,@TimpStart1,getdate())  
		close cursor_views
		deallocate cursor_views

		fetch next from cursor_teste into @TestId, @TestName
	end
	close cursor_teste
	deallocate cursor_teste
	delete from Inchirieri
	delete from Clienti
	delete from Masini
	delete from Modele
	delete from Angajati
	delete from Locatii
	delete from Manageri
end
go

exec DatabaseTestsRun
go

--1--
create or alter procedure insertClienti @no_randuri int as
begin
	declare @i int
	set @i=1
	while @i<= @no_randuri 
	begin
		insert into Clienti values(@i,'Maria','Pop','strada Parang','0745678456')
		set @i=@i+1
	end
end
go

--2--
create or alter procedure insertAngajati @no_randuri int as
begin
	declare @i int
	set @i=1
	while @i<= @no_randuri 
	begin
		insert into Angajati values(@i,'aaa','aaa',2300,'manager',1,4)
		set @i=@i+1
	end
end
go 

--3--
create or alter procedure insertAngajati_Verificari @no_randuri int as
begin
	declare @i int
	set @i=1
	while @i<= @no_randuri 
	begin
		insert into Angajati_Verificari values(@i,1,3)
		set @i=@i+1
	end
end
go 

--4--
create or alter procedure insertAsigurari @no_randuri int as
begin
	declare @i int
	set @i=1
	while @i<= @no_randuri 
	begin
		insert into Asigurari values(@i,1,'hh','nn', '2021-12-07', '2021-12-07')
		set @i=@i+1
	end
end
go 

--5--
create or alter procedure insertInchirieri @no_randuri int as
begin
	declare @i int
	set @i=1
	while @i<= @no_randuri 
	begin
		insert into Inchirieri values(@i,1,1,1,4,'2021-12-07','2021-12-07','hh')
		set @i=@i+1
	end
end
go 

--6--
create or alter procedure insertLocatii @no_randuri int as
begin
	declare @i int
	set @i=1
	while @i<= @no_randuri 
	begin
		insert into Locatii values(@i,'gg','jj',1,345,1)
		set @i=@i+1
	end
end
go 

--7--
create or alter procedure insertManageri @no_randuri int as
begin
	declare @i int
	set @i=1
	while @i<= @no_randuri 
	begin
		insert into Manageri values(@i,'hh','jj')
		set @i=@i+1
	end
end
go 

--8--
create or alter procedure insertMasini @no_randuri int as
begin
	declare @i int
	set @i=1
	while @i<= @no_randuri 
	begin
		insert into Masini values(@i,1,1,'2000','hh',4)
		set @i=@i+1
	end
end
go 

--9--
create or alter procedure insertModele @no_randuri int as
begin
	declare @i int
	set @i=1
	while @i<= @no_randuri 
	begin
		insert into Modele values(@i,'fff','ggg')
		set @i=@i+1
	end
end
go


--10--
create or alter procedure insertVerificari @no_randuri int as
begin
	declare @i int
	set @i=1
	while @i<= @no_randuri 
	begin
		insert into Verificari values(@i,'2021-12-07 00:00:00','bun',1)
		set @i=@i+1
	end
end
go

exec DatabaseTestsRun
