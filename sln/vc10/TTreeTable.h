#pragma once
#include <iostream>
#include "TTreeNode.h"
#include "TQueue.h"
#include <queue>
using namespace std;
template <class TKEY, class TVAL>
class TTreeTable
{
protected:
	TTreeNode<TKEY, TVAL>* root;
	int count;
public:
	TTreeTable();
	TTreeTable(int s);
	TTreeTable(const TTreeTable<TKEY, TVAL>& p);
	TTreeTable(TTreeTable<TKEY, TVAL>&& p);
	~TTreeTable();
	void Clear();
	TVAL& operator[](const TKEY k);
	TVAL Find(const TKEY& k);
	void Add(TKEY k, TVAL v);
	void Del(const TKEY& k);
	void ReSize(int s);
	int GetCount();
	friend ostream& operator<<(ostream& out, const TTreeTable& v)
	{
		std::queue<TTreeNode<TKEY, TVAL>*> tmp1;
		tmp1.push(v.root);

		while (!tmp1.empty())
		{
			TTreeNode<TKEY, TVAL>* cur1 = tmp1.front();
			tmp1.pop();

			if (cur1->left != nullptr)
				tmp1.push(cur1->left);
			if (cur1->right != nullptr)
				tmp1.push(cur1->right);

			out << *cur1;
		}

		return out;

	}
};

template<class TKEY, class TVAL>
inline TTreeTable<TKEY, TVAL>::TTreeTable()
{
	root = nullptr;

	count = 0;
}

template<class TKEY, class TVAL>
inline TTreeTable<TKEY, TVAL>::TTreeTable(int s)
{
	root = nullptr;

	count = 0;
}

template<class TKEY, class TVAL>
inline TTreeTable<TKEY, TVAL>::TTreeTable(const TTreeTable<TKEY, TVAL>& p)
{
	if (p.root == nullptr) {
		root = nullptr;
		count = 0;
		return;
	}
	TQueue<TTreeNode<TKEY, TVAL>*> tmp1(count+p.count);
	TQueue<TTreeNode<TKEY, TVAL>*> tmp2(count + p.count);
	root = new TTreeNode<TKEY, TVAL>(*(p.root));
	tmp1.Push(root);
	tmp2.Push(p.root);
	while (!tmp1.IsEmpty())
	{
		TTreeNode<TKEY, TVAL>* cur1 = tmp1.Pull();
		TTreeNode<TKEY, TVAL>* cur2 = tmp2.Pull();
		if (cur2->left != nullptr)
		{
			cur1->left = new TTreeNode<TKEY, TVAL>(cur2->left->key, cur2->left->value);
			cur1->left->prev = cur1;
			tmp1.Push(cur1->left);
			tmp2.Push(cur2->left);
		}
		if (cur2->right != nullptr)
		{
			cur1->right = new TTreeNode<TKEY, TVAL>(cur2->right->key, cur2->right->value);
			cur1->right->prev = cur1;
			tmp1.Push(cur1->right);
			tmp2.Push(cur2->right);
		}
	}
	count = p.count;
}

template<class TKEY, class TVAL>
inline TTreeTable<TKEY, TVAL>::TTreeTable(TTreeTable<TKEY, TVAL>&& p)
{
	if (p.root == nullptr) {
		root = nullptr;
		count = 0;
		return;
	}
	TQueue<TTreeNode<TKEY, TVAL>*> tmp1(count + p.count);
	TQueue<TTreeNode<TKEY, TVAL>*> tmp2(count + p.count);
	root = new TTreeNode<TKEY, TVAL>(*(p.root));
	tmp1.Push(root);
	tmp2.Push(p.root);
	while (!tmp1.IsEmpty())
	{
		TTreeNode<TKEY, TVAL>* cur1 = tmp1.Pull();
		TTreeNode<TKEY, TVAL>* cur2 = tmp2.Pull();
		if (cur2->left != nullptr)
		{
			cur1->left = new TTreeNode<TKEY, TVAL>(cur2->left->key, cur2->left->value);
			cur1->left->prev = cur1;
			tmp1.Push(cur1->left);
			tmp2.Push(cur2->left);
		}
		if (cur2->right != nullptr)
		{
			cur1->right = new TTreeNode<TKEY, TVAL>(cur2->right->key, cur2->right->value);
			cur1->right->prev = cur1;
			tmp1.Push(cur1->right);
			tmp2.Push(cur2->right);
		}
	}
	count = p.count;
	p.Clear();
}

template<class TKEY, class TVAL>
inline TTreeTable<TKEY, TVAL>::~TTreeTable()
{
	this->Clear();
}

