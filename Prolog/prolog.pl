factorial(0, 1).
factorial(N, F) :- 
    N > 0,
    M is N - 1,
    factorial(M, R),
    F is N * R.
potencia(_, 0, 1).
potencia(B, N, P) :- 
    N > 0,
    M is N - 1,
    potencia(B, M, R),
    P is B * R.

mult(0, _, 0).
mult(_, 0, 0).
mult(X, Y, Z) :- 
    Y > 0,
    M is Y - 1,
    mult(X, M, R),
    Z is R + X.

div(_, 0, "Infinito").
div(0, _, 0).
div(X, 1, X).
div(X, Y, Z) :-
    (Y > X, Z is 0);
    X > 0,
    A is X - Y,
    div(A, Y, R),
    Z is R + 1.

bin(1) :- write(1).
bin(X) :-
    C is X mod 2,
    Z is X - C,
    Y is Z / 2,
    bin(Y), write(C).

fibonacci(0, 0).
fibonacci(1, 1).
fibonacci(X, R) :- 
    X > 0,
    Z is X - 1,
    Y is X - 2,
    fibonacci(Z, A),
    fibonacci(Y, A),
    R is A + B.
   
membro(X, [X|_]).
membro(X, [_|R]) :- membro(X, R).

append([], B, B).
append([X|Y], B, [X|C]) :- append(Y, B, C).