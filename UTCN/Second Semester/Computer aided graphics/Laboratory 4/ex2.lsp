( defun deg2rad ( deg / rad )
  ( setq rad ( * deg pi) )
  ( / rad 180 )
  )
( defun rad2deg ( rad / deg )
  ( setq deg ( * rad 180 ) )
  ( setq deg (/ deg pi ) )
  ( fix deg )
  )