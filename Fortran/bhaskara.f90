PROGRAM BHASKARA
    
    IMPLICIT NONE

    REAL :: A, B, C, DELTA, X1, X2

    PRINT *, 'QUAL O VALOR DE A?'
    READ *, A
    PRINT *, 'QUAL O VALOR DE B?'
    READ *, B
    PRINT *, 'QUAL O VALOR DE C?'
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