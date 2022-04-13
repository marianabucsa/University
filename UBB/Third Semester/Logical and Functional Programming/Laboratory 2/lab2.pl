% 3.a) Sa se sorteze o lista cu eliminarea dublurilor. De ex: [4 2 6 2 3 4] =>[2 3 4 6]
%
% determina_min(L,M)
% L - lista in care se cauta minimul
% M - minimul listei
%
% model de flux (i,o)

determina_min([E],E):-!.
determina_min([H|T],H):- determina_min(T,M1), H<M1,!.
determina_min([_|T],M):- determina_min(T,M).

% elimina_duplicate_min(L,M,LR)
% L -lista initiala
% M - minimul listei caruia i se vor elimina duplicatele
% LR - lista rezultat
%
% model de flux (i,i,o)

elimina_duplicate_min([],_,[]):-!.
elimina_duplicate_min([H|T],M,LR):- H\=M,!, elimina_duplicate_min(T,M,LR1),LR=[H|LR1].
elimina_duplicate_min([_|T],M,LR):- elimina_duplicate_min(T,M,LR).

% sorteaza_fara_duplicate(L,LR)
% L - lista initiala
% LR - lista rezultat
%
% modelul de flux (i,o)

sorteaza_fara_duplicate([],[]):-!.
sorteaza_fara_duplicate(L,LR):- determina_min(L,M),
                                elimina_duplicate_min(L,M,LE),
                                sorteaza_fara_duplicate(LE,LR1),
                                LR=[M|LR1].

% b)Se da o lista eterogena, formata din numere intregi si liste de
% numere. Sa se sorteze fiecare sublista fara pastrarea dublurilor. De
% ex:[1, 2, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] =>[1, 2,
% [1, 4], 3, 6, [1, 3, 7, 9, 10], 5, [1], 7].
%
% sorteaza_subliste(L,R)
% L - lista initiala
% R - lista cu sublistele sortate
%
% modelul de flux (i,o)

sorteaza_subliste([],[]):-!.
sorteaza_subliste([H|T],R):- is_list(H),!,sorteaza_fara_duplicate(H,R1),sorteaza_subliste(T,R2),R=[R1|R2].
sorteaza_subliste([H|T],R):- sorteaza_subliste(T,R1),R=[H|R1].

