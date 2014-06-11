// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// -------------------------------

/*
To compile the program:
    % g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz

To run the program:
    % valgrind RunCollatz < RunCollatz.in

To obtain coverage of the run:
    % gcov-4.7 -b Collatz.c++ RunCollatz.c++

To configure Doxygen:
    % doxygen -g
    That creates the file "Doxyfile".
    Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    % doxygen Doxyfile
*/

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream> // cin, cout

#include "Collatz.h"

// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}

/*
% g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz



% valgrind RunCollatz < RunCollatz.in > RunCollatz.out
==17119== Memcheck, a memory error detector
==17119== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==17119== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==17119== Command: RunCollatz
==17119==
==17119==
==17119== HEAP SUMMARY:
==17119==     in use at exit: 0 bytes in 0 blocks
==17119==   total heap usage: 2 allocs, 2 frees, 1,136 bytes allocated
==17119==
==17119== All heap blocks were freed -- no leaks are possible
==17119==
==17119== For counts of detected and suppressed errors, rerun with: -v
==17119== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)



% gcov-4.7 -b Collatz.c++
File 'Collatz.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Collatz.c++.gcov'
...



% cat Collatz.c++.gcov
...



% gcov-4.7 -b RunCollatz.c++
File 'RunCollatz.c++'
Lines executed:100.00% of 3
Branches executed:100.00% of 4
Taken at least once:50.00% of 4
Calls executed:100.00% of 2
Creating 'RunCollatz.c++.gcov'
...



% cat RunCollatz.c++.gcov
...
*/
