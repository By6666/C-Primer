#include "Complex.h"

Complex operator +(const Complex&c1, const Complex&c2)      //类外的友元函数
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator -(const Complex&c1, const Complex&c2)
{
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
Complex& operator ++(Complex&c1)                       //前置++
{
	c1.real++;
	c1.imag++;
	return c1;
}
Complex operator ++(Complex&c1, int)                   //后置++
{
	++c1;
	return c1;
}
ostream& operator <<(ostream&out, const Complex&c)           //重载插入运算符
{
	out << "real:" << c.real << "  imag:" << c.imag << endl;
	return out;
}
void Complex::display() const
{
	cout << "real:" << real << "  imag:" << imag << endl;
}

