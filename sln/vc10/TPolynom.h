#pragma once
#include "TMonom.h"
#include "tlist.h"
template <class T>
class TPolynom 
{
protected:
  TMonom<int> *poly;
  int count;

public:
  void Set(int c, TMonom<int> *Monoms);
  void Add(int c, TMonom<int>* Monoms);
  void AddOne(TMonom<int> Monoms);
  TPolynom();
  TPolynom(int c, TVector<int> pdegrees);
  TPolynom operator+(const TPolynom& p);
  TPolynom operator-(const TPolynom& p);
  TPolynom operator*(const TPolynom& p);
  TPolynom operator=(const TPolynom& p);
  bool operator==(const TPolynom& p);
  bool operator!=(const TPolynom& p);
  void ProvSort();
  int GetCount();
  TMonom<int> GetMonom(int c);
  friend ostream& operator<<(ostream& out, const TPolynom& v)
  {
    for (int i = 0; i < v.count; i++)
      out << v.poly[i] << "+";
    return out;
  }
};

template<class T>
inline void TPolynom<T>::Set(int c, TMonom<int>* Monoms)
{
  count = c;
  poly = new TMonom<int>[count];
  for (int i = 0; i < count; i++)
    poly[i] = Monoms[i];
}


template<class T>
inline void TPolynom<T>::Add(int c, TMonom<int>* Monoms)
{
  TMonom<int>* w = new TMonom<int>[count + c];
  for (int i = 0; i < count; i++)
    w[i] = poly[i];
  for (int i = count; i < count + c; i++)
    w[i] = Monoms[i - count];
  count += c;
  delete[] poly;
  poly = new TMonom<int>[count];
  for (int i = 0; i < count; i++)
    poly[i] = w[i];
  this->ProvSort();
  delete[] w;
}

template<class T>
inline void TPolynom<T>::AddOne(TMonom<int> Monoms)
{
  TMonom<int>* w = new TMonom<int>[count + 1];
  for (int i = 0; i < count; i++)
    w[i] = poly[i];
  w[count] = Monoms;
  count += 1;
  delete[] poly;
  poly = new TMonom<int>[count];
  for (int i = 0; i < count; i++)
    poly[i] = w[i];
  this->ProvSort();
  delete[] w;
}


template<class T>
inline TPolynom<T>::TPolynom()
{
  count = 1;
  poly = new TMonom<int>[count];
}

template<class T>
inline TPolynom<T>::TPolynom(int c, TVector<int> pdegrees)
{
  count = 1;
  poly = new TMonom<int>[count];
  TMonom<int> a;
  a.Set(c, pdegrees);
  poly[0] = a;
}

template<class T>
inline TPolynom<T> TPolynom<T>::operator+(const TPolynom& p)
{
  int ncount = count + p.count+1;
  TMonom<int>* pol = new TMonom<int>[ncount];
  int y = 0;
  for (int i = 0; i < count; i++)
  {
    pol[y] = poly[i];
    y++;
  }
  for (int i = count; i < count + p.count; i++)
  {
    pol[y] = p.poly[i - count];
    y++;
  }
  count = ncount;
  poly = new TMonom<int>[count];
  for (int i = 0; i < count; i++)
    poly[i] = pol[i];
  return *this;
}

template<class T>
inline TPolynom<T> TPolynom<T>::operator-(const TPolynom& p)
{
  if (count > p.count)
  {
    for (int i = 0; i < count; i++)
      if (poly[i] == p.poly[i])
        poly[i] = poly[i] - p.poly[i];
  }
  else
  {
    for (int i = 0; i < p.count; i++)
      if (poly[i] == p.poly[i])
        p.poly[i] = poly[i] - p.poly[i];
    count = p.count;
    TMonom<int> poly = new TMonom<int>[count];
    for (int i = 0; i < p.count; i++)
      poly[i] = p.poly[i];
  }
  //this->ProvSort();
  return *this;
}

template<class T>
inline TPolynom<T> TPolynom<T>::operator*(const TPolynom& p)
{
  int ncount = (count) * (p.count)+1;
  TMonom<int>* pol = new TMonom<int>[ncount];
  int y = 0;
  for (int i = 0; i < count; i++)
  {
    for (int j = 0; j < p.count; j++)
    {
      pol[y] = poly[i] * p.poly[j];
      y++;
    }
  }
  count = ncount;
  poly = new TMonom<int>[count];
  for (int i = 0; i < count; i++)
    poly[i] = pol[i];
  //this->ProvSort();
  return *this;

}

template<class T>
inline TPolynom<T> TPolynom<T>::operator=(const TPolynom& p)
{
  count = p.count;
  TMonom<int>* poly = new TMonom<int>[count];
  for (int i = 0; i < count; i++)
    poly[i] = p.poly[i];
  this->ProvSort();
  return *this;
}

template<class T>
inline bool TPolynom<T>::operator==(const TPolynom& p)
{
  if (const == p.const)
  {
    for (int i = 0; i < count; i++)
      if (poly != p.poly)
        return FALSE;
    return TRUE;
  }
  return FALSE;
}

template<class T>
inline bool TPolynom<T>::operator!=(const TPolynom& p)
{
  if (const != p.const)
    return TRUE;
  else
  {
    for (int i = 0; i < count; i++)
      if (poly != p.poly)
        return TRUE;
    return FALSE;
  }
}

template<class T>
inline void TPolynom<T>::ProvSort()
{
  for(int j = 0; j < count; j++)
    for (int i = j+1; i < count; i++)
    {
      if ((poly[i] == poly[j]) && (i != j))  // Добавлено условие i != j
      {
        poly[i] = poly[i] + poly[j];
        TVector<int> v(0);
        poly[j].Set(0, v);
      }
    }
  for (int i = 0; i < count; i++)
  {
    if (poly[i].GetDim() == 0)
    {
      TMonom<int>* pol = new TMonom<int>[count - 1];
      for (int j = 0; j < count - 1; j++)
      {
        if (i > j)
          pol[j] = poly[j];
        if (j >= i)
          pol[j] = poly[j + 1];
      }
      count = count - 1;
      poly = new TMonom<int>[count];
      for (int j = 0; j < count - 1; j++)
        poly[j] = pol[j];
    }
  }
}

template<class T>
inline int TPolynom<T>::GetCount()
{
  return count;
}

template<class T>
inline TMonom<int> TPolynom<T>::GetMonom(int c)
{
  return poly[c];
}
