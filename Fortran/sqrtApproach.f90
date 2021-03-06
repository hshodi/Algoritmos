PROGRAM SQRT_APPROACH

    IMPLICIT NONE
    REAL(16) :: VALUE, X1, X2

    READ *, VALUE
    
    IF (VALUE.EQ.0) THEN
        X1 = 0  
        GOTO 200
    END IF

    IF ( VALUE.LT.0 ) THEN
        WRITE (*, *) 'NAO POSSUI SOLUCAO REAL'
        GOTO 300
    END IF
    
    X1 = (VALUE + (VALUE / VALUE)) / 2
    
100 X2 = (X1 + (VALUE / X1)) / 2
    IF ( .NOT.( X1.EQ.X2 ) ) THEN
        X1 = (X2 + (VALUE / X2)) / 2
        GOTO 100
    ELSE
        GOTO 200
    END IF

200 WRITE (*, *) 'O RESULTADO APROXIMADO DA RAIZ E:', X1


300 END PROGRAM SQRT_APPROACH