; 10.Definiti o functie care determina numarul de noduri de pe nivelul k dintr-un arbore n-ar reprezentat sub forma (radacina lista_noduri_subarb1 ... lista_noduri_subarbn) Ex: arborelele este (a (b (c)) (d) (e (f))) si k=1 => 3 noduri

; l = arborele reprezentat sub forma de lista
; k = nivelul pentru care se cere nr de noduri

(defun nr_noduri_nivel(l k)
    (cond
        ((and (atom l) (= k -1)) 1)
        ((atom l) 0)
        (t (apply #'+ (mapcar #'(lambda(l)
                                    (nr_noduri_nivel l (- k 1))
                                )
                                l)))
    )
)

(defun substituie_nivel_impar(l k e i)
    (cond
        ((and (equal l e) (oddp k))  i)
        ((atom l) l)
        (t (mapcar #'(lambda(lst)
                        (substituie_nivel_impar lst (+ k 1) e i)
                     )
                     l))
    )
)

(defun substituie(l e i)
	(substituie_nivel_impar l '1 e i)) 