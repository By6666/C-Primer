//重载前置++与后置++是，语法规定必须在后置++定义时添加一个形参（int）
//这个形参的唯一作用就是区分前置和后置版本的函数，而不是真的要在实现后置版本是参与运算。
//因为前置和后置版本的递增或者递减函数原型必须加以一个特殊的区分，c++语言选择增加一个占位参数实现后置版本


#ifndef _COMPLEX_
#define _COMPLEX_

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

 extern int qwe;

class Complex
{
public:
	Complex(double r=0.0,double i=0.0)
		:real(r),imag(i)
	{}
//	Complex(const Complex&p){ cout << "copy succeed!!" << endl; }
	//Complex operator + (const Complex&c2) const; //运算符+重载成员函数,复数+复数
	//Complex operator - (const Complex&c2) const; //运算符-重载成员函数

	//Complex operator + (const int& c2) const; //运算符+重载成员函数，复数+整数
	//Complex operator - (const int& c2) const; //运算符+重载成员函数

	//Complex& operator ++();        //前置++
	//Complex  operator ++(int);      //后置++  

	void display() const;

	friend Complex operator +(const Complex&c1, const Complex&c2);      //类外的友元函数
	friend Complex operator -(const Complex&c1, const Complex&c2);
	friend Complex& operator ++(Complex&c1);                       //前置++
	friend Complex operator ++(Complex&c1,int);                   //后置++
	friend ostream& operator <<(ostream&out, const Complex&c);           //重载插入运算符

private:
	double 
		real,    //复数实部
		imag;    //复数虚部
};

//Complex Complex::operator + (const Complex&c2) const
//{  //创建一个临时无名对象作为返回值
//	return Complex(real + c2.real, imag + c2.imag);
//}
//
//Complex Complex::operator - (const Complex&c2) const
//{  //创建一个临时无名对象作为返回值
//	return Complex(real - c2.real, imag - c2.imag);
//}

//Complex Complex::operator + (const int& c2) const //运算符+重载成员函数
//{
//	return Complex(real + c2, imag);   //这样的返回形式不需要调用复制构造函数
//}
//Complex Complex::operator - (const int& c2) const //运算符+重载成员函数
//{
//	return Complex(real - c2, imag);
//}

//Complex& Complex::operator ++()        //前置++
//{
//	real++;
//	return *this;
//}
//Complex Complex::operator ++(int)     //后置++
//{
//	Complex old = *this;
//	++(*this);
//	return old;
//}


#endif // !_COMPLEX_


