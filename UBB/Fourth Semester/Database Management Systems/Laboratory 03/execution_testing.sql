/*cerinta 1*/
/*scenariu succes*/
Use Inchirieri_auto

exec [dbo].adaugaAngajatiClientiInchirieri 'Popescu', 'Andrei',135.78, 'casier',
'Borman','Alexandru','strada Parang nr. 23', '0746912598', 25000 ,'2022-03-23','2022-04-23','in curs'

/*scenariu esec*/
exec [dbo].adaugaAngajatiClientiInchirieri 'Popescu', '',135.78, 'casier',
'Borman','Alexandru','strada Parang nr. 23', '0746912598', 25000 ,'2022-03-23','2022-04-23','in curs'

exec [dbo].adaugaAngajatiClientiInchirieri 'Popescu', 'Andrei',135.78, 'casier',
'Borman','','strada Parang nr. 23', '0746912598', 25000 ,'2022-03-23','2022-04-23','in curs'

exec [dbo].adaugaAngajatiClientiInchirieri 'Popescu', 'Andrei',135.78, 'casier',
'Borman','Alexandru','strada Parang nr. 23', '0746912598', -25000 ,'2022-03-23','2022-04-23','in curs'


/*cerinta 2*/
/*scenariu succes*/
exec [dbo].adaugaAngajatiClientiInchirieri2 'Popescu', 'Andrei',135.78, 'casier',
'Borman','Alexandru','strada Parang nr. 23', '0746912598', 25000 ,'2022-03-23','2022-04-23','in curs'

/*scenariu esec*/
exec [dbo].adaugaAngajatiClientiInchirieri2 'Popescu', '',135.78, 'casier',
'Borman','Alexandru','strada Parang nr. 23', '0746912598', 25000 ,'2022-03-23','2022-04-23','in curs'

exec [dbo].adaugaAngajatiClientiInchirieri2 'Popescu', 'Andrei',135.78, 'casier',
'Borman','','strada Parang nr. 23', '0746912598', 25000 ,'2022-03-23','2022-04-23','in curs'

exec [dbo].adaugaAngajatiClientiInchirieri2 'Popescu', 'Andrei',135.78, 'casier',
'Borman','Alexandru','strada Parang nr. 23', '0746912598', -25000 ,'2022-03-23','2022-04-23','in curs'

delete from Clienti where id_client>4
delete from Angajati where id_angajat>8
delete from Inchirieri where id_inchiriere>1
select * from Angajati
select * from Clienti
select * from Inchirieri