#include <iostream>
#include"shapes.h"

using namespace std;

template <typename T>
class Point :
  public  Shapes
{
private:
  T sign;
public:
  Point();
  Point(T _sign);
  Point(const Point& point);
  
  T Get();
  float Perimeter() override;
  
  ostream& print(ostream& off) override;
  bool operator ==(const Point& other);
};

template<typename T>
inline Point<T>::Point()
{
  sign = '.';
}

template<typename T>
inline Point<T>::Point(T _sign)
{
  sign = _sign;
}

template<typename T>
inline Point<T>::Point(const Point& point)
{
  sign = point.sign;
}

template<typename T>
inline T Point<T>::Get()
{
  return sign;
}

template<typename T>
inline float Point<T>::Perimeter()
{
  return 0;
}

template<typename T>
inline ostream& Point<T>::print(ostream& off)
{
  off << this->Get();
  return off;
}

template<typename T>
inline bool Point<T>::operator==(const Point& other)
{
  if (sign == other.sign)
    return true;
  return false;
}
