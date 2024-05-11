#pragma once
#include <iostream>
#include <utility>
using namespace std;
template <class TKEY, class TVAL>
class TNode
{
protected:
  TKEY key;
  TVAL value;
public:
  TNode();
  TNode(const TKEY& k, const TVAL&v);
  TNode(const TNode<TKEY, TVAL>& p);
  TNode(TNode<TKEY, TVAL>&& p);
  TNode<TKEY, TVAL>& operator=(const TNode<TKEY, TVAL>& p);
  ~TNode();
  TVAL GetVal();
  TKEY GetKey();
  bool operator==(const TNode<TKEY, TVAL>& p);
  bool operator!=(const TNode<TKEY, TVAL>& p);
  bool operator<(const TNode<TKEY, TVAL>& p);
  bool operator>(const TNode<TKEY, TVAL>& p);
  bool operator==(TKEY& p);
  bool operator!=(TKEY& p);
  bool operator<(TKEY& p);
  bool operator>(TKEY& p);
  TVAL& RedVal();
  friend ostream& operator<<(ostream& out, const TNode& v)
  {
    out << "| ";
    out << v.key << '|' << v.value;
    out << " |" << endl;
    return out;
  }
};

template<class TKEY, class TVAL>
inline TNode<TKEY, TVAL>::TNode()
{
}

template<class TKEY, class TVAL>
inline TNode<TKEY, TVAL>::TNode(const TKEY& k,const TVAL& v)
{
  key = k;
  value = v;
}

template<class TKEY, class TVAL>
inline TNode<TKEY, TVAL>::TNode(const TNode<TKEY, TVAL>& p)
{
  key = p.key;
  value = p.value;
}

template<class TKEY, class TVAL>
inline TNode<TKEY, TVAL>::TNode(TNode<TKEY, TVAL>&& p)
{
  key = p.key;
  value = p.value;
  delete p.value;
  delete p.key;
}

template<class TKEY, class TVAL>
inline TNode<TKEY, TVAL>& TNode<TKEY, TVAL>::operator=(const TNode<TKEY, TVAL>& p)
{
  key = std::move(p.key);
  value = std::move(p.value);
  return *this;
}

template<class TKEY, class TVAL>
inline TNode<TKEY, TVAL>::~TNode()
{

}

template<class TKEY, class TVAL>
inline TVAL TNode<TKEY, TVAL>::GetVal()
{
  return value;
}

template<class TKEY, class TVAL>
inline TKEY TNode<TKEY, TVAL>::GetKey()
{
  return key;
}

template<class TKEY, class TVAL>
inline bool TNode<TKEY, TVAL>::operator==(const TNode<TKEY, TVAL>& p)
{
  if (p.key == key)
    return true;
  return false;
}

template<class TKEY, class TVAL>
inline bool TNode<TKEY, TVAL>::operator!=(const TNode<TKEY, TVAL>& p)
{
  if (p.key != key)
    return true;
  return false;
}

template<class TKEY, class TVAL>
inline bool TNode<TKEY, TVAL>::operator<(const TNode<TKEY, TVAL>& p)
{
  if (p.key > key)
    return true;
  return false;
}

template<class TKEY, class TVAL>
inline bool TNode<TKEY, TVAL>::operator>(const TNode<TKEY, TVAL>& p)
{
  if (p.key < key)
    return true;
  return false;
}

template<class TKEY, class TVAL>
inline bool TNode<TKEY, TVAL>::operator==(TKEY& p)
{
  if (p == key)
    return true;
  return false;
}

template<class TKEY, class TVAL>
inline bool TNode<TKEY, TVAL>::operator!=(TKEY& p)
{
  if (p != key)
    return true;
  return false;
}

template<class TKEY, class TVAL>
inline bool TNode<TKEY, TVAL>::operator<(TKEY& p)
{
  if (p > key)
    return true;
  return false;
}

template<class TKEY, class TVAL>
inline bool TNode<TKEY, TVAL>::operator>(TKEY& p)
{
  if (p < key)
    return true;
  return false;
}

template<class TKEY, class TVAL>
inline TVAL& TNode<TKEY, TVAL>::RedVal()
{
  return value;
}
