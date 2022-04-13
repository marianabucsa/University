; 15. Sa se construiasca lista nodurilor unui arbore de tipul (1) parcurs in postordine.

; l = lista de tipul 1 a nodurilor
; m = nr de muchii
; v = nr de varfuri
; s = subarborii rezultati 
(defun detSubarbori(l m v s)
    (cond 
        ((or (= v (+ m 1)) (null l)) (list s l))
        (t (detSubarbori (cddr l) (+ m (cadr l)) (+ v 1) (append s (list (car l) (cadr l)))))
    )
)

; l = lista de tipul 1 a nodurilor 
(defun postordine(l)
     (cond
        ((null l) nil)
        (t (append (postordine (car (detSubarbori (cddr l) 0 0 nil))) (postordine(cadr (detSubarbori (cddr l) 0 0 nil))) (list (car l))))
    )
)