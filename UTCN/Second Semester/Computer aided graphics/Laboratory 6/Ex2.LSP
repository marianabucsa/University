;;; spiral.lsp/c:spiral
;;;
;;;deseanza o spirala formata din puncte , egal departate unul de
;;;celalalt.Spirala poate fi creata in sensul acelor de ceasornic
;;;sau in sens trigonometric, pornind cu o raza initiala care se
;;;mareste uniform cu fiecare rotatie conform unui increment
;;;specificat.spirala prezinta un centru de rotattie si ;;;contine un
;;;numar finit de puncte.
(defun C:SPIRAL ( / center radius rinc delta points direction
 distprompts distances angoffset FULLCIRCLE
 cmdecho_store)
 ; constante
 (setq FULLCIRCLE (* 2 pi))

 ; obtinerea caracteristicilor spiralei
 ; centrul
 (setq center (getpoint "centrul spiralei: "))

 ; deoarece obtinerea distantelor se realizeaza similar
 ;citirea lor se realizeaza într-o bucla
 (setq distprompts '("\nraza initiala: "
 "\nincrementul razei la o rotatie completa: "
 "\ndistanta dintre puncte consecutive:"
 )
 distances nil)
 (while distprompts ;pana cand se afiseaza toate solicitarile la
 ;prompt
 (initget 7) ; permite citirea de valori pozitive
 ;plaseaza distanta citita în capul listei
 (setq distances (cons (getdist (car distprompts)) distances)
 distprompts (cdr distprompts) ; next
 )
 )
  ;lista de distante arata astfel:
 ; (dist_puncte increment_raza raza_initiala)
 ; folosirea lui (cons),face ca valorile sa fie in ordine inversa fata
 ; de citirea lor de la tastatura
 (setq radius (caddr distances)
 rinc (cadr distances)
 delta (car distances)
 )
 ; nr de puncte ale spiralei
 (initget 7)
 (setq points (getint "\nNumber of points on the spiral: "))
 ;directia spiralei
 (initget 1 "Clockwise counteRclockwise")
 (setq direction (getkword "\nSpiral direction (Clockwise
counteRclockwise): "))

 ;pastrarea setarilor de mediu curente si modificarea lor
 (setq cmdecho_store (getvar "CMDECHO"))
 (setvar "CMDECHO" 0) ;fara ecoul comenzilor
 (setvar "PDMODE" 33) ;punctele vor fi reprezentate ca cercuri
 ; desenarea
 (setq ang 0) ; vom porni sub un unghi egal cu 0
 (while (/= points 0)
 ; plasarea punctului conform orientarii dorite si a razei fata de
 ;centrul specificat
 (command "point" (polar center ang radius))
 ; distanta dintre puncte (lungime de arc) trebuie
 ; sa fie constanta, de aceea trebuie ca raza sa fie luata in
 ;considerare cand se modifica unghiul
 (setq angoffset (/ delta radius)
 ang (if (= direction "Clockwise") (- ang angoffset)
 (+ ang angoffset))
 )
 ;limitare intre [0, 2pi)
 (if (< ang 0) (setq ang (+ ang FULLCIRCLE)))
 (if (>= ang FULLCIRCLE) (setq ang (- ang FULLCIRCLE)))
 ;creste raya cu un procent din incrementul prestabilit al razei
 ;conform unghiului la care a fost plasat punctul pe spirala
 (setq radius (+ radius (* rinc (/ angoffset FULLCIRCLE)))
 points (1- points)
 )
 ) ;
 (setvar "CMDECHO" cmdecho_store)

 (princ) ; anuleaza returnarea rezultatului
 ) ; C:SPIRAL