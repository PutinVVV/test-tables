#include "TMonom.h"

#include <gtest.h>

TEST(TMonom, can_create_Monom_with_positive_length)
{
	ASSERT_NO_THROW(TMonom<int> v);
}

TEST(TMonom, can_Set)
{
	TVector<int> v(2);

	v[0] = 1; v[1] = 2;
	TMonom<int> w;
	ASSERT_NO_THROW(w.Set(4,v));
}

TEST(TMonom, can_plus_c)
{
	TVector<int> v(2);
	TVector<int> v1(2);

	v[0] = 1; v[1] = 2;
	v1[0] = 1; v1[1] = 2;
	TMonom<int> w,w1;
	w.Set(4, v);
	w1.Set(3, v1);
	w =w + w1;
	ASSERT_EQ(w.GetDim(),7);
}

TEST(TMonom, can_plus_deg)
{
	TVector<int> v(2);
	TVector<int> v1(2);

	v[0] = 1; v[1] = 2;
	v1[0] = 1; v1[1] = 2;
	TMonom<int> w, w1;
	w.Set(4, v);
	w1.Set(3, v1);
	w = w + w1;
	ASSERT_EQ(w.GetDeg(), v);
}

TEST(TMonom, can_sub_deg)
{
	TVector<int> v(2);
	TVector<int> v1(2);
	TVector<int> v2(2);
	v[0] = 1; v[1] = 2;
	v1[0] = 1; v1[1] = 2;
	v2[0] = 2; v2[1] = 4;
	TMonom<int> w, w1;
	w.Set(4, v);
	w1.Set(3, v1);
	w = w * w1;
	ASSERT_EQ(w.GetDeg(), v2);
}

TEST(TMonom, can_sub_degnumtwo)
{
	TVector<int> v(2);
	TVector<int> v1(5);
	TVector<int> v2(5);
	v[0] = 1; v[1] = 2;
	v1[0] = 1; v1[1] = 2; v1[2] = 2; v1[3] = 5; v1[4] = 7;
	v2[0] = 2; v2[1] = 4; v2[2] = 2; v2[3] = 5; v2[4] = 7; 
	TMonom<int> w, w1;
	w.Set(4, v);
	w1.Set(3, v1);
	w = w * w1;
	ASSERT_EQ(w.GetDeg(), v2);
}

TEST(TMonom, can_sub_c)
{
	TVector<int> v(2);
	TVector<int> v1(2);
	v[0] = 1; v[1] = 2;
	v1[0] = 1; v1[1] = 2;
	TMonom<int> w, w1;
	w.Set(4, v);
	w1.Set(3, v1);
	w = w * w1;
	ASSERT_EQ(w.GetDim(), 12);
}