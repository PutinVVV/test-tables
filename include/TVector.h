// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора
#include <iostream>
#include <functional>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора
template <class T>
class TVector
{
protected:
    T *pVector;
    int Size; // размер вектора

public:
    typedef function<T(size_t)> AllocatorFunc;
    TVector(size_t s = 1);
    TVector(const TVector &v); // конструктор копирования
    ~TVector();
    void NewSize(int s) const;
    int GetSize() const;  // размер вектора
    T& operator[](int pos); // доступ
    bool operator==(const TVector &v) const noexcept; // сравнение
    bool operator!=(const TVector &v) const noexcept; // сравнение
    TVector& operator=(const TVector &v); // присваивание

    // скалярные операции
    TVector  operator+(const T &val);   // прибавить скаляр
    TVector  operator-(const T &val);   // вычесть скаляр
    TVector  operator*(const T &val);   // умножить на скаляр

    // векторные операции
    TVector  operator+(const TVector &v);     // сложение
    TVector  operator-(const TVector &v);     // вычитание
    T  operator*(const TVector &v);     // скалярное произведение

    // ввод-вывод
    friend istream& operator>>(istream &in, TVector &v)
    {
    for (int i = 0; i < v.Size; i++)
        in >> v.pVector[i];
    return in;
    }
    friend ostream& operator<<(ostream &out, const TVector &v)
    {
    out << "(";
    for (int i = 0; i < v.Size; i++)
        out << v.pVector[i] << ' ';
    out << ")";
    return out;
    }
};

template <class T>
TVector<T>::TVector(size_t s) : Size(s)
{
    if (s < 0 || s > MAX_VECTOR_SIZE) 
    { 
      Size = 0;
      throw exception("Invalid size TVECTOR"); 
    }
    pVector = new T[Size];
    for (int i = 0; i < Size; i++)
    {
      pVector[i] = 0;
      //cout << pVector[i];
    }
} /*-------------------------------------------------------------------------*/

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T> &v): Size(v.Size)
{
  if (v.Size > 0) {
    pVector = new T[Size]();
    for (int i = 0; i < Size; i++) { pVector[i] = v.pVector[i]; }
  }
  else {
    pVector = new T[1];
    Size = 1;
    pVector[0] = 0;
  }

} /*-------------------------------------------------------------------------*/

template <class T>
TVector<T>::~TVector()
{
    delete[] pVector;
} /*-------------------------------------------------------------------------*/

template<class T>
inline void TVector<T>::NewSize(int s) const
{
  T* b = new T[s];
  for (int i = 0; i < s; i++) {
    if (Size > i)
      b[i] = pVector[i];
    else b[i] = 0;
  }

}

template<class T>
inline int TVector<T>::GetSize() const
{
  return Size;
}

template <class T> // доступ
T& TVector<T>::operator[](int pos)
{
    if (pos < 0 || pos > Size) { throw exception("Invalid position"); }

    return pVector[pos];
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator==(const TVector &v) const noexcept
{
    if (Size != v.Size) { return false; }

    for (int i = 0; i < Size; i++)
    {
        if (pVector[i] != v.pVector[i]) { return false; }
    }

    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector &v) const noexcept
{
    return !(*this == v);
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector &v)
{
    if (this != &v)
    {
        if (Size != v.Size)
        {
            Size = v.Size;
            delete[] pVector;
            pVector = new T[Size];
        }
        for (int i = 0; i < Size; i++)
          pVector[i] = v.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T &val)
{
    TVector<T> temp(Size);

    for (int i = 0; i < Size; i++) { temp[i] = pVector[i] + val; }
    return temp;
} /*-------------------------------------------------------------------------*/

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T &val)
{
    TVector<T> temp(Size);

    for (int i = 0; i < Size; i++) { temp[i] = pVector[i] - val; }
    return temp;
} /*-------------------------------------------------------------------------*/

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T &val)
{
    TVector<T> temp(Size);

    for (int i = 0; i < Size; i++) { temp[i] = pVector[i] * val; }
    return temp;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T>& v)
{

  if (Size > v.Size)
  {
    TVector<T> temp(Size);
    for (int i = 0; i < v.Size; i++)
      temp.pVector[i] = pVector[i] + v.pVector[i];
    for (int i = v.Size; i < Size; i++)
      temp.pVector[i] = pVector[i];
    return temp;
  }
  if (Size < v.Size)
  {
    TVector<T> temp(v.Size);
    for (int i = 0; i < Size; i++)
      temp.pVector[i] = pVector[i] + v.pVector[i];
    for (int i = Size; i < v.Size; i++)
      temp.pVector[i] = v.pVector[i];
    return temp;
  }
  //throw exception("Invalid size321"

  TVector<T> temp(Size);


    for (int i = 0; i < Size; i++) { temp.pVector[i] = pVector[i] + v.pVector[i]; }
    return temp;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
    if (Size != v.Size) { throw exception("Invalid size"); }

    TVector<T> temp(Size);

    for (int i = 0; i < Size; i++) { temp.pVector[i] = pVector[i] - v.pVector[i]; }
    return temp;
} /*-------------------------------------------------------------------------*/

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T> &v)
{
    if (Size != v.Size) { throw exception("Invalid size"); }
    
    int result = 0;
    for (int i = 0; i < Size; i++) { result += pVector[i] * v.pVector[i]; }
    
    return result;
} /*-------------------------------------------------------------------------*/


