// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------------

/*
Google Test Libraries:
    % ls -al /usr/include/gtest/
    ...
    gtest.h
    ...

    % locate libgtest.a
    /usr/lib/libgtest.a

    % locate libpthread.a
    /usr/lib/x86_64-linux-gnu/libpthread.a
    /usr/lib32/libpthread.a

    % locate libgtest_main.a
    /usr/lib/libgtest_main.a

To compile the test:
    % g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -lpthread

To run the test:
    % valgrind TestCollatz

To obtain coverage of the test:
    % gcov-4.7 -b Collatz.c++ TestCollatz.c++
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <utility>  // make_pair, pair

#include "gtest/gtest.h"

#include "Collatz.h"

// -----------
// TestCollatz
// -----------

// ----
// read
// ----

TEST(Collatz, read) {
    std::istringstream r("1 10\n");
    const std::pair<int, int> p = collatz_read(r);
    ASSERT_EQ( 1, p.first);
    ASSERT_EQ(10, p.second);}

// ----
// eval
// ----

TEST(Collatz, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(Collatz, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(Collatz, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(Collatz, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

// -----
// print
// -----

TEST(Collatz, print) {
    std::ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(Collatz, solve) {
    std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    std::ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

/*
% g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -lpthread



% valgrind TestCollatz
==17162== Memcheck, a memory error detector
==17162== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==17162== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==17162== Command: TestCollatz
==17162==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Collatz
[ RUN      ] Collatz.read
[       OK ] Collatz.read (30 ms)
[ RUN      ] Collatz.eval_1
TestCollatz.c++:67: Failure
Value of: v
  Actual: 1
Expected: 20
[  FAILED  ] Collatz.eval_1 (57 ms)
[ RUN      ] Collatz.eval_2
TestCollatz.c++:71: Failure
Value of: v
  Actual: 1
Expected: 125
[  FAILED  ] Collatz.eval_2 (6 ms)
[ RUN      ] Collatz.eval_3
TestCollatz.c++:75: Failure
Value of: v
  Actual: 1
Expected: 89
[  FAILED  ] Collatz.eval_3 (5 ms)
[ RUN      ] Collatz.eval_4
TestCollatz.c++:79: Failure
Value of: v
  Actual: 1
Expected: 174
[  FAILED  ] Collatz.eval_4 (5 ms)
[ RUN      ] Collatz.print
[       OK ] Collatz.print (12 ms)
[ RUN      ] Collatz.solve
TestCollatz.c++:98: Failure
Value of: w.str()
  Actual: "1 10 1\n100 200 1\n201 210 1\n900 1000 1\n"
Expected: "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n"
Which is: "1 10 20
100 200 125
201 210 89
900 1000 174
"
[  FAILED  ] Collatz.solve (22 ms)
[----------] 7 tests from Collatz (157 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (201 ms total)
[  PASSED  ] 2 tests.
[  FAILED  ] 5 tests, listed below:
[  FAILED  ] Collatz.eval_1
[  FAILED  ] Collatz.eval_2
[  FAILED  ] Collatz.eval_3
[  FAILED  ] Collatz.eval_4
[  FAILED  ] Collatz.solve

 5 FAILED TESTS
==17162==
==17162== HEAP SUMMARY:
==17162==     in use at exit: 0 bytes in 0 blocks
==17162==   total heap usage: 746 allocs, 746 frees, 115,424 bytes allocated
==17162==
==17162== All heap blocks were freed -- no leaks are possible
==17162==
==17162== For counts of detected and suppressed errors, rerun with: -v
==17162== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)



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



% gcov-4.7 -b TestCollatz.c++
File 'TestCollatz.c++'
Lines executed:100.00% of 26
Branches executed:83.93% of 224
Taken at least once:41.96% of 224
Calls executed:67.65% of 204
Creating 'TestCollatz.c++.gcov'
...



% cat TestCollatz.c++.gcov
...
*/