template<class TKEY, class TVAL>
inline void TTreeTable<TKEY, TVAL>::Clear()
{
	TQueue<TTreeNode<TKEY, TVAL>*> tmp1(count);
	tmp1.Push(root);
	while (!tmp1.IsEmpty())
	{
		TTreeNode<TKEY, TVAL>* cur1 = tmp1.Pull();
		if (cur1->left != nullptr)
			tmp1.Push(cur1->left);
		if(cur1->right!= nullptr)
			tmp1.Push(cur1->right);
		delete cur1;
	}
	count = 0;
	root = nullptr; 
}

template<class TKEY, class TVAL>
inline TVAL& TTreeTable<TKEY, TVAL>::operator[](TKEY k)
{
	TTreeNode<TKEY, TVAL>* cur = root;
	TTreeNode<TKEY, TVAL>* prev = root;
	TTreeNode<TKEY, TVAL>* next = nullptr;
	while (cur != nullptr)
	{
		prev = cur;
		if (*cur == k)
			return cur->GetVal();
		else if (*cur > k)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}

	return root;
}

template<class TKEY, class TVAL>
inline TVAL TTreeTable<TKEY, TVAL>::Find(const TKEY& k)
{
	TTreeNode<TKEY, TVAL>* cur = root;
	while (cur != nullptr)
	{
		if (*cur == k)
			return cur->value;
		else if (*cur > k)
			cur = cur->left;
		else
			cur = cur->right;
	}
	throw ("not_found"); 
}

template<class TKEY, class TVAL>
inline void TTreeTable<TKEY, TVAL>::Add(TKEY k, TVAL v)
{
	TTreeNode<TKEY, TVAL>* cur = root;
	TTreeNode<TKEY, TVAL>* prev = nullptr;
	TTreeNode<TKEY, TVAL>* next = nullptr;

	while (cur != nullptr)
	{
		prev = cur;
		if (*cur == k)
			throw ("Invalid key");
		else if (*cur > k)
		{
			next = cur->left;
			cur = cur->left;
		}
		else
		{
			next = cur->right;
			cur = cur->right;
		}
	}

	if (prev == nullptr)
	{
		TTreeNode<TKEY, TVAL>* new_node = new TTreeNode<TKEY, TVAL>(k, v, nullptr);
		root = new_node;
	}
	else
	{
		if (prev->key > k)
		{
			TTreeNode<TKEY, TVAL>* new_node = new TTreeNode<TKEY, TVAL>(k, v, prev);
			prev->left = new_node;
		}
		else
		{
			TTreeNode<TKEY, TVAL>* new_node = new TTreeNode<TKEY, TVAL>(k, v, prev);
			prev->right = new_node;
		}
	}

	count++;
}

template<class TKEY, class TVAL>
inline void TTreeTable<TKEY, TVAL>::Del(const TKEY& k)
{
	TTreeNode<TKEY, TVAL>* cur = root;
	TTreeNode<TKEY, TVAL>* prev = nullptr;
	TTreeNode<TKEY, TVAL>* next = nullptr;


	while (cur != nullptr)
	{
		prev = cur;
		if (*cur == k)
			break;
		else if (*cur > k)
		{
			next = cur->left;
			cur = cur->left;
		}
		else
		{
			next = cur->right;
			cur = cur->right;
		}
	}

	if (cur == nullptr)
		throw ("Key not found");


	if (cur->left == nullptr && cur->right == nullptr)
	{
		if (prev->left == cur)
			prev->left = nullptr;
		else
			prev->right = nullptr;
		delete cur;
		count--;
	}

	else if (cur->left == nullptr)
	{
		if (prev->left == cur)
			prev->left = cur->right;
		else
			prev->right = cur->right;
		cur->right->prev = prev;
		delete cur;
		count--;
	}
	else if (cur->right == nullptr)
	{
		if (prev->left == cur)
			prev->left = cur->left;
		else
			prev->right = cur->left;
		cur->left->prev = prev;
		delete cur;
		count--;
	}

	else
	{
		next = cur->right;
		while (next->left != nullptr)
			next = next->left;


		cur->key = next->key;
		cur->value = next->value;


		if (next->right != nullptr)
		{
			next->right->prev = next->prev;
			next->prev->left = next->right;
		}
		else
		{
			if (next->prev->left == next)
				next->prev->left = nullptr;
			else
				next->prev->right = nullptr;
		}
		delete next;
		count--;
	}
}

template<class TKEY, class TVAL>
inline void TTreeTable<TKEY, TVAL>::ReSize(int s)
{
	count++;
	count--;
}

template<class TKEY, class TVAL>
inline int TTreeTable<TKEY, TVAL>::GetCount()
{
	return count;
}
