% 4.a) Sa se scrie un predicat care substituie intr-o lista un element printr-o
% alta lista.
%
% substituie(L,E,Ld,R)
% L- lista initiala
% E- elementul ce trebuie substituit
% Ld- lista cu care va fi substituit elementul
% R - lista rezultata dupa substitutie
%
% model de flux (i,i,i,o)

substituie([],_,_,[]):-!.
substituie([H|T],E,Ld,R):- H=:=E,!,substituie(T,E,Ld,R1),R=[Ld|R1].
substituie([H|T],E,Ld,R):- substituie(T,E,Ld,R1),R=[H|R1].

% 4.b)Sa se elimine elementul de pe pozitia a n-a a unei liste liniare.
%
% elimina(L,N,R)
% L- lista initiala
% N- pozitia de pe care se elimina
% R - lista rezultata dupa eliminare
% model de flux (i,i,o)

elimina([],_,[]):-!.
elimina([_|T],N,R):-N=1,!, elimina(T,0,R).
elimina([H|T],N,R):-N1 is N-1, elimina(T,N1,R1),R=[H|R1].
