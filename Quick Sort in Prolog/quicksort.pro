quicksort(nil, nil).
%   Uppercase variables, lowercase rest stuff
quicksort(cons(X, Xs)) :-
    partition(X, Xs, Lo, Hi),
    quicksort(Lo, SLo),
    quicksort(Hi, SHi),
    append(SLo, cons(X, SHi), S).

partition(X, nil, nil, nil).
partition(X, cons(Y, Ys), cons(X, Lo), Hi) :-
    leq(X, Y), partition(X, Ys, Lo, Hi).
partition(X, cons(Y, Ys), Lo, cons(X, Hi)) :-
    leq(Y, X), partition(X, Ys, Lo, Hi).

append(nil, Ys, Ys).
append(cons(X, Xs), Ys, cons(X, Zs)) :- append(Xs, Ys, Zs).

leq(X, X).
leq(X, Z) :- next(X, Y), leq(Y, Z).

next(a, b).
next(b, c).
next(c, d).