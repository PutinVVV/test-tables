#pragma once
#include <iostream>
#include <functional>

using namespace std;
template <class TKEY,class TVAL>
class TTable
{
protected:
  TKEY* keys;
  TVAL* values;
  int count;
  int size;
public:
  TTable(int _s = 1);
  TTable(const TTable<TKEY, TVAL>& p);
  TTable(TTable<TKEY, TVAL>&& p);
  ~TTable();
  int GetCount();
  int GetSize();
  void ReSize(int nsize);
  TVAL& operator[](const TKEY& p);
  void Add(TKEY k, TVAL v);
  TVAL Find(const TKEY& k);
  void Del(const TKEY& k);
  bool IsFull();
  bool IsEmpty();

  friend ostream& operator<<(ostream& out, const TTable& v)
  {
    for (int i = 0; i < v.count; i++) 
    {
      out << "| ";
      out << v.keys[i] << '|' << v.values[i];
      out << " |"<<endl;
    }
    return out;
  }
};

template<class TKEY, class TVAL>
inline TTable<TKEY, TVAL>::TTable(int _s)
{
  if (_s > 0)
  {
    size = _s;
    count = 0;
    keys = new TKEY[size];
    values = new TVAL[size];
  }
  else
    throw("invalid size constructor");
}

template<class TKEY, class TVAL>
inline TTable<TKEY, TVAL>::TTable(const TTable<TKEY, TVAL>& p)
{
  size = p.size;
  count = p.count;
  keys = new TKEY[size];
  values = new TVAL[size];
  for (int i = 0; i < count; i++)
  {
    keys[i] = p.keys[i];
    values[i] = p.values[i];
  }
}

template<class TKEY, class TVAL>
inline TTable<TKEY, TVAL>::TTable(TTable<TKEY, TVAL>&& p)
{
  size = p.size;
  count = p.count;
  keys = new TKEY[size];
  values = new TVAL[size];
  for (int i = 0; i < count; i++)
  {
    keys[i] = p.keys[i];
    values[i] = p.values[i];
  }
  p.count = 0;
  p.size = 0;
  delete[] p.keys;
  delete[] p.values;
  p.keys = nullptr;
  p.values = nullptr;
}

template<class TKEY, class TVAL>
inline TTable<TKEY, TVAL>::~TTable()
{
  delete[] keys;
  delete[] values;
  count = 0;
  size = 0;
  keys = nullptr;
  values = nullptr;
}

template<class TKEY, class TVAL>
inline int TTable<TKEY, TVAL>::GetCount()
{
  return count;
}

template<class TKEY, class TVAL>
inline int TTable<TKEY, TVAL>::GetSize()
{
  return size;
}

template<class TKEY, class TVAL>
inline void TTable<TKEY, TVAL>::ReSize(int nsize)
{
  TKEY* _keys = new TKEY[nsize];
  TVAL* _values = new TVAL[nsize];
  if (size > nsize)
    size = nsize;
  for (int i = 0; i < size; i++)
  {
    _values[i] = values[i];
    _keys[i] = keys[i];
  }
  size = nsize;
  delete[] keys;
  delete[] values;
  values = _values;
  keys = _keys;
}

template<class TKEY, class TVAL>
inline TVAL& TTable<TKEY, TVAL>::operator[](const TKEY& p)
{
  for (int i = 0; i < count; i++)
    if (keys[i] == p)
      return values[i];
  throw std::out_of_range("Key not found");
}

template<class TKEY, class TVAL>
inline void TTable<TKEY, TVAL>::Add(TKEY k, TVAL v)
{
  if (this->IsFull())
    this->ReSize(size + 1);
  values[count] = v;
  keys[count] = k;
  count++;
}

template<class TKEY, class TVAL>
inline TVAL TTable<TKEY, TVAL>::Find(const TKEY& k)
{
  for (int i = 0; i < count; i++)
    if (keys[i] == k)
      return values[i];
}

template<class TKEY, class TVAL>
inline void TTable<TKEY, TVAL>::Del(const TKEY& k)
{
  if (!(this->IsEmpty()))
  {
    int r = 0;
    for (int i = 0; i < count; i++)
      if (k == keys[i] && r != 1)
      {
        r = 1;
        if (i != count - 1)
        {
          keys[i] = keys[i + 1];
          values[i] = values[i + 1];
        }
      }
    if (r == 1)
      count--;
  }
  else
    throw("cant delete because empty");
}

template<class TKEY, class TVAL>
inline bool TTable<TKEY, TVAL>::IsFull()
{
  if (count == size && size > 0)
    return true;
  else 
    return false;
}

template<class TKEY, class TVAL>
inline bool TTable<TKEY, TVAL>::IsEmpty()
{
  if (count==0 && size>0)
    return true;
  else
    return false;
}

