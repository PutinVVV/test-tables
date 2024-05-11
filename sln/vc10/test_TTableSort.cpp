#include "TTableSort.h"

#include <gtest.h>

TEST(TTableSort, can_get_value)
{
	TNode<int, float> w0(0, 0.1);
	TNode<int, float> w1(1, 0.2);
	TNode<int, float> w2(2, 0.3);
	TNode<int, float> w3(3, 0.4);
	TNode<int, float> w4(4, 0.5);
	TNode<int, float> w5(5, 0.6);
	TNode<int, float> w6(6, 0.7);
	TNode<int, float> w7(-10, 0.7);
	TNode<int, float> w8(102, 0.7);
	TTableSort<int, float> v(10);
	v.Add(w1);
	v.Add(w4);
	v.Add(w3);
	v.Add(w2);
	v.Add(w5);
	v.Add(w6);
	v.Add(w0);
	v.Add(w8);
	v.Add(w7);
	v.Add(w1);
	float d = v.Find(5);
	float con = 0.6;
	ASSERT_EQ(con,d);
}
TEST(TTableSort, can_delete)
{
	TNode<int, float> w0(0, 0.1);
	TNode<int, float> w1(1, 0.2);
	TNode<int, float> w2(2, 0.3);
	TNode<int, float> w3(3, 0.4);
	TNode<int, float> w4(4, 0.5);
	TNode<int, float> w5(5, 0.6);
	TNode<int, float> w6(6, 0.7);
	TNode<int, float> w7(-10, 0.7);
	TNode<int, float> w8(102, 0.7);
	TTableSort<int, float> v(10);
	v.Add(w1);
	v.Add(w4);
	v.Add(w3);
	v.Add(w2);
	v.Add(w5);
	v.Add(w6);
	v.Add(w0);
	v.Add(w8);
	v.Add(w7);
	v.Add(w1);
	int kl = w8.GetKey();
	ASSERT_NO_THROW(v.Del(kl));
}
TEST(TTableSort, can_dostup_skobki)
{
	TNode<int, float> w0(0, 0.1);
	TNode<int, float> w1(1, 0.2);
	TNode<int, float> w2(2, 0.3);
	TNode<int, float> w3(3, 0.4);
	TNode<int, float> w4(4, 0.5);
	TNode<int, float> w5(5, 0.6);
	TNode<int, float> w6(6, 0.7);
	TNode<int, float> w7(-10, 0.7);
	TNode<int, float> w8(102, 0.7);
	TTableSort<int, float> v(10);
	v.Add(w1);
	v.Add(w4);
	v.Add(w3);
	v.Add(w2);
	v.Add(w5);
	v.Add(w6);
	v.Add(w0);
	v.Add(w8);
	v.Add(w7);
	v.Add(w1);
	int kl = 5;
	ASSERT_NO_THROW(v[kl]);
}
TEST(TTableSort, can_get_count)
{
	TNode<int, float> w0(0, 0.1);
	TNode<int, float> w1(1, 0.2);
	TNode<int, float> w2(2, 0.3);
	TNode<int, float> w3(3, 0.4);
	TNode<int, float> w4(4, 0.5);
	TNode<int, float> w5(5, 0.6);
	TNode<int, float> w6(6, 0.7);
	TNode<int, float> w7(-10, 0.7);
	TNode<int, float> w8(102, 0.7);
	TTableSort<int, float> v(10);
	v.Add(w1);
	v.Add(w4);
	v.Add(w3);
	v.Add(w2);
	v.Add(w5);
	v.Add(w6);
	v.Add(w0);
	v.Add(w8);
	v.Add(w7);
	v.Add(w1);
	int kl = 5;
	ASSERT_EQ(10,v.GetCount());
}

