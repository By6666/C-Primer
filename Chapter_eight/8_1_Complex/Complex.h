//����ǰ��++�����++�ǣ��﷨�涨�����ں���++����ʱ���һ���βΣ�int��
//����βε�Ψһ���þ�������ǰ�úͺ��ð汾�ĺ��������������Ҫ��ʵ�ֺ��ð汾�ǲ������㡣
//��Ϊǰ�úͺ��ð汾�ĵ������ߵݼ�����ԭ�ͱ������һ����������֣�c++����ѡ������һ��ռλ����ʵ�ֺ��ð汾


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
	//Complex operator + (const Complex&c2) const; //�����+���س�Ա����,����+����
	//Complex operator - (const Complex&c2) const; //�����-���س�Ա����

	//Complex operator + (const int& c2) const; //�����+���س�Ա����������+����
	//Complex operator - (const int& c2) const; //�����+���س�Ա����

	//Complex& operator ++();        //ǰ��++
	//Complex  operator ++(int);      //����++  

	void display() const;

	friend Complex operator +(const Complex&c1, const Complex&c2);      //�������Ԫ����
	friend Complex operator -(const Complex&c1, const Complex&c2);
	friend Complex& operator ++(Complex&c1);                       //ǰ��++
	friend Complex operator ++(Complex&c1,int);                   //����++
	friend ostream& operator <<(ostream&out, const Complex&c);           //���ز��������

private:
	double 
		real,    //����ʵ��
		imag;    //�����鲿
};

//Complex Complex::operator + (const Complex&c2) const
//{  //����һ����ʱ����������Ϊ����ֵ
//	return Complex(real + c2.real, imag + c2.imag);
//}
//
//Complex Complex::operator - (const Complex&c2) const
//{  //����һ����ʱ����������Ϊ����ֵ
//	return Complex(real - c2.real, imag - c2.imag);
//}

//Complex Complex::operator + (const int& c2) const //�����+���س�Ա����
//{
//	return Complex(real + c2, imag);   //�����ķ�����ʽ����Ҫ���ø��ƹ��캯��
//}
//Complex Complex::operator - (const int& c2) const //�����+���س�Ա����
//{
//	return Complex(real - c2, imag);
//}

//Complex& Complex::operator ++()        //ǰ��++
//{
//	real++;
//	return *this;
//}
//Complex Complex::operator ++(int)     //����++
//{
//	Complex old = *this;
//	++(*this);
//	return old;
//}


#endif // !_COMPLEX_


