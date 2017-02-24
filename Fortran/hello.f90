PROGRAM shodi
    IMPLICIT NONE
    character(40) :: myname
    Print *, "Whats is your name?"

    Read *, myname

    Print *, "Hello "//trim(myname)

END PROGRAM shodi
