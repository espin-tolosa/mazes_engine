#ifndef GRID_H
#define GRID_H

//TODO: Activate threshold, now is totally bugged

//X->
// 0 1 2 3 4 5 6 7
// 0 1 2 3 4 5
// 0 1 2 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7
// 0 1 2 3 4 5
// 0 1 2 3

//Member grid2D should be used as grid2D[y][x]
//other way to think about it is as row = y, col = x
#include <random>
#include <vector>
#include "MazeSeeker.h"

template <class T>
class Grid : public MazeSeeker<T> {

public:

  Grid() = delete;
  Grid(size_t Horizontal, size_t Vertical);
  void RandomizeCells();
  void DisplayGrid() const;
  void CreateMaze(const size_t& Init_X, const size_t& Init_Y);
  void CreateBFS(const size_t& Init_X, const size_t& Init_Y); //TODO: in process
  void Log_Cells_Visited() const;

protected:

  vector_Grid<T> &grid2D{this->m_Grid2D}; //Just an alias

  const size_t NX;
  const size_t NY;

};

template <class T>
Grid<T>::Grid(size_t Horizontal, size_t Vertical) : MazeSeeker<T>{Horizontal, Vertical}, NX{Horizontal}, NY{Vertical} { }


template <class T>
void Grid<T>::RandomizeCells() {
  for(size_t ht = 0; ht != grid2D.size(); ++ht )
    for(size_t vt = 0; vt != grid2D[ht].size(); ++vt)
      grid2D[ht][vt] = Zero<T>::RandomNumber(0,1);
}

template <class T>
void Grid<T>::DisplayGrid() const {
  std::cout << "Grid ------------------------------------" << std::endl;
  for(size_t ht = 0; ht != grid2D.size(); ++ht ) {
    for(size_t vt = 0; vt != grid2D[ht].size(); ++vt) {
      printf("%.6f ", grid2D[ht][vt]);
    }
    printf("\n");
  }
  std::cout << "-----------------------------------------" << std::endl;
}

template <class T>
void Grid<T>::CreateMaze(const size_t& x0, const size_t& y0) {

  auto cell = this->SetPosInCell(x0, y0);

  while(this->Get_Path_Memo_Size() != NX*NY) {
    auto cells = this->SeekAdjacentCells(cell.first, cell.second, 10.0);
    cell = this->PickACell(cells);
  }
}

template <class T>
void Grid<T>::CreateBFS(const size_t& x0, const size_t& y0) {
}

#endif
