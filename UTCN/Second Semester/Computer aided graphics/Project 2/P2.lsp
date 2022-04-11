(defun C:PROIECT (/ set1 set2 set3 set4 curent deschimbat culoare inaltime punctstart n )
  ; creeaza un set de selectie ce contine cercuri cu raza >= 1
  (setq set1 (ssget "X" '((0 . "CIRCLE") (-4 . ">=") (40 . 1.0) ) ) )
  ; creeaza un set de selectie ce contine cercuri cu raza < 1
  (setq set2 (ssget "X" '((0 . "CIRCLE") (-4 . "<") (40 . 1.0) ) ) )
  ; creeaza un set de selectie cu entitatile de tip text sau mtext
   (setq set3 (ssget "X" (list '(-4 . "<OR") '(0 . "TEXT") '(0 . "MTEXT") '(-4 . "OR>"))))
  ; creeaza un set de selectie ce contine linii aflate intre laturile patratului cu colturile (0,0) si (10,10)
  (setq set4 (ssget "W" '(0 0 0) '(10.0 10.0 0) (list '(-4 . "<OR") '(0 . "LWPOLYLINE") '(0 . "LINE") '(-4 . "OR>"))))
  ;; MODIFICAREA SETULUI 1
  ; seteaza n=0
  (setq n 0)
  ; o structura repetitiva ce parcurge setul de selectie (se doreste schimbarea culorii liniilor)
  (repeat (sslength set1)
    	(setq
	  ; preia entitatea cu nr n din setul de selectie in variabila curent
	  	curent (entget (ssname set1 n))
	  ; cauta cheia 62 in lista si returneaza lista care il contine
		deschimbat (assoc 62 curent)
	  ; memoreaza in variabila culoare o lista cu punct formata din elementul 62 (cheia) si 1 (codul culorii)
		culoare (cons 62 1)
	  ; schimba in entitatea curenta lista "deschimbat" cu lista "culoare"
		curent (subst culoare deschimbat curent)
		)
    ;actualizeaza lista entitatii
	(entmod curent)
    ; n trece in n+1 (se parcurge mai departe setul de selectie)
	(setq n (+ 1 n))
  )
  ;; MODIFICAREA SETULUI 2
  ; structura repetitiva are acelasi rezultat pentru un alt set de selectie
   (setq n 0)
  (repeat (sslength set2)
    	(setq
	  	curent (entget (ssname set2 n))
		deschimbat (assoc 62 curent)
		culoare (cons 62 2)
		curent (subst culoare deschimbat curent)
		)
	(entmod curent)
	(setq n (+ 1 n))
  )
  ;; MODIFICAREA SETULUI 3
  ; o structura repetitiva ce parcurge setul de selectie (se doreste schimbarea inaltimii textelor)
 (setq n 0)
 (repeat (sslength set3)
 (setq

 	curent (entget (ssname set3 n))
	deschimbat (assoc 40 curent)
  	inaltime (cons 40 1.5)
	curent (subst inaltime deschimbat curent)
 )
 (entmod curent) 
 (setq n (1+ n)) 
 )
 ;; MODIFICAREA SETULUI 4
 ; o structura repetitiva ce parcurge setul de selectie (se doreste schimbarea punctului de start al liniilor)
  (setq n 0)
 (repeat (sslength set4)
 (setq

 	curent (entget (ssname set4 n))
	deschimbat (assoc 10 curent)
  	punctstart (cons 10 '(5 5 0))
	curent (subst punctstart deschimbat curent)
 )
 (entmod curent) 
 (setq n (1+ n)) 
 )
;CREAREA ENTITATII
; se creeaza o entitate
  (entmake '(
  		(0 . "MTEXT") ; tipul entitatii (MTEXT)
 		(100 . "AcDbEntity")  
 		(8 . "0")	; layerul in care se afla
 		(100 . "AcDbMText")    
 		(10 22.0 2.5 0.0) ; punctul de start al textului
 		(1 . "GAC") ; string-ul afisat
 		(40 . 1.5) ; inaltimea string-ului
		 )
	)
 
)