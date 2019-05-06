#ifndef _ARRAY_
#define _ARRAY_
//写模板时，必须将声明和定义写在同一个文件夹中
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
	Array(int sz = 50);             //构造函数
	Array(const Array<T>& a);       //复制构造函数 
	~Array();                       //析构函数

	Array<T>& operator = (const Array<T>& rhs);   //重载=号运算符
	T& operator [] (int i);                       //重载[]
	const T& operator [] (int i) const;
	operator T* ();                               //重载T*类型的转换
	operator const T* () const;

	int GetSize() const;
	void Resize(int sz);

private:
	T* list;          //用于存放动态分配的数组内存首地址
	int size;         //数组大小（数组元素个数）

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
Array<T>::Array(const Array<T>& a)      //复制构造函数(深复制)
{
	this->size = a.size;
	this->list = new T[size];
	for (int i = 0; i < size; i++)
		this->list[i] = a.list[i];
}

template <class T>
Array<T>& Array<T>::operator = (const Array<T>& rhs)  //深层赋值
{                                                     //=号要求返回值必须是左值，所以必须返回引用
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
T& Array<T>::operator [] (int i)          //返回值必须是左值
{
	assert(i >= 0 && i < this->size);     //检查下标是否越界
	return this->list[i];
}

template <class T>
const T& Array<T>::operator [] (int i) const
{
	assert(i >= 0 && i < this->size);     //检查下标是否越界
	return this->list[i];
}

template <class T>
Array<T>::operator T* ()                 //语法要求不能定义返回值类型
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



