// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair

#include "Collatz.h"

// ------------
// collatz_read
// ------------

std::pair<int, int> collatz_read (std::istream& r) {
    int i;
    r >> i;
    if (!r)
        return std::make_pair(0, 0);
    int j;
    r >> j;
    return std::make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
    if (i > j){
        int sub = i;
        i = j;
        j = sub;
    }
    int max_cycle = 1;
    int cycle = 1;
    int num_iteration = j - i +1;
    for(int k = i; k <= num_iteration; k++){
        while(k > 1){
            if((k % 2) == 0)
                k = (k / 2);
            else
                k = (3 * k) + 1;
            ++cycle;
        }
        if(cycle > max_cycle)
            max_cycle = cycle;
    }
    return max_cycle;
    // while(i != j){
    //     int k = i;
    //     if((k % 2) == 0)
    //         k = k/2;
    //     else 
    //         k = (3 * k) +1;
    //     ++cycle;
    //     ++i;
    //     if(cycle > max_cycle)
    //         max_cycle = cycle;
    // }
}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    while (true) {
        const std::pair<int, int> p = collatz_read(r);
        if (p == std::make_pair(0, 0))
            return;
        const int v = collatz_eval(p.first, p.second);
        collatz_print(w, p.first, p.second, v);}}
