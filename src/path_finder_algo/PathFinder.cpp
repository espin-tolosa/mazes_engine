#include "PathFinder.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

namespace set {

std::pair< std::vector<size_t>, std::vector<size_t> > PathFinder::Gradient_Descend(const std::vector< std::vector<uint32_t> >& Grid) {

    //Compute the minimum cost grid
    const size_t size_x = Grid.size();
    const size_t size_y = Grid[0].size();

    //Choose the minimum cost path (very archaic way)
    size_t i = -100+size_x/2;
    size_t j = 100+size_y/2;

    std::vector<size_t> path_x;
    std::vector<size_t> path_y;
    path_x.push_back(i);
    path_y.push_back(j);

    size_t i0 = i;
    size_t j0 = j;

//    while( (i%(size_x-50)) != 0 || (j%(size_y-50)) != 0) {
      int count{0};
    while(count != 150) {
      count++;
      i0 = i;
      j0 = j;

      //TODO: hacer una funcion para calcular los minimos que acepte pairs pero solo compare first
      //Input x1, x2, x3, x4 -> min(x1.first,x2.first,x3.first,x4.first)
      // si el resultado es por ejemplo x2, como x2 es un pair
      //facilmente extraigo el valor x2->second
      //Todo esto englobado en una clase que sera de calculos geometricos o algo asi

    int x = rand()%2;
    std::cout << x << std::endl;
    if(x) {
      if(Grid[i0-1][j0] <= Grid[i0+1][j0])
        i--;
      else
        i++;
    }
    else{
      if(Grid[i0][j0-1] <= Grid[i0][j0+1])
        j++;
      else
        j--;
    }
      path_x.push_back(i);
      path_y.push_back(j);
    }

      return std::pair< std::vector<std::size_t>, std::vector<std::size_t> >(path_x, path_y);
}

std::pair< std::vector<size_t>, std::vector<size_t> > PathFinder::Minimum_Cost_Forward(const std::vector< std::vector<uint32_t> >& Grid) {
    
    //Compute the minimum cost grid
    const size_t size_x = Grid.size();
    const size_t size_y = Grid[0].size();

    std::vector< std::vector <uint32_t> > Board(size_x, std::vector<uint32_t>(size_y, 0));
    
    Board[0][0] = 0;
    
    for(size_t i = 1; i != size_x; i++)
      Board[i][0] = Grid[i][0] + Board[i-1][0];

    for(size_t j = 1; j != size_y; j++)
      Board[0][j] = Grid[0][j] + Board[0][j-1];


    for(size_t i = 1; i != size_x; i++)
      for(size_t j = 1; j != size_y; j++)
        Board[i][j] = Grid[i][j] + (Board[i-1][j] < Board[i][j-1]? Board[i-1][j] : Board[i][j-1]);

    //Choose the minimum cost path (very archaic way)
    size_t i = 0;
    size_t j = 0;

    std::vector<size_t> path_x;
    std::vector<size_t> path_y;
    path_x.push_back(i);
    path_y.push_back(j);

    while(true) {
        if     (i+1 == size_x && j+1 != size_y) j++;
        else if(i+1 != size_x && j+1 == size_y) i++;
        else if(i+1 == size_x && j+1 == size_y) i+=0;
        else if(Board[i+1][j] < Board[i][j+1] ) {
          i++;
        }
        else {
          j++;
        }
        path_x.push_back(i);
        path_y.push_back(j);

        if((i == size_x-1) && (j == size_y-1)) {break;}
      }

    //Draw the solutions for Debugging purposes
    std::cout << "\n\nGRID------------------------\n" << std::endl;
    for(size_t i = 0; i != size_x; i++) {
      for(size_t j = 0; j != size_y; j++) {
        std::cout << Grid[i][j] << "\t" <<  std::flush;
      } std::cout << std::endl;
    }

    std::cout << "\n\nBOARD------------------------\n" << std::endl;
    for(size_t i = 0; i != size_x; i++) {
      for(size_t j = 0; j != size_y; j++) {
        std::cout << Board[i][j] << "\t" << std::flush;
      } std::cout << std::endl;
    }

      return std::pair< std::vector<std::size_t>, std::vector<std::size_t> >(path_x, path_y);
  }

std::pair< std::vector<size_t>, std::vector<size_t> > PathFinder::Minimum_Cost_Backward(const std::vector< std::vector<uint32_t> >& Grid) {
    
    //Compute the minimum cost grid
    const size_t size_x = Grid.size();
    const size_t size_y = Grid[0].size();

    std::vector< std::vector <uint32_t> > Board(size_x, std::vector<uint32_t>(size_y, 0));
    
    Board[0][0] = 0;
    
    for(size_t i = 1; i != size_x; i++)
      Board[i][0] = Grid[i][0] + Board[i-1][0];

    for(size_t j = 1; j != size_y; j++)
      Board[0][j] = Grid[0][j] + Board[0][j-1];


    for(size_t i = 1; i != size_x; i++)
      for(size_t j = 1; j != size_y; j++)
        Board[i][j] = Grid[i][j] + (Board[i-1][j] < Board[i][j-1]? Board[i-1][j] : Board[i][j-1]);

    //Choose the minimum cost path (very archaic way)
    size_t i = size_x-1 ;
    size_t j = size_y-1 ;

    std::vector<size_t> path_x;
    std::vector<size_t> path_y;
    path_x.push_back(i);
    path_y.push_back(j);

    while(true) {
        if     (i == 0 && j != 0) j--;
        else if(i != 0 && j == 0) i--;
        else if(i == 0 && j == 0) i+=0;
        else if(Board[i-1][j] < Board[i][j-1] ) {
          i--;
        }
        else {
          j--;
        }
        path_x.push_back(i);
        path_y.push_back(j);

        if((i == 0) && (j == 0)) {break;}
      }

    //Draw the solutions for Debugging purposes
/*    std::cout << "\n\nGRID------------------------\n" << std::endl;
    for(size_t i = 0; i != size_x; i++) {
      for(size_t j = 0; j != size_y; j++) {
        std::cout << Grid[i][j] << "\t" <<  std::flush;
      } std::cout << std::endl;
    }

    std::cout << "\n\nBOARD------------------------\n" << std::endl;
    for(size_t i = 0; i != size_x; i++) {
      for(size_t j = 0; j != size_y; j++) {
        std::cout << Board[i][j] << "\t" << std::flush;
      } std::cout << std::endl;
    }
*/
      return std::pair< std::vector<std::size_t>, std::vector<std::size_t> >(path_x, path_y);
}


} //namespace set
