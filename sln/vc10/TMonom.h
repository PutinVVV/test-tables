#pragma once
#include "TVector.h"
template <class T>
class TMonom 
{
protected:
  TVector<int> degrees;
  int C;

public:
  void Set(int pc, TVector<int> pdegrees);
  TMonom();
  TMonom operator+(const TMonom& p);
  TMonom operator-(const TMonom& p);
  TMonom operator*(const TMonom& p);
  TMonom operator=(const TMonom& p);
  bool operator==(const TMonom& p);
  bool operator!=(const TMonom& p);
  int GetDim();
  TVector<int> GetDeg();
  friend istream& operator>>(istream& in, TMonom& v)
  {
    in >> v.C >> v.degrees;
    return in;
  }
  friend ostream& operator<<(ostream& out, const TMonom& v)
  {
    out << v.C << "*" << v.degrees;
    return out;
  }
};

template<class T>
inline void TMonom<T>::Set(int pc, TVector<int> pdegrees)
{
  C = pc;
  degrees = pdegrees;
}

template<class T>
inline TMonom<T>::TMonom()
{
  C = 1;
  degrees = { 0 };
}

template<class T>
inline TMonom<T> TMonom<T>::operator+(const TMonom& p)
{
  if (degrees == p.degrees)
  {
    TMonom<T> result(*this);
    result.C += p.C;
    return result;
  }
}
template<class T>
inline TMonom<T> TMonom<T>::operator-(const TMonom& p)
{
  if (degrees == p.degrees)
  {
    TMonom<T> result(*this);
    result.C -= p.C;
    return result;
  }
}

template<class T>
inline TMonom<T> TMonom<T>::operator*(const TMonom& p)
{
  TMonom<T> result(*this);
    result.degrees= degrees + p.degrees;
    result.C = C * p.C;
  return result;
}

template<class T>
inline TMonom<T> TMonom<T>::operator=(const TMonom& p)
{
  C = p.C;
  degrees = p.degrees;
  return *this;
}

template<class T>
inline bool TMonom<T>::operator==(const TMonom& p)
{
  if (degrees == p.degrees)
    return true;
  else return false;
}

template<class T>
inline bool TMonom<T>::operator!=(const TMonom& p)
{
  if (degrees != p.degrees)
    return true;
  else return false;
}

template<class T>
inline int TMonom<T>::GetDim()
{
  return C;
}

template<class T>
inline TVector<int> TMonom<T>::GetDeg()
{
  return degrees;
}