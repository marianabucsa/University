(defun C:PROIECT (/ set1 set2 set3 curent schimbat culoare)
  (setq set1 (ssget "X" '((0 . "CIRCLE") (-4 . "=") (40 . 1.0) ) ) )
  (setq set2 (ssget "X" '((0 . "LINE") (-4 ."<OR" ) (-4 . ">=") (40 . 3.0 ) (-4 . "<=") (40 . 5.0) (-4 . "OR>"))))
  (setq set3 (ssget "W" '(14.0 0.0 0.0) '(19.0 5.0 0.0)))
  (setq n 0)
  (repeat (sslength set1)
    	(setq
	  	curent (entget (ssname set1 n))
		schimbat (assoc 62 curent)
		culoare (cons 62 "red")
		curent (subst culoare schimbat curent)
		)
	(entmod curent)
	(setq n (+ 1 N))
  )
	 )
