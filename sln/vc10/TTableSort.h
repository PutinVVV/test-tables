
#pragma once
#include "TNode.h"
#include "Math.h"

using namespace std;
template <class TKEY, class TVAL>
class TTableSort
{
protected:
  TNode<TKEY, TVAL>* data;
  int count;
  int size;
public:
  TTableSort(int _s = 1);
  TTableSort(const TTableSort<TKEY, TVAL>& p);
  TTableSort(TTableSort<TKEY, TVAL>&& p);
  ~TTableSort();
  int GetCount();
  int GetSize();
  void ReSize(int nsize);
  TVAL& operator[](const TKEY& p);
  void Add(TNode<TKEY, TVAL>& p);
  void Add(TKEY k, TVAL v);
  TVAL Find(const TKEY& k);
  void Del(const TKEY& k);
  bool IsFull();
  bool IsEmpty();
  void Add1(TNode<TKEY, TVAL>& p);

  friend ostream& operator<<(ostream& out, const TTableSort& v)
  {
    for (int i = 0; i < v.count; i++)
    {
      out << v.data[i] << endl;
    }
    return out;
  }
};

template<class TKEY, class TVAL>
inline TTableSort<TKEY, TVAL>::TTableSort(int _s)
{
  data = new TNode<TKEY, TVAL>[_s];
  size = _s;
  count = 0;
}

template<class TKEY, class TVAL>
inline TTableSort<TKEY, TVAL>::TTableSort(const TTableSort<TKEY, TVAL>& p)
{
  size = p.size;
  count = p.count;
  data= data = new TNode<TKEY, TVAL>[size];
  for (int i = 0; i < count; i++)
    data[i] = p.data[i];
}

template<class TKEY, class TVAL>
inline TTableSort<TKEY, TVAL>::TTableSort(TTableSort<TKEY, TVAL>&& p)
{
  size = p.size;
  count = p.count;
  data = data = new TNode<TKEY, TVAL>[size];
  for (int i = 0; i < count; i++)
    data[i] = p.data[i];
  p.count = 0;
  p.size = 0;
  delete[] p.data;
}

template<class TKEY, class TVAL>
inline TTableSort<TKEY, TVAL>::~TTableSort()
{
  size = 0;
  count = 0;
  delete[] data;
}

template<class TKEY, class TVAL>
inline int TTableSort<TKEY, TVAL>::GetCount()
{
  return count;
}

template<class TKEY, class TVAL>
inline int TTableSort<TKEY, TVAL>::GetSize()
{
  return size;
}

template<class TKEY, class TVAL>
inline void TTableSort<TKEY, TVAL>::ReSize(int nsize)
{
  if (nsize > 0)
  {
    size = nsize;
    if (size < count)
      count = size;
    TNode<TKEY, TVAL>* data1 = new TNode<TKEY, TVAL>[size];
    for (int i = 0; i < count; i++)
      data1[i] = data[i];
    data= new TNode<TKEY, TVAL>[size];
    for (int i = 0; i < count; i++)
      data[i] = data1[i];
    delete[] data1;
  }
}

template<class TKEY, class TVAL>
inline TVAL& TTableSort<TKEY, TVAL>::operator[](const TKEY& p)
{
  if (this->IsFull())
    this->ReSize(size + 1);
  int cer = count / 2, s = 0, e = count;
  while (e - s > 1)
  {
    if (data[cer].GetKey() > p)
    {
      s = cer;
      cer = (e + s) / 2;
    }
    else
    {
      e = cer;
      cer = (e + s) / 2;
    }
  }


  if (data[cer].GetKey() == p)
  {
    return data[cer].RedVal();
  }


  if (data[cer].GetKey() > p)
  {
    if(data[cer-1].GetKey()==p)
      return data[cer-1].RedVal();
  }
  if (data[cer].GetKey() < p)
  {
    if (data[cer + 1].GetKey() == p)
      return data[cer + 1].RedVal();
  }
}

template<class TKEY, class TVAL>
inline void TTableSort<TKEY, TVAL>::Add(TNode<TKEY, TVAL>& p)
{
  if (this->IsFull())
    this->ReSize(size+ 1);
  int cer = count / 2, s = 0, e = count;
  while (e - s > 1)
  {
    if (data[cer].GetKey() > p.GetKey())
    {
      s = cer;
      cer = (e + s) / 2;
    }
    else
    {
      e = cer;
      cer = (e + s) / 2;
    }
  }

  
  if (data[cer].GetKey() < p.GetKey())
  {
    if(cer!=0)
    cer--;
  }
  
  
  if (data[cer].GetKey() > p.GetKey())
    cer++;
  
  for (int i = count; i > cer; i--)
    data[i] = data[i - 1];
  data[cer] = p;
  count++;
}

template<class TKEY, class TVAL>
inline void TTableSort<TKEY, TVAL>::Add(TKEY k, TVAL v)
{
  TNode<TKEY, TVAL> p(k, v);

  if (this->IsFull())
    this->ReSize(size + 1);
  int cer = count / 2, s = 0, e = count;
  while (e - s > 1)
  {
    if (data[cer].GetKey() > p.GetKey())
    {
      s = cer;
      cer = (e + s) / 2;
    }
    else
    {
      e = cer;
      cer = (e + s) / 2;
    }
  }


  if (data[cer].GetKey() < p.GetKey())
  {
    if (cer != 0)
      cer--;
  }


  if (data[cer].GetKey() > p.GetKey())
    cer++;

  for (int i = count; i > cer; i--)
    data[i] = data[i - 1];
  data[cer] = p;
  count++;
}

template<class TKEY, class TVAL>
inline TVAL TTableSort<TKEY, TVAL>::Find(const TKEY& p)
{

  int cer = count / 2, s = 0, e = count;
  while (e - s > 1)
  {
    if (data[cer].GetKey() > p)
    {
      s = cer;
      cer = (e + s) / 2;
    }
    else
    {
      e = cer;
      cer = (e + s) / 2;
    }
  }


  if (data[cer].GetKey() < p)
  {
    if (cer != 0)
      cer--;
  }


  if (data[cer].GetKey() > p)
    cer++;
  if (data[cer].GetKey() == p)
  {
    return data[cer].GetVal();
  }
  return data[count].GetVal();

}

template<class TKEY, class TVAL>
inline void TTableSort<TKEY, TVAL>::Del(const TKEY& p)
{
  if (this->IsFull())
    this->ReSize(size + 1);
  int cer = count / 2, s = 0, e = count;
  while (e - s > 1)
  {
    if (data[cer].GetKey() > p)
    {
      s = cer;
      cer = (e + s) / 2;
    }
    else
    {
      e = cer;
      cer = (e + s) / 2;
    }
  }


  if (data[cer].GetKey() < p)
  {
    if (cer != 0)
      cer--;
  }


  if (data[cer].GetKey() > p)
    cer++;
  if(data[cer].GetKey() == p)
  {
    for (int i = cer; i < count - 1; i++)
      data[i] = data[i + 1];
    count--;
  }
  
}

template<class TKEY, class TVAL>
inline bool TTableSort<TKEY, TVAL>::IsFull()
{
  if (size == count)
    return true;
  return false;
}

template<class TKEY, class TVAL>
inline bool TTableSort<TKEY, TVAL>::IsEmpty()
{
  if (count == 0 && size != 0)
    return true;
  return false;
}

