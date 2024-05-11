#include <gtest.h>
#include "THashTable.h"


TEST(HashTableTest, AddAndFind) {
  THashTable<int, char> table(100);
  table.Add(1, 'A');
  EXPECT_EQ('A', table.Find(1));
}


TEST(HashTableTest, Delete) {
  THashTable<int, char> table(100);
  table.Add(1, 'A');
  table.Del(1);
  EXPECT_THROW(table.Find(1), std::out_of_range);
}

TEST(HashTableTest, BracketOperator) {
  THashTable<int, char> table(100);
  table.Add(1, 'A');
  EXPECT_EQ('A', table[1]);
}