TEST(TTableSort, can_size)
{
	TNode<int, float> w0(0, 0.1);
	TNode<int, float> w1(1, 0.2);
	TNode<int, float> w2(2, 0.3);
	TNode<int, float> w3(3, 0.4);
	TNode<int, float> w4(4, 0.5);
	TNode<int, float> w5(5, 0.6);
	TNode<int, float> w6(6, 0.7);
	TNode<int, float> w7(-10, 0.7);
	TNode<int, float> w8(102, 0.7);
	TTableSort<int, float> v(10);
	v.Add(w1);
	v.Add(w4);
	v.Add(w3);
	v.Add(w2);
	v.Add(w5);
	v.Add(w6);
	v.Add(w0);
	v.Add(w8);
	v.Add(w7);
	v.Add(w1);
	int kl = 5;
	ASSERT_EQ(10, v.GetSize());
}
TEST(TTableSort, can_resize_one)
{
	TNode<int, float> w0(0, 0.1);
	TNode<int, float> w1(1, 0.2);
	TNode<int, float> w2(2, 0.3);
	TNode<int, float> w3(3, 0.4);
	TNode<int, float> w4(4, 0.5);
	TNode<int, float> w5(5, 0.6);
	TNode<int, float> w6(6, 0.7);
	TNode<int, float> w7(-10, 0.7);
	TNode<int, float> w8(102, 0.7);
	TTableSort<int, float> v(10);
	v.Add(w1);
	v.Add(w4);
	v.Add(w3);
	v.Add(w2);
	v.Add(w5);
	v.Add(w6);
	v.Add(w0);
	v.Add(w8);
	v.Add(w7);
	v.Add(w1);
	int kl = 5;
	v.ReSize(5);
	ASSERT_EQ(v.GetSize(),5);
}
TEST(TTableSort, can_resize_two)
{
	TNode<int, float> w0(0, 0.1);
	TNode<int, float> w1(1, 0.2);
	TNode<int, float> w2(2, 0.3);
	TNode<int, float> w3(3, 0.4);
	TNode<int, float> w4(4, 0.5);
	TNode<int, float> w5(5, 0.6);
	TNode<int, float> w6(6, 0.7);
	TNode<int, float> w7(-10, 0.7);
	TNode<int, float> w8(102, 0.7);
	TTableSort<int, float> v(10);
	v.Add(w1);
	v.Add(w4);
	v.Add(w3);
	v.Add(w2);
	v.Add(w5);
	v.Add(w6);
	v.Add(w0);
	v.Add(w8);
	v.Add(w7);
	v.Add(w1);
	v.ReSize(5);
	ASSERT_EQ(v.GetCount(),5);
}
TEST(TTableSort, is_full_true)
{
	TNode<int, float> w0(0, 0.1);
	TNode<int, float> w1(1, 0.2);
	TNode<int, float> w2(2, 0.3);
	TNode<int, float> w3(3, 0.4);
	TNode<int, float> w4(4, 0.5);
	TNode<int, float> w5(5, 0.6);
	TNode<int, float> w6(6, 0.7);
	TNode<int, float> w7(-10, 0.7);
	TNode<int, float> w8(102, 0.7);
	TTableSort<int, float> v(10);
	v.Add(w1);
	v.Add(w4);
	v.Add(w3);
	v.Add(w2);
	v.Add(w5);
	v.Add(w6);
	v.Add(w0);
	v.Add(w8);
	v.Add(w7);
	v.Add(w1);
	v.ReSize(5);
	ASSERT_EQ(true,v.IsFull());
}
TEST(TTableSort, is_empty_true)
{
	TNode<int, float> w0(0, 0.1);
	TNode<int, float> w1(1, 0.2);
	TNode<int, float> w2(2, 0.3);
	TNode<int, float> w3(3, 0.4);
	TNode<int, float> w4(4, 0.5);
	TNode<int, float> w5(5, 0.6);
	TNode<int, float> w6(6, 0.7);
	TNode<int, float> w7(-10, 0.7);
	TNode<int, float> w8(102, 0.7);
	TTableSort<int, float> v(10);
	v.ReSize(5);
	ASSERT_EQ(true, v.IsEmpty());
}

TEST(TTableSort, add_with_k_v)
{
	int k = 10;
	TTableSort<int, int> v;
	v.Add(k+1, k-7);
	v.Add(k+100, k-6);
	v.Add(k, k);
	v.Add(k-1, k-5);
	ASSERT_EQ(k, v.Find(k));
}


