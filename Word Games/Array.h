#pragma once
#include<cassert>
#include<typeinfo>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
template<class T>
class Array
{
private:
	T* list;
	int size;
public:
	Array(int sz = 0); //���캯��
	Array(const Array<T>&a); //���ƹ��캯��
	~Array(); //��������
	T* getList() { return list; }
	int getSize() { return size; }
	T* getEnd() { return list + size;}
	Array<T>& operator=(const Array<T>&rhs); //����=�����
	T& operator[](int i); //����[]�����
	const T& operator[](int n)const; //����[]�����
	operator T*(); //����ָ��ת�������
	operator const T*()const; //����ָ��ת�������
	int getSize() const; //��ȡArray��Сsize
	void resize(int sz); //����Array��С
	T function(Array<T> &a); //����Array����Ͳ���
	void swap(T* a, T* b); //������Ԫ��
	void sort(); //����
	void find(T goal); //����
	void print(); //��ӡ
};
template<class T>
Array<T>::Array(int sz) :size(sz)
{
	assert(sz >= 0);
	list = new T[size];
}
template<class T>
Array<T>::~Array()
{
	delete[] list;
}
template<class T>
Array<T>::Array(const Array<T> &a) :size(a.size)
{
	list = new T[size];
	for (int i = 0; i < size; i++)
		list[i] = a.list[i];
	//cout << "Copy constructor" << endl;
}
template<class T>
Array<T>& Array<T>::operator=(const Array<T> &rhs)
{
	if (&rhs != this)
	{
		if (size != rhs.size)
		{
			delete[] list;
			size = rhs.size;
			list = new T[size];
		}
		for (int i = 0; i < size; i++)
			list[i] = rhs.list[i];
	}
	cout << "Equal" << endl;
	return *this;//��������
}
template<class T>
T& Array<T>::operator[](int n)
{
	assert(n >= 0 && n < size);
	return list[n];
}
template<class T>
const T& Array<T>::operator[](int n)const
{
	assert(n >= 0 && n < size);
	return list[n];
}
template<class T>
Array<T>::operator T*()
{
	return list;
}
template<class T>
Array<T>::operator const T*()const
{
	return list;
}
template<class T>
int Array<T>::getSize()const
{
	return size;
}
template<class T>
void Array<T>::resize(int sz)
{
	assert(size >= 0);
	if (size == sz)return;
	T* newList = new T[sz];
	int n = (sz < size) ? sz : size;
	for (int i = 0; i < n; i++)
		newList[i] = list[i];
	delete[] list;
	list = newList;
	size = sz;
}
//
template<class T>
T Array<T>::function(Array<T> &a)
{
	assert(size == a.getSize());
	T sum = 0;
	for (int i = 0; i < a.getSize(); i++)
		sum += a[i] * list[i];
	return sum;
}
//
template<class T>
void Array<T>::sort()
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		int j;
		for (j = i + 1; j < size; j++)
			if (list[min] > list[j])min = j;
		swap(&list[min], &list[i]);
	}
}
template<class T>
void Array<T>::swap(T* a, T* b)
{
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

template<class T>
void Array<T>::find(T goal)
{
	for (int i = 0; i < size; i++)
		if (list[i] == goal)
		{
			cout << "Found ! Location : " << i + 1 << endl;
			return;
		}
	cout << "Not Found ! " << endl;
	return;
}
template<class T>
void Array<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << setw(2) << "No" << i + 1 << "  " << list[i] << endl;
}


