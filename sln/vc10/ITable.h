#pragma once

template <class TKEY, class TVAL>
class ITable
{
protected:
	int count;
public:
	virtual TVAL Find(const TKEY& key) = 0;
	virtual void Del(const TKEY& key) = 0;
	virtual void Add(TKEY key, TVAL value) = 0;
	virtual TVAL& operator[] (const TKEY& key) = 0;
	virtual int GetCount();
};

template<class TKEY, class TVAL>
inline int ITable<TKEY, TVAL>::GetCount()
{
	return count;
}
