PROGRAM BHASKARA
    
    IMPLICIT NONE

    REAL(16) :: A, B, C, DELTA, X1, X2

    READ *, A
    READ *, B
    READ *, C

    DELTA = (B * B) - 4 * A * C
    IF ( DELTA.LT.0 ) THEN
        PRINT *, 'RAIZ NAO POSSUI SOLUCAO REAL'
    ELSE
        DELTA = SQRT(DELTA)
        X1 = (-B + DELTA) / 2 * A
        X2 = (-B - DELTA) / 2 * A
        WRITE (*, *) 'AS RAIZES DE SUA FUNCAO SAO: ', X1, ' E ', X2
    END IF


END PROGRAM BHASKARA