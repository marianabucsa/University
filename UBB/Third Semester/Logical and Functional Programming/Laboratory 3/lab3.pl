% candidat(N:intreg,X:intreg)
% N - domeniul din care se alege candidatul (1-N)
% X - candidatul rezultat
% model de flux (i,o)- nedeterminist

candidat(N,N).
candidat(N,X):- N>1,N1 is N-1,candidat(N1,X).

% exista(L:lista,X:intreg)
% L - lista in care se cauta elementul
% X - elementul cautat
% model de flux (i,i)- determinist

exista([H|_],H):-!.
exista([_|T],X):- exista(T,X).

% modele_aux(N:intreg,M:intreg,K:intreg,C:lista,R:lista)
% N - domeniul din care se formeaza modelul (1-N)
% M - nr pentru verificare conditiei modelului
% K - lungimea candidatului actual
% C - candidatul actual
% R - modelul rezultat
% model de flux (i,i,i,i,o)- nedeterminist

modele_aux(N,_,N,C,C):-!.
modele_aux(N,M,K,[H|T],R):-
    candidat(N,X),
    abs(X-H)>=M,
    not(exista([H|T],X)),
    K1 is K+1,
    modele_aux(N,M,K1,[X|[H|T]],R).

% modele(N:intreg,M:intreg,R:lista)
% N - domeniul din care se formeaza modelul(1-N)
% M - nr pentru verificarea conditiei modelului
% R - modelul rezultat
% model de flux (i,i,o) - nedeterminist

modele(N,M,R):-
    candidat(N,X),
    modele_aux(N,M,1,[X],R).


