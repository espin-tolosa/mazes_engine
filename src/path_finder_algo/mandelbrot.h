#ifndef MANDELBROT_H
#define MANDELBROT_H

inline double clamp(float x);
inline int toInt(double x);
int mandelbrot ( float x, float y, uint32_t w, uint32_t h);

#endif
