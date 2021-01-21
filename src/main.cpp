//tags:

#include<iostream>
#include <vector>
#include<functional>
#include <random>

#include "Zero.h"
#include "Grid.h"

#include "bmp_image/BMP.h"
#include "path_finder_algo/PathFinderAlgo.h" //TODO: still to polish the class


//#include "PathFinder.h"
//#include "mandelbrot.h"
//#include "random.h"
//#include <math.h>

//define working type once for all
typedef double type;

int main(int argc, char** argv)
{
  //TODO: For some reason I can't draw images below 16x16 pixels
  //GRID
  const size_t NX = 5;
  const size_t NY = 5;
  const uint32_t NX_BMP = 16;
  const uint32_t NY_BMP = 16;

  Grid<type> grid(NX,NY);
  grid.RandomizeCells();
  grid.CreateMaze(2,2); 
  grid.Sort_Path_Memo();
  grid.DisplayGrid();
  grid.Log_Sorted_Path_Memo();

  //BMP
  std::string inputFile{argv[1]};
  std::string format{".bmp"};
//  set::Bitmap myBitmap(static_cast<uint32_t>(NX),static_cast<uint32_t>(NY));
  set::Bitmap myBitmap(NX_BMP, NY_BMP);


  uint8_t color{255};

  for(size_t i = 0; i != NX*NY; ++i) {
    auto step = grid.Get_Step(i);
    myBitmap.SetPixel(static_cast<int32_t>(step.first), static_cast<int32_t>(step.second), --color % 255, 100, 100);

    std::string outputFile{inputFile};
    myBitmap.Write(outputFile.append("out").append(format)+"."+std::to_string(i));

  }
  
//    std::string outputFile{inputFile};
//    myBitmap.Write(outputFile.append("out").append(format));

}









