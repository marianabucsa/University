;;; Registrul este o lista care contine liste de �nregistrari
;;; asociative cu urmatoarea structura:
;;; ((pn. <prenume>) (nf .<nume de familie>) (v . <v�rsta>))
;;; Registrul este pastrat �n variabila globala numita PD_DATA.
;;Datele solicitate de la utilizator pentru o noua intrare
;; le adauga �n lista
(defun C:DP_ADINREG ( / prenume nume varsta inreg)

 ; preia datele de la utlizator
 (initget 1)
 (setq prenume (getstring "\nIntroduceti prenumele: "))
 (initget 1)
 (setq nume (getstring "\nIntroduceti numele: "))
 (initget 7)
 (setq varsta (getint "\nIntroduceti varsta: "))
 ; Creeaza si adauga o �nregistrare
 ; Remarcati utilizarea functiei (cons)cu doi atomi ca si argumente
 ; si faptul ca noua �nregistrare trebuie sa fie o lista creata cu
 ; functia (list) �nainte de a o adauaga lui DP_DATA
 (setq inreg (list (cons 'pn prenume) (cons 'nf nume)
 (cons 'v varsta))
 DP_DATA (append DP_DATA (list inreg))
 )

 ; anuleaza printarea rezultatului functiei
 (princ)
 )
;; Listeaza continutul registrului de date personale intr-o forma
;inteligibila
(defun C:DP_LISTARE ( / curent inreg n)

 ;nu dorim pierderea pointer-ului spre �nregistrarea actuala
 ;astfel ca vom folosi o variabila interna pentru a parcurge lista
 ;si spre alte inregistrari
 (setq curent DP_DATA
 n 1)
 ; pointerul va ajunge la sf�rsitul listei cand va atinge NIL
 ; la sf�rsitul listei, valoare care va folosita pentru a parasi
 ;bucla
 (while curent
 (setq inreg (car curent)) ; preia datele
 ; data este stocata �n zona de acces prin cdr a listelor
 ;asociative ale inregistrarii
 ; iar cheia de cautare este data de car
 (princ (strcat "\n Inregistrarea" (itoa n)
 ": " (cdr (assoc 'pn inreg))
 ", " (cdr (assoc 'nf inreg))
 ". Varsta " (itoa (cdr (assoc 'v inreg)))
 )
 )
 (setq curent (cdr curent) ;urmatoarea �nregistrare
 n (1+ n)
 )
 )
 (princ) ) 