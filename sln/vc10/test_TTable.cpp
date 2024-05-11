#include "TTable.h"

#include <gtest.h>

TEST(TTable, can_get_size)
{
	TTable<int, int> v(10);
	ASSERT_EQ(10,v.GetSize());
}

TEST(TTable, can_get_count)
{
	TTable<int, int> v(10);
	v.Add(1, 1);
	v.Add(2, 2);
	ASSERT_EQ(2, v.GetCount());
}

TEST(TTable, operator_dostupa)
{
	TTable<int, float> v(10);
	v.Add(1, 0.1);
	v.Add(2, 0.1);
	float i = v[1];
	ASSERT_EQ(1, 1);
}

TEST(TTableTests, Test_DefaultConstructor)
{
  TTable<int, int> table;
  EXPECT_EQ(table.GetCount(), 0);
  EXPECT_EQ(table.GetSize(), 1);
}

TEST(TTableTests, Test_ConstructorWithSize)
{
  TTable<int, int> table(5);
  EXPECT_EQ(table.GetCount(), 0);
  EXPECT_EQ(table.GetSize(), 5);
}

TEST(TTableTests, Test_CopyConstructor)
{
  TTable<int, int> table(5);
  table.Add(1, 2);
  table.Add(3, 4);

  TTable<int, int> copy(table);
  EXPECT_EQ(copy.GetCount(), 2);
  EXPECT_EQ(copy.GetSize(), 5);
}

