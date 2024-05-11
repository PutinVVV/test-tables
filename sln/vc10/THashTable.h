#pragma once
#include "THashTableNode.h"
#include "ITable.h"

template <class TKEY, class TVAL>
class THashTable: public ITable<TKEY,TVAL>
{
protected:
	THashTableNode<TKEY, TVAL>** data;
	int size;
	int Hash(const TKEY& key);
public:

	THashTable(THashTable<TKEY, TVAL>&& p);
	THashTable(const THashTable<TKEY, TVAL>& p);
	~THashTable();
	virtual TVAL Find(const TKEY& k);
	virtual void Del(const TKEY& k);
	virtual void Add(TKEY k, TVAL v);
	virtual TVAL& operator[](const TKEY& k);
	THashTable(int s=0);
	void ReSize(int s);
	int GetCount();


};

template<class TKEY, class TVAL>
inline THashTable<TKEY, TVAL>::THashTable(int s)
{
	this->count = 0;
	size = s;
	if (s < 0)
		size = 0;
	data = new THashTableNode<TKEY, TVAL>* [size];
	for (int i = 0; i < size; i++)
		data[i] = nullptr;
}

template<class TKEY, class TVAL>
inline void THashTable<TKEY, TVAL>::ReSize(int s)
{
	this->count = 0;
	size = s;
	if (s < 0)
		size = 0;
	data = new THashTableNode<TKEY, TVAL>* [size];
	for (int i = 0; i < size; i++)
		data[i] = nullptr;
}

template<class TKEY, class TVAL>
inline int THashTable<TKEY, TVAL>::GetCount()
{
	return size;
}

template<class TKEY, class TVAL>
inline int THashTable<TKEY, TVAL>::Hash(const TKEY& key)
{
	std::hash<TKEY> hash_fn;
	size_t hash = hash_fn(key);
	return hash % size;
}

template<class TKEY, class TVAL>
inline THashTable<TKEY, TVAL>::THashTable(THashTable<TKEY, TVAL>&& p)
{
	this->count = p.count;
	size = p.size;
	data = p.data;
	p.count = 0;
	p.size = 0;
	p.data = nullptr;
}

template<class TKEY, class TVAL>
inline THashTable<TKEY, TVAL>::THashTable(const THashTable<TKEY, TVAL>& p)
{
	this->count = p.count;
	size = p.size;
	data = new THashTableNode<TKEY, TVAL>* [size];
	for (int i = 0; i < size; i++)
		data[i] = p.data[i];
}

template<class TKEY, class TVAL>
inline THashTable<TKEY, TVAL>::~THashTable()
{
	if (data != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] != nullptr)
				delete data[i];
		}
		delete[] data;
		data = nullptr;
		count = 0;
		size = 0;

	}
}

template<class TKEY, class TVAL>
inline TVAL THashTable<TKEY, TVAL>::Find(const TKEY& k)
{
	int hash = Hash(k);
	if (data[hash] == nullptr)
		throw std::out_of_range("eror");
	else
	{
		auto cur = data[hash]->Find(k);
		if (cur != nullptr)
			return cur->GetValue();

	}
}

template<class TKEY, class TVAL>
inline void THashTable<TKEY, TVAL>::Del(const TKEY& k)
{
	int hash = Hash(k);
	if (data[hash]!= nullptr)
	{
		auto cur = data[hash]->Find(k);
		data[hash] = cur->Del();
		delete cur;
	}
}

template<class TKEY, class TVAL>
inline void THashTable<TKEY, TVAL>::Add(TKEY k, TVAL v)
{
	int hash = Hash(k);
	if (data[hash] == nullptr)
	{
		data[hash] = new THashTableNode<TKEY, TVAL>(k,v);
	}
	else
	{
		data[hash]->Add(k, v);
	}
}

template<class TKEY, class TVAL>
inline TVAL& THashTable<TKEY, TVAL>::operator[](const TKEY& k)
{
	int hash = Hash(k);
	if (data[hash] == nullptr)
		throw "not found";
	else
	{
		auto cur = data[hash]->Find(k);
		if (cur != nullptr)
			return cur->GetValue();
		else
			throw "not found";
	}
}
