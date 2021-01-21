#ifndef PATH_FINDER_ALGO_H
#define PATH_FINDER_ALHO_H

//tags: Path finding algorithms libray with input-out to bmp file

// Forward:
//  start at (0,0) go in an kind of blindness fashion way till the end, avoiding higher costs on the fly

// Backward:
//  start at (end,end) and go to the begining. Since all the information of cost propagates downstream
//  any decision has all cost warrantized so this is the true minimum cost path in global sense.

// Gradient
//  a little mess attempt to implement movement in the gradient direction movement, but it doesn't work
//  TODO: implement a real gradient computation algorithm

//1. Start traversing the matrix from (0,0) and store sum of values along the path
//2. Handle boundary cells
//3. Any interior cell has two choices (one from left, one from north)
//4. Store all sums in a dic?
#include<iostream>
#include <vector>
#include<functional>
#include <math.h>
#include "PathFinder.h"
#include "mandelbrot.h"
#include "random.h"


#endif
