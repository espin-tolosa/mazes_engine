#ifndef RANDOM_H
#define RANDOM_H

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//srand (time(NULL));

int getRandInBetween(int min, int max) {
  return rand() % (max-min) + min;
}


#endif


