#ifndef ZERO_H
#define ZERO_H
#include <typeinfo>
#include <random>

//TODO: Zero class has to mute to something bigger, I'll need return some features like:
//
//  return Random type T
//  return Zero
//  return One
//  ...

//TODO: I need to define arrays or enums to pass specif type arguments to other functions, like this printf("%.2f", fNum);
//      this expects a double, but if my type T=int then I need to change to printf("%d", iNum); this is amazingly complicated

//TODO:define thread-safe global random generator: https://tbz533.blogspot.com/2019/05/a-thread-safe-global-random-number.html
inline static std::random_device global;


//std::random_device global;

const std::string name_int = typeid(int).name();
const std::string name_uint = typeid(unsigned int).name();
const std::string name_float = typeid(float).name();
const std::string name_double = typeid(double).name();
const std::string name_string = typeid(std::string).name();


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

  static T RandomNumber(T Min, T Max) { //TODO: One isn't defined in classes like std::string, for sure this is only valir for decimal primitive types
    Zero<T> z;
    std::string name_class = typeid(z.m_zero).name();
    T mean{};
    std::default_random_engine e1(global());

    if(name_class == name_int)
    {
      std::uniform_int_distribution<int> uniform_dist(Min,Max);
      mean = uniform_dist(e1);
    }
    else
    {
      std::uniform_real_distribution<double> uniform_dist(Min,Max);
      mean = uniform_dist(e1);
    }

    return mean;
   // return static_cast<T>(1);
  }

  T operator()(){
    return m_zero;
  }

private:
  
  T m_zero;
};

#endif
