#include "TNode.h"

#include <gtest.h>

TEST(TNode, bool_less)
{
	TNode<int, int> v1(1,1);
	TNode<int, int> v2(2,2);
	ASSERT_EQ(true,v1<v2);
}
TEST(TNode, bool_more)
{
	TNode<int, int> v1(1, 1);
	TNode<int, int> v2(2, 2);
	ASSERT_EQ(false, v1 > v2);
}
TEST(TNode, bool_eq_false)
{
	TNode<int, int> v1(1, 1);
	TNode<int, int> v2(2, 2);
	ASSERT_EQ(false, v1 == v2);
}
TEST(TNode, bool_eq_true)
{
	TNode<int, int> v1(1, 1);
	TNode<int, int> v2(1, 2);
	ASSERT_EQ(true, v1 == v2);
}
TEST(TNode, prisvoenie)
{
	TNode<int, int> v1(1, 1);
	TNode<int, int> v2=v1;
	ASSERT_EQ(true, v2==v1);
}
TEST(TNode, copirovanie)
{
	TNode<int, int> v1(1, 1);
	TNode<int, int> v2(v1);
	ASSERT_EQ(true, v2 == v1);
}
TEST(TNode, can_get_key_eq)
{
	TNode<int, int> v(10,10);
	ASSERT_EQ(10, v.GetKey());
}
TEST(TNode, can_get_val_eq)
{
	TNode<int, int> v(10, 10);
	ASSERT_EQ(10, v.GetVal());
}
