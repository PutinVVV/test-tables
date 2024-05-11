#pragma once

	using namespace std;
	template<class T>
	class TQueue
	{
	protected:
		T* data;
		int size;
		int start, end;
	public:
		TQueue(int _size = 10);          //конструктор инициализации и по умолчанию
		~TQueue() { delete[] data; size = 0; start = 0; end = 0; };       //деструктор
		TQueue(const TQueue<T>& p);      //конструктор копирования 
		bool IsEmpty();                  //проверка на пустоту
		bool IsFull(); 
		bool Est(const T& d);//проверка на полноту
		int GetCoun();
		T Pull();                         //извлечь элемент
		void Push(const T& a);           //записать элемент в стек
	};
	template<class T>
	inline TQueue<T>::TQueue(int _size)
	{
		if (_size < 0) throw ("error");
		size = _size;
		start = 0;
		end = 0;
		data = new T[size];
	}
	template<class T>
	inline TQueue<T>::TQueue(const TQueue<T>& p)
	{
		size = p.size;
		start = p.start;
		end = p.end;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = p.data[i];
	}
	template<class T>
	inline bool TQueue<T>::IsEmpty()
	{
		if (end == start)
			return true;
	}
	template<class T>
	inline bool TQueue<T>::IsFull()
	{
		if (end == size)
			return true;
	}
	template<class T>
	inline bool TQueue<T>::Est(const T& d)
	{
		for (int i = 0; i < size; i++)
			if (data[i] == d)
				return true;
		return false;
	}
	template<class T>
	inline int TQueue<T>::GetCoun()
	{
		return (end - start);
	}
	template<class T>
	inline T TQueue<T>::Pull()
	{
		if ((start < size) && (start > 0))
		{
			T a = data[start];
			start++;
			return a;
		}
		else throw "error";
	}
	template<class T>
	inline void TQueue<T>::Push(const T& a)
	{
		if (end < size)
		{
			data[end] = a;
			end++;
		}

	}
