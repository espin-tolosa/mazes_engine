#ifndef ZERO_H
#define ZERO_H
#include <typeinfo>

//TODO: Zero class has to mute to something bigger, I'll need return some features like:
//
//  return Random type T
//  return Zero
//  return One
//  ...

//TODO: classes suportedby now
const std::type_info& type_int = typeid(int);
const std::type_info& type_uint = typeid(unsigned int);
const std::type_info& type_float = typeid(float);
const std::type_info& type_double = typeid(double);
const std::type_info& type_string = typeid(std::string);

const std::string name_int = typeid(int).name();
const std::string name_uint = typeid(unsigned int).name();
const std::string name_float = typeid(float).name();
const std::string name_double = typeid(double).name();
const std::string name_string = typeid(std::string).name();

//TODO: I know branching type could be done with enum or binds tuple but I don't still know how
//enum types {type_int, type_uint, type_float, type_double, type_string};

template <class T>
class Zero {

//TODO: use move-semantics or whatever to call constructor implicitly, I want something like Zero::Zero<int>()

public:

  Zero() : m_zero{} { } //m_zero{} call default constructor of the type class T

  static T Get() {
    Zero<T> z;
    return z();
  }

  static T One() { //TODO: One isn't defined in classes like std::string, for sure this is only valir for decimal primitive types
    return static_cast<T>(1);
  }

  static T Random() {

    T value;
    return value;
/*    Zero<T> z;
    std::string name_class = typeid(z.m_zero).name();
    T value;
    if(name_class == name_string)
    {
      std::cout << "Random STRING Still not implemented!!!" << std::endl;
      value = std::string{"NotRandomString"};
    }
    else
    {
      std::cout << "DECIMAL PRIMITIVES AND ALL OTHER STUFF HERE" << std::endl;
      value = 0;
    }

    return value;
    
   // return static_cast<T>(1);
  }
*/
  T operator()(){
    return m_zero;

  }

private:
  
  T m_zero;
};

#endif
