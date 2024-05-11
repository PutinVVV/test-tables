  #pragma once
  #include <iostream>
  template <class TKEY, class TVAL>
  class THashTableNode 
	  {
    protected:
      TKEY key;
      TVAL value;
      THashTableNode<TKEY, TVAL>* next;
      THashTableNode<TKEY, TVAL>* prev;

    public:
      TKEY& GetKey();
      TVAL& GetValue();
      THashTableNode<TKEY, TVAL>* GetNext();
      THashTableNode<TKEY, TVAL>* GetPrev();

      void SetKey(TKEY k);
      void SetValue(TVAL v);
      void SetNext(THashTableNode<TKEY, TVAL>* n);
      void SetPrev(THashTableNode<TKEY, TVAL>* p);
      ~THashTableNode();
      THashTableNode();
      THashTableNode(TKEY k, TVAL value, THashTableNode<TKEY, TVAL>* next = nullptr, THashTableNode<TKEY, TVAL>* prev = nullptr);

      bool operator==(const THashTableNode<TKEY, TVAL>& p);
      bool operator!=(const THashTableNode<TKEY, TVAL>& p);

      bool operator==(const TKEY& k);
      bool operator!=(const TKEY& k);

      void Add(TKEY key, TVAL value);
      THashTableNode<TKEY, TVAL>* Del();
      THashTableNode<TKEY, TVAL>* Find(const TKEY& k);

	  };

  template<class TKEY, class TVAL>
  inline TKEY& THashTableNode<TKEY, TVAL>::GetKey()
  {
    return key;
  }

  template<class TKEY, class TVAL>
  inline TVAL& THashTableNode<TKEY, TVAL>::GetValue()
  {
    return value;
  }

  template<class TKEY, class TVAL>
  inline THashTableNode<TKEY, TVAL>* THashTableNode<TKEY, TVAL>::GetNext()
  {
    return next;
  }

  template<class TKEY, class TVAL>
  inline THashTableNode<TKEY, TVAL>* THashTableNode<TKEY, TVAL>::GetPrev()
  {
    return prev;
  }

  template<class TKEY, class TVAL>
  inline void THashTableNode<TKEY, TVAL>::SetKey(TKEY k)
  {
    key = k;
  }

  template<class TKEY, class TVAL>
  inline void THashTableNode<TKEY, TVAL>::SetValue(TVAL v)
  {
    value = v;
  }

  template<class TKEY, class TVAL>
  inline void THashTableNode<TKEY, TVAL>::SetNext(THashTableNode<TKEY, TVAL>* n)
  {
    next = n;
  }

  template<class TKEY, class TVAL>
  inline void THashTableNode<TKEY, TVAL>::SetPrev(THashTableNode<TKEY, TVAL>* p)
  {
    prev = p;
  }

  template<class TKEY, class TVAL>
  inline THashTableNode<TKEY, TVAL>::THashTableNode()
  {
    next = nullptr;
    prev = nullptr;
  }

  template<class TKEY, class TVAL>
  inline THashTableNode<TKEY, TVAL>::THashTableNode(TKEY k, TVAL value, THashTableNode<TKEY, TVAL>* next, THashTableNode<TKEY, TVAL>* prev)
  {
    key = k;
    this->value = value;
    this->next = next;
    this->prev = prev;

  }

  template<class TKEY, class TVAL>
  inline bool THashTableNode<TKEY, TVAL>::operator==(const THashTableNode<TKEY, TVAL>& p)
  {
    return key == p.key;
  }

  template<class TKEY, class TVAL>
  inline bool THashTableNode<TKEY, TVAL>::operator!=(const THashTableNode<TKEY, TVAL>& p)
  {
    return key != p.key;
  }

  template<class TKEY, class TVAL>
  inline bool THashTableNode<TKEY, TVAL>::operator==(const TKEY& k)
  {
    return key ==k;
  }

  template<class TKEY, class TVAL>
  inline bool THashTableNode<TKEY, TVAL>::operator!=(const TKEY& k)
  {
    return key !=k;
  }

  template<class TKEY, class TVAL>
  inline void THashTableNode<TKEY, TVAL>::Add(TKEY key, TVAL value)
  {
    THashTableNode<TKEY, TVAL>* cur = next;
    THashTableNode<TKEY, TVAL>** nextcur = nullptr;
    if (cur == nullptr)
    {
      cur= new THashTableNode<TKEY, TVAL>(key, value);
    }
    if (cur->next == nullptr && !(cur == nullptr))
    {
      cur->next = new THashTableNode<TKEY, TVAL>(key,value);
    }
    else
    {
      while (cur != nullptr) 
      {
        nextcur = &cur->next;
        cur = cur->next;
      }
      *nextcur = new THashTableNode<TKEY, TVAL>(key, value);
    }
  }

  template<class TKEY, class TVAL>
  inline THashTableNode<TKEY, TVAL>* THashTableNode<TKEY, TVAL>::Del()
  {
    if (this == nullptr)
    {
      THashTableNode<TKEY, TVAL> a;
      return &a;
    }
    if (next == nullptr && prev== nullptr)
    {
      return nullptr;
    }
    if (next == nullptr && prev != nullptr)
    {
      prev->next = nullptr;
      THashTableNode<TKEY, TVAL>* cur = prev;
      while (cur->prev != nullptr)
      {
        cur = cur->prev;
      }
      return prev;
    }
    else if (next != nullptr && prev == nullptr)
    {
      next->prev = nullptr;
      return next;
    }
    else 
    {
      next->prev = prev;
      prev->next = next;
    }
  }

  template<class TKEY, class TVAL>
  inline THashTableNode<TKEY, TVAL>* THashTableNode<TKEY, TVAL>::Find(const TKEY& k) 
  {
    if (key == k)
      return this;
    THashTableNode<TKEY, TVAL>* cur = next;
    while (cur != nullptr && cur->key != k)
      cur = cur->next;
    return cur;
  }

  template<class TKEY, class TVAL>
  inline THashTableNode<TKEY, TVAL>::~THashTableNode()
  {
    THashTableNode<TKEY, TVAL>* nextNode = next;
    next = nullptr;
    if (nextNode != nullptr)
    {
      delete nextNode;
    }
    prev = nullptr;
  }

