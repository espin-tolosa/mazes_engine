#ifndef PATH_FINDER_H
#define PATH_FINDER_H

//tags: Choose minimum cost path under: the player only see the next contiguous cells, can't go backward
//tags: Most basic path way choosing
//tags: usefull to model behaviour of materials as sand or water
//targs: Forward vs Backward

// Forward:
//  start at (0,0) go in an kind of blindness fashion way till the end, avoiding higher costs on the fly

// Backward:
//  start at (end,end) and go to the begining. Since all the information of cost propagates downstream
//  any decision has all cost warrantized so this is the true minimum cost path in global sense.

//1. Start traversing the matrix from (0,0) and store sum of values along the path
//2. Handle boundary cells
//3. Any interior cell has two choices (one from left, one from north)
//4. Store all sums in a dic?
#include <vector>
#include <inttypes.h>

namespace set {

class PathFinder {
public:

std::pair< std::vector<size_t>, std::vector<size_t> > Gradient_Descend(const std::vector< std::vector<uint32_t> >& Grid);
  std::pair< std::vector<size_t>, std::vector<size_t> > Minimum_Cost_Forward(const std::vector< std::vector<uint32_t> >& Grid);
  std::pair< std::vector<size_t>, std::vector<size_t> > Minimum_Cost_Backward(const std::vector< std::vector<uint32_t> >& Grid);

private:

};

}

#endif //path
