#include <iostream>

using namespace std;

class Shapes
{
public:
  virtual ~Shapes() {}
  virtual float Perimeter() = 0;
  virtual ostream& print(ostream& off) = 0;
  
  friend ostream& operator<<(ostream& off, Shapes& another)
  {
    return another.print(off);
  }
  
  bool operator > (Shapes& other)
  {
    if (this->Perimeter() > other.Perimeter())
      return true;
    return false;
  }
  
  bool operator < (Shapes& other)
  {
    if (this->Perimeter() < other.Perimeter())
      return true;
    return false;
  }
};
