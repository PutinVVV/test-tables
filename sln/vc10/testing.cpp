#include "TPolynom.h"
#include "TTable.h"
#include "TTreeTable.h"
#include "TTableSort.h"
#include "THashTable.h"
#include "TTableTestkit.h"
#include <iostream>

int main()
{



	TTreeTable<int, TPolynom<int>> table(1);
	//std::stack<unsigned int> b = AddT(table, 1000);
	//b = DelT(table);
	FullT( 1000);
	//while (!b.empty()) {
		//double t = b.top();
		//t = t / (double) 1000;
		//std::cout << t << std::endl;
		//b.pop();
	//}


	return 0;









	//TTreeNode<int, float> w(4, 5);
	//TTreeTable<int, float> q;
	//q.Add(8, 8);
	//q.Add(4, 4);
	//q.Add(12, 12);
	//q.Add(2, 2);
	//q.Add(10, 10);
	//q.Add(6, 6);
	//q.Add(14, 14);
	//int k = 14;
	//auto a= q.Find(k);
	//cout << q;
	//return 0;



	//TNode<int, float> w0(0, 0.1);
	//TNode<int, float> w1(1, 0.2);
	//TNode<int, float> w2(2, 0.3);
	//TNode<int, float> w3(3, 0.4);
	//TNode<int, float> w4(4, 0.5);
	//TNode<int, float> w5(5, 0.6);
	//TNode<int, float> w6(6, 0.7);
	//TNode<int, float> w7(-10, 0.7);
	//TNode<int, float> w8(102, 0.7);
	//TTableSort<int, float> v(10);
	//v.Add(w1);
	//v.Add(w4);
	//v.Add(w3);
	//v.Add(w2);
	//v.Add(w5);
	//v.Add(w6);
	//v.Add(w0);
	//v.Add(w8);
	//v.Add(w7);
	//v.Add(w1);
	//cout << v;
	//int kl = w8.GetKey();
	//v.Del(kl);
	//cout << v;
	//return 0;























	//TVector<int> v(2);
	//TVector<int> v1(3);
	//TTable<int, float> v2311(10);
	//v2311.Add(1, 0.1);
	//v2311.Add(2, 0.1);

	//v[0] = 1; v[1] = 2;
	//v1[0] = 2; v1[1] = 3; v1[2] = 4;
	//TMonom<int> *w= new TMonom<int>[2];
	//w[0].Set(1, v);
	//w[1].Set(2, v1);
	//TMonom<int>* w2 = new TMonom<int>[2];
	//w2[0].Set(3, v1);
	//w2[1].Set(4, v);
	//TPolynom<int> q,z;
	//q.Set(2,w);
	//z.Set(2, w2);
	//cout << z << endl;
	//cout << q << endl;
	//z = z + q;
	//cout << z << endl;
	//cout << v2311 << endl;
	//TPolynom<int> m;
	//cout << v << endl;
	//cout << w.GetDeg() << endl;
	//cout << w.GetDim() << endl;
	//cout << w << endl;
	//cout << e << endl;
	//e = e * w;
	//cout << e << endl;


	//TMonom<int>* w = new TMonom<int>[2];
	//w[0].Set(4, v);	w[1].Set(5, v1);
	//TPolynom<int> m;
	//m.Set(2, w);
	//m.GetMonom(1);
	//getchar();
	//return 0;
}