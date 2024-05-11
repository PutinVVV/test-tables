#pragma once
#include "TPolynom.h"
#include <ctime>
#include <cstdlib>
#include <stack>
#include <chrono>
#include <cmath>
#include "TPolynom.h"
#include "TTable.h"
#include "TTreeTable.h"
#include "TTableSort.h"
#include "THashTable.h"
#include "TTableTestkit.h"
#include <iostream>
#include <typeinfo> 

template <class T>
std::stack<unsigned int> AddT( T &table, int size)
{
	std::stack<unsigned int > vstavka;
	int randNum = rand();
	unsigned int search_time, search_t;
	TVector<int> b(3);
	table.ReSize(size);
	auto start_t = chrono::high_resolution_clock::now();
	for (int i = 1; i < size-1; i++) {
		b[0] = randNum; b[1] = randNum; b[2] = randNum;
		TPolynom<int> a(randNum, b);
		if(i!=size/2)
			table.Add(i, a);
	}
	auto end_t = chrono::high_resolution_clock::now();
	search_t = chrono::duration_cast<chrono::microseconds>(end_t - start_t).count();
	vstavka.push(search_t);
	// 0 el
	b[0] = randNum; b[1] = randNum; b[2] = randNum;
	auto start_time = chrono::high_resolution_clock::now();
	TPolynom<int> a(randNum, b);
	table.Add(0, a);
	auto end_time = chrono::high_resolution_clock::now();
	search_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	vstavka.push(search_time);
	//seredina
	b[0] = randNum; b[1] = randNum; b[2] = randNum;
	start_time = chrono::high_resolution_clock::now();
	TPolynom<int>  bc(randNum, b);
	table.Add(size/2, bc);
	end_time = chrono::high_resolution_clock::now();
	search_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	vstavka.push(search_time);
	//konets
	b[0] = randNum; b[1] = randNum; b[2] = randNum;
	start_time = chrono::high_resolution_clock::now();
	TPolynom<int> c(randNum, b);
	table.Add(size-1, c);
	end_time = chrono::high_resolution_clock::now();
	search_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	vstavka.push(search_time);
	return vstavka;
}

template <class T>
std::stack<unsigned int> FindT(T& table)
{
	std::stack<unsigned int> stak;
	int size = table.GetCount();
	//0 element
	auto start_time = chrono::high_resolution_clock::now();
	table.Find(0);
	auto end_time = chrono::high_resolution_clock::now();
	auto search_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	stak.push(search_time);
	// size/2 element
	start_time = chrono::high_resolution_clock::now();
	table.Find((size) / 2);
	end_time = chrono::high_resolution_clock::now();
	search_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	stak.push(search_time);
	// size element
	start_time = chrono::high_resolution_clock::now();
	table.Find(size-1);
	end_time = chrono::high_resolution_clock::now();
	search_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
  stak.push(search_time);
	return stak;
}

template <class T>
std::stack<unsigned int> DelT(T& table)
{
	std::stack<unsigned int> stak;
	int size = table.GetCount();
	//0 element
	auto start_time = chrono::high_resolution_clock::now();
	table.Del(0);
	auto end_time = chrono::high_resolution_clock::now();
	auto search_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	stak.push(search_time);
	// size/2 element
	start_time = chrono::high_resolution_clock::now();
	table.Del((size) / 2);
	end_time = chrono::high_resolution_clock::now();
	search_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	stak.push(search_time);
	// size element
	start_time = chrono::high_resolution_clock::now();
	table.Del(size - 1);
	end_time = chrono::high_resolution_clock::now();
	search_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	stak.push(search_time);
	return stak;
}

template <class T>
void TestT(T& table, int size)
{
	cout << typeid(table).name() << " :" << endl;
	cout << "|......IN THE END......|......IN THE MIDLE......|......IN THE START......|......FULL TIME......|" << endl;
	std::stack<unsigned int> stak= AddT(table,size);
	cout << "|ADD :";// вставка
	while (!stak.empty()) {
		double t = stak.top();
		t = t / (double)1000;
		cout << "|......" << t << "msec......";
		stak.pop();
	}
	cout << "|" << endl;
	stak = FindT(table);//поиск
	cout << "|Find :";
	while (!stak.empty()) {
		double t = stak.top();
		t = t / (double)1000;
		cout << "|......" << t << "msec......";
		stak.pop();
	}
	cout << "|" << endl;
	stak = DelT(table);//удаление
	cout << "|DEL :";
	while (!stak.empty()) {
		double t = stak.top();
		t = t / (double)1000;
		cout << "|......" << t << "msec......";
		stak.pop();
	}
	cout << "|" << endl;
	
}

void FullT(int size)
{
	TTable<int, TPolynom<int>> table(1);
	TTableSort<int, TPolynom<int>> tableS(1);
	TTreeTable<int, TPolynom<int>> tableT(1);
	THashTable<int, TPolynom<int>> tableH(1);
	TestT(table, size);
	TestT(tableS, size);
	TestT(tableT, size);
	TestT(tableH, size);
}