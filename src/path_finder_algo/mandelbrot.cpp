#include <iostream>
#include <algorithm>
#include <math.h>
#include <complex>
#include <stdlib.h> // printf, scanf, puts, NULL
#include <time.h>

#include "mandelbrot.h"



double clamp(float x){ return x<0 ? 0 : x>255 ? 1 : x; }
int toInt(double x){ return int(pow(clamp(x),1/2.2)*255+.5); }
int mandelbrot ( float x, float y, uint32_t w, uint32_t h)  {

    const int MAX_ITERATIONS = 300;

    std::complex<float> point(x, y);
    std::complex<float> z(0.0f, 0.0f);

    uint32_t iterations = 0;
    while (abs (z) < 2 && iterations <= MAX_ITERATIONS) {
           z = z * z + point;
           iterations++;
    }

    if (iterations < MAX_ITERATIONS) return (iterations);
    else return 0;
}
