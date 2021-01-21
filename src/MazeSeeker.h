#ifndef MAZE_SEEKER_H
#define MAZE_SEELER_H

//tags: available cells to move in a grid
#include <vector>
#include "Memory.h"

template <class T>
class MazeSeeker : public Memo_String<T> {

public:

  MazeSeeker() = delete;
  MazeSeeker(size_t Horizontal, size_t Vertical);

  pair_size_t SetPosInCell(const size_t& x, const size_t& y);
  pair_vector_size_t SeekAdjacentCells(size_t x, size_t y, T Threshold);
  pair_size_t PickACell(pair_vector_size_t cells_index);

protected:

  vector_Grid<T> m_Grid2D;
  size_t orderer_counter{0};

};

template <class T>
MazeSeeker<T>::MazeSeeker(size_t Horizontal, size_t Vertical)
  : m_Grid2D{ vector_Grid<T>(Vertical, std::vector<T>(Horizontal, Zero<T>::Zero::Get())) } { }

template <class T>
pair_size_t MazeSeeker<T>::SetPosInCell(const size_t& x, const size_t& y) {
  pair_size_t p(x, y);
  this->Add_Stack(p.first, p.second);
  this->Insert_Path_Memo(p.first, p.second, orderer_counter++);
  return p;
}

template <class T>
pair_vector_size_t MazeSeeker<T>::SeekAdjacentCells(size_t x, size_t y, T Threshold) {

  T *North{nullptr}, *South{nullptr}, *East{nullptr}, *West{nullptr};
  std::vector<size_t> Coordinates_X;
  std::vector<size_t> Coordinates_Y;

  Coordinates_X.reserve(4);
  Coordinates_Y.reserve(4);

  auto push_coord = [&Coordinates_X, &Coordinates_Y](size_t x, size_t y)
  {
    Coordinates_X.push_back(x);
    Coordinates_Y.push_back(y);
  };

  if(x > 0) {
    East = &m_Grid2D[y][x-1];
    if(*East < Threshold && !this->Find(x-1,y)) {
      push_coord(x-1,y);
    }
  }

  if(x < m_Grid2D[y].size()-1) {
    West = &m_Grid2D[y][x+1];
    if(*West < Threshold && !this->Find(x+1,y)) {
      push_coord(x+1,y);
    }
  }

  if(y != 0 && m_Grid2D[y-1].size()-1 >= x) {
    North = &m_Grid2D[y-1][x];
    if(*North < Threshold && !this->Find(x,y-1)) {
      push_coord(x,y-1);
    }
  }

  if(y < m_Grid2D.size()-1 && m_Grid2D[y+1].size()-1 >= x) {
    South = &m_Grid2D[y+1][x];
    if(*South < Threshold && !this->Find(x,y+1)) {
      push_coord(x,y+1);
    }
  }

  //if(North != nullptr) std::cout << "North " << *North << std::endl;
  //if(South != nullptr) std::cout << "South " << *South << std::endl;
  //if(East  != nullptr) std::cout << "East  " << *East  << std::endl;
  //if(West  != nullptr) std::cout << "West  " << *West  << std::endl;

  pair_vector_size_t Coordinates(Coordinates_X, Coordinates_Y);
  return Coordinates;
}



template <class T>
pair_size_t MazeSeeker<T>::PickACell(pair_vector_size_t cells_index) {
  //cells_index.first.size() == cells_index.second.size() = true; Warrantied by SeekAdjacentCells

  while(cells_index.first.size() == 0) {
    auto prev_step = this->Pop_Stack();
    cells_index = SeekAdjacentCells(prev_step.first, prev_step.second, 10.0);
  }

  //TODO: create a independent function for this random method
  std::default_random_engine e1(global());
  std::uniform_int_distribution<int> uniform_dist(0, cells_index.first.size()-1 );
  size_t mean = static_cast<size_t>(uniform_dist(e1));

  pair_size_t p(cells_index.first[mean], cells_index.second[mean]);

//  this->Insert(p.first, p.second, grid2D[p.second][p.first]);
  this->Add_Stack(p.first, p.second);
  this->Insert_Path_Memo(p.first, p.second, orderer_counter++);
  return p;
}
#endif
