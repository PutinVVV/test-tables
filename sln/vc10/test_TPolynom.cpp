#include "TPolynom.h"

#include <gtest.h>

TEST(TPolynom, can_create_TPolynom_with_positive_length)
{
	ASSERT_NO_THROW(TPolynom<int> v);
}

TEST(TPolynom, can_Set)
{
	TVector<int> v(2);
	TVector<int> v1(3);

	v[0] = 1; v[1] = 2;
	v1[0] = 2; v1[1] = 3; v1[2] = 4;
	TMonom<int> *w = new TMonom<int>[2];
	w[0].Set(4, v);	w[1].Set(5, v1);
	TPolynom<int> m;
	ASSERT_NO_THROW(m.Set(2, w));
}

TEST(TPolynom, can_get)
{
	TVector<int> v(2);
	TVector<int> v1(3);

	v[0] = 1; v[1] = 2;
	v1[0] = 2; v1[1] = 3; v1[2] = 4;
	TMonom<int>* w = new TMonom<int>[2];
	w[0].Set(4, v);	w[1].Set(5, v1);
	TPolynom<int> m;
	m.Set(2, w);
	ASSERT_NO_THROW(m.GetMonom(0));
}

TEST(TPolynom, can_adding_another)
{
	TVector<int> v(2);
	TVector<int> v1(3);
	TVector<int> v2(3);

	v[0] = 1; v[1] = 2;
	v1[0] = 2; v1[1] = 3; v1[2] = 4;
	v2[0] = 3; v2[1] = 5;
	TMonom<int>* w1 = new TMonom<int>[2];
	TMonom<int>* w2 = new TMonom<int>[2];
	w1[0].Set(4, v);	w1[1].Set(5, v1);
	w1[0].Set(5, v2);	w1[1].Set(7, v1);
	TPolynom<int> m1;
	m1.Set(2, w1);
	TPolynom<int> m2;
	m2.Set(2, w2);
	ASSERT_NO_THROW(m1=m2);
}