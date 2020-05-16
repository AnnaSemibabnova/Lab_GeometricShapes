#include"shapes.h"
#include <iostream>

using namespace std;

template <typename T>
class Square : 
  public  Shapes
{
private:
  int part;
  T** Array;
public:
  Square();
  Square(int a, T _sign);
  Square(const Square& square);
  ~Square();

  int GetPart();
  T GetSign();

  void SetPart(int _part);
  float Area() override;
  ostream& print(ostream& off) override;
  bool operator == (const Square& other);
};
inline Square<char>::Square()
{
  part = 1;
  Array = new char* [1];
  Array[0] = new char[1];
  Array[0][0] = '*';
}

template<typename T>
inline Square<T>::Square(int a, T _sign)
{
  part = a;
  Array = new T * [part];
  for (int i = 0; i < part; i++)
    Array[i] = new T[part];
  for (int i = 0; i < part; i++)
    for (int j = 0; j < part; j++)
      Array[i][j] = _sign;
}

template<typename T>
inline Square<T>::Square(const Square& square)
{
  if (Array != 0)
  {
    for (int i = 0; i < part; i++)
      delete[] Array[i];
    delete[] Array;
  }
  part = square.part;
  Array = new T * [part];
  for (int i = 0; i < part; i++)
    Array[i] = new T[part];
  for (int i = 0; i < part; i++)
    for (int j = 0; j < part; j++)
      Array[i][j] = square.Array[i][j];
}

template<typename T>
inline Square<T>::~Square()
{
  if (Array != 0)
  {
    for (int i = 0; i < part; i++)
      delete[] Array[i];
    delete[] Array;
    Array = 0;
    part = 0;
  }
}

template<typename T>
inline int Square<T>::GetPart()
{
  return part;
}

template<typename T>
inline T Square<T>::GetSign()
{
  return Array[0][0];
}

template<typename T>
inline void Square<T>::SetPart(int _part)
{
  T tmp = Array[0][0];
  if (Array != 0)
  {
    for (int i = 0; i < part; i++)
      delete[] Array[i];
    delete[] Array;
  }
  part = _part;
  Array = new T * [part];
  for (int i = 0; i < part; i++)
    Array[i] = new T[part];
  for (int i = 0; i < part; i++)
    for (int j = 0; j < part; j++)
      Array[i][j] = tmp;
}

template<typename T>
inline float Square<T>::Area()
{
  return part * part;
}

template<typename T>
inline ostream& Square<T>::print(ostream& off)
{
  for (int i = 0; i < part; i++)
  {
    for (int j = 0; j < part; j++)
      off << Array[i][j];
    off << endl;
  }
  return off;
}

template<typename T>
inline bool Square<T>::operator == (const Square& other)
{
  if (part == other.part && Array[0][0] == other.Array[0][0])
    return true;
  return false;
}
