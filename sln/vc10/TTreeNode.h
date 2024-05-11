#pragma once
#include <iostream>
template <class TKEY, class TVAL>
class TTreeNode {
public:
  TKEY key;
  TVAL value;
  TTreeNode<TKEY, TVAL>* left;
  TTreeNode<TKEY, TVAL>* right;
  TTreeNode<TKEY, TVAL>* prev;

  TTreeNode() : left(nullptr), right(nullptr), prev(nullptr) {}
  TTreeNode(TKEY k, TVAL v, TTreeNode<TKEY, TVAL>* l, TTreeNode<TKEY, TVAL>* r)
    : key(k), value(v), left(l), right(r), prev(nullptr) {}
  TTreeNode(TKEY k, TVAL v, TTreeNode<TKEY, TVAL>* l, TTreeNode<TKEY, TVAL>* r, TTreeNode<TKEY, TVAL>* p)
    : key(k), value(v), left(l), right(r), prev(p) {}
  TTreeNode(TKEY k, TVAL v, TTreeNode<TKEY, TVAL>* p)
    : key(k), value(v), left(nullptr), right(nullptr), prev(p) {}
  TTreeNode(TKEY k, TVAL v)
    : key(k), value(v), left(nullptr), right(nullptr), prev(nullptr) {}
  TTreeNode(TKEY k)
    : key(k), value(TVAL()), left(nullptr), right(nullptr), prev(nullptr) {}
  TTreeNode(const TTreeNode<TKEY, TVAL>& p)
    : key(p.key), value(p.value), left(p.left), right(p.right), prev(p.prev) {}

  void SetLeft(TTreeNode<TKEY, TVAL>* l) { left = l; }
  void SetRight(TTreeNode<TKEY, TVAL>* r) { right = r; }
  void SetPrev(TTreeNode<TKEY, TVAL>* p) { prev = p; }

  TVAL& GetVal() { return value; }

  bool operator >(const TTreeNode<TKEY, TVAL>& p) { return key > p.key; }
  bool operator <(const TTreeNode<TKEY, TVAL>& p) { return key < p.key; }
  bool operator ==(const TTreeNode<TKEY, TVAL>& p) { return key == p.key; }
  bool operator !=(const TTreeNode<TKEY, TVAL>& p) { return key != p.key; }
  bool operator >(const TKEY& p) { return key > p; }
  bool operator <(const TKEY& p) { return key < p; }
  bool operator ==(const TKEY& p) { return key == p; }
  bool operator !=(const TKEY& p) { return key != p; }

  friend ostream& operator<<(std::ostream& out, const TTreeNode& v) {
    out << "| " << v.key << " | " << v.value << " |" << std::endl;
    return out;
  }
};
