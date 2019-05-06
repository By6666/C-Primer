#ifndef _ARRAY_
#define _ARRAY_
//дģ��ʱ�����뽫�����Ͷ���д��ͬһ���ļ�����
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

template <class T>
class Array
{
public:
	Array(int sz = 50);             //���캯��
	Array(const Array<T>& a);       //���ƹ��캯�� 
	~Array();                       //��������

	Array<T>& operator = (const Array<T>& rhs);   //����=�������
	T& operator [] (int i);                       //����[]
	const T& operator [] (int i) const;
	operator T* ();                               //����T*���͵�ת��
	operator const T* () const;

	int GetSize() const;
	void Resize(int sz);

private:
	T* list;          //���ڴ�Ŷ�̬����������ڴ��׵�ַ
	int size;         //�����С������Ԫ�ظ�����

};

template <class T>
Array<T>::Array(int sz)
{
	assert(sz >= 0);
	this->size = sz;
	this->list = new T[size];
}

template <class T>
Array<T>::~Array()
{
	delete[] this->list;
}

template <class T>
Array<T>::Array(const Array<T>& a)      //���ƹ��캯��(���)
{
	this->size = a.size;
	this->list = new T[size];
	for (int i = 0; i < size; i++)
		this->list[i] = a.list[i];
}

template <class T>
Array<T>& Array<T>::operator = (const Array<T>& rhs)  //��㸳ֵ
{                                                     //=��Ҫ�󷵻�ֵ��������ֵ�����Ա��뷵������
	if (&rhs != this)
	{
		if (this->size != rhs.size)
		{
			delete[] this->list;
			this->size = rhs.size;
			this->list = new T[size];
		}
		for (int i = 0; i < size; i++)
			this->list[i] = rhs.list[i];
	}
	return *this;
}
template <class T>
T& Array<T>::operator [] (int i)          //����ֵ��������ֵ
{
	assert(i >= 0 && i < this->size);     //����±��Ƿ�Խ��
	return this->list[i];
}

template <class T>
const T& Array<T>::operator [] (int i) const
{
	assert(i >= 0 && i < this->size);     //����±��Ƿ�Խ��
	return this->list[i];
}

template <class T>
Array<T>::operator T* ()                 //�﷨Ҫ���ܶ��巵��ֵ����
{
	return this->list;
}

template <class T>
Array<T>::operator const T* () const
{
	return this->list;
}

template <class T>
int Array<T>::GetSize() const
{
	return this->size;
}

template <class T>
void Array<T>::Resize(int sz)
{
	assert(sz >= 0);
	if (sz == this->size)   return;

	T* newlist = new T[sz];
	int n = (sz < this->size) ? sz : this->size;

	for (int i = 0; i < n; i++)
		newlist[i] = this->list[i];

	delete[] this->list;
	this->list = newlist;
	this->size = sz;
}

#endif // !_ARRAY_



