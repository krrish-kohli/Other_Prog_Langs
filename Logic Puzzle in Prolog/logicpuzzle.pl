% CECS 342 Assignment 3
% Logic Puzzle
% Solution Template: >>> Please fill in the missing code! <<<
%
% Each person reported a "UFO" sighting on a different day of the week.
%
% How to run this:
% ?- solve.

% Chronoligical order of weekdays
earlier(A, B) :-
  append(Earlier, Later, ['Tuesday', 'Wednesday', 'Thursday', 'Friday']),
  member(A, Earlier), member(B, Later), !.

% Frisbee person cannot be Ms. Gort
not_gort('Mr. Klaatu').
not_gort('Ms. Barada').
not_gort('Mr. Nikto').

% Nikto can only be Wed, Thu, or Fri
nikto_day('Wednesday').
nikto_day('Thursday').
nikto_day('Friday').

% Klaatu's object cannot be the water tower
klaatu_object(balloon).
klaatu_object(frisbee).
klaatu_object(clothesline).

% Friday must be Ms. Barada OR clothesline
friday_ok(Events) :-
    member(('Ms. Barada', _, 'Friday'), Events).
friday_ok(Events) :-
    member((_, clothesline, 'Friday'), Events).
  
% Solve the puzzle.
solve :-
  % Each event is represented by a triple of the form
  % (Person, Object, Day) in a list of events:
  Events = [
    ('Ms. Gort',   _, _        ),
    ('Mr. Klaatu', _, KlaatuDay),
    ('Ms. Barada', _, _        ),
    ('Mr. Nikto',  _, _        )
  ],

  member((_, balloon,     BalloonDay ), Events),
  member((_, clothesline, _         ), Events),
  member((_, frisbee,     FrisbeeDay), Events),
  member((_, watertower,  _         ), Events),

  member((_, _, 'Tuesday'),   Events),
  member((_, _, 'Wednesday'), Events),
  member((_, _, 'Thursday'),  Events),
  member((_, _, 'Friday'),    Events),

  % 1. Mr. Klatu made his sighting at some point earlier in the week
  %    than the one who saw the balloon, but at some point later in the week
  %    than the one who spotted the Frisbee (who isn't Ms. Gort).

  member((FrisbeePerson, frisbee, FrisbeeDay), Events),
  earlier(KlaatuDay, BalloonDay),
  earlier(FrisbeeDay, KlaatuDay),
  not_gort(FrisbeePerson),
      
  % 2. Friday's sighting was made by either Ms. Barada
  %    or the one who saw the clothesline or both.

  friday_ok(Events),      
      
  % 3. Mr. Nikto did not make his sighting on Tuesday.
  
  member(('Mr. Nikto', _, NiktoDay), Events),
  nikto_day(NiktoDay),
      
  % 4. Mr. Klatu isn't the one whose object turned out to be a water tower.
  
  member(('Mr. Klaatu', KlaatuObject, KlaatuDay), Events),
  klaatu_object(KlaatuObject),      
      
  % Display a solution: An English sentence for each event.
  forall(member(T, Events), report(T)).

% Write out an English sentence for an event.
report((Who, What, When)) :-
  write(Who), write(' saw the '), write(What),
  write(' on '), write(When), write('.'), nl.
