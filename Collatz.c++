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

int cache [1000000] = { 0 };
int collatz_eval (int i, int j) {
    // <your code>
    assert(i > 0);
    assert(j > 0);

     if (i > j){
         int sub = i;
         i = j;
         j = sub;
     }
    int max_cycle = 1;
    int k = i; 

    while(k <= j){
        int h = k;
        if(cache[k] != 0)
            return cache[k];
        else{
            int cycle = 1;
            while(h > 1){
                if((h % 2) == 0)
                    h = (h / 2);
                else
                    h = (3 * h) + 1;
                ++cycle;
            }
            if(cycle > max_cycle){
                max_cycle = cycle;
                cache[k] = max_cycle;
            }
                
            ++k;
            h = k;   
        }
    }
    assert(max_cycle > 0);
    return max_cycle;
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
