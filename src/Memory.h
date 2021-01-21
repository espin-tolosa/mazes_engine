#ifndef MEMO_STRING_H
#define MEMO_STRING_H

#include <string>
#include <stack>
#include <map>
#include <unordered_map>

typedef std::pair<std::vector<size_t>, std::vector<size_t> > pair_vector_size_t;
typedef std::pair<size_t, size_t > pair_size_t;

template <class T>
using vector_Grid = std::vector< std::vector<T> >;

template <class T>
class Memo_String {

public:
  void Insert_Path_Memo(std::string cell, size_t counter) {
    m_path_memo.insert(std::make_pair(cell, counter));
  }

  void Insert_Path_Memo(size_t x, size_t y, size_t counter) {
    std::string cell = std::to_string(x) + " " +  std::to_string(y);
    Insert_Path_Memo(cell, counter);
  }

  void Add_Stack(std::string cell) {
    m_steps.push(cell);
  }

  void Add_Stack(size_t x, size_t y) {
    std::string cell = std::to_string(x) + " " +  std::to_string(y);
    Add_Stack(cell);
  }

  bool Stack_Is_Empty() const {
    return (m_steps.size() == 0);
  }

  //calling this function whitout before checking Stack_Is_Empty()
  //may cause a run-time error. TODO: add a flag in between both
  std::pair<size_t, size_t> Pop_Stack() {
    std::string cell = m_steps.top();
    m_steps.pop();
    return Parse_Cell_String(cell);
  }

  std::pair<size_t, size_t> Parse_Cell_String(const std::string& cell) const {
    size_t x = static_cast<size_t>(std::stoi(cell.substr(0, cell.find(" "))));
    size_t y = static_cast<size_t>(std::stoi(cell.substr(cell.find(" ")+1, cell.size())));

    return std::make_pair(x,y);
}

  bool Find(const std::string& cell) {
    if(m_path_memo.find(cell) != m_path_memo.end())
      return true;
    else
      return false;
  }

  bool Find(size_t x, size_t y) {
    std::string cell = std::to_string(x) + " " +  std::to_string(y);
    return Find(cell);
  }

  size_t Get_Path_Memo_Size() const {
    return m_path_memo.size();
  }

  size_t Get_Stack_Size() const {
    return m_steps.size();
  }

  void Log_Memo() const {
    for(auto it = m_path_memo.begin(); it != m_path_memo.end(); ++it)
      std::cout << it->first << " " << it->second << std::endl;
  }

  void Log_Path_Memo() const {
    for(auto it = m_path_memo.begin(); it != m_path_memo.end(); ++it) {
      std::cout << it->first << " : " << it->second << std::endl;
    }
  }

  void Sort_Path_Memo() {
    for(auto it = m_path_memo.begin(); it != m_path_memo.end(); ++it) {
      sorted_post_processed_steps.insert(std::make_pair(it->second, it->first));
    }
  }

  void Log_Sorted_Path_Memo() const {
    for(auto it = sorted_post_processed_steps.begin(); it != sorted_post_processed_steps.end(); ++it)
      std::cout << "Step: " << it->first << ":\t" << it->second << std::endl;
  }

  std::pair<size_t, size_t> Get_Step(size_t step) const {
    auto it = sorted_post_processed_steps.find(step);
    return Parse_Cell_String( it->second );
  }
/*
  void Log_Sort_Path_Pop() {
    std::map<size_t, std::string> sorted_post_processed_steps;
    while(m_steps.size() != 0) {
      auto it = m_path_memo.find(m_steps.top());
      sorted_post_processed_steps.insert(std::make_pair(it->second, it->first));
      m_steps.pop();
    }

    for(auto it = sorted_post_processed_steps.begin(); it != sorted_post_processed_steps.end(); ++it)
      std::cout << "Step: " << it->first << ": " << it->second << std::endl;
  }
*/

/*
  void Log_Size_Memo() const {
    std::cout << "Memo size: " << m_memo.size() << std::endl;
  }
*/
protected:
  //std::unordered_map<std::string, T> m_memo;
  std::stack<std::string> m_steps;
  std::map<size_t, std::string> sorted_post_processed_steps;
  std::unordered_map<std::string, size_t> m_path_memo;

};
#endif
