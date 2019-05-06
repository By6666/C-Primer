#include "Complex.h"

Complex operator +(const Complex&c1, const Complex&c2)      //�������Ԫ����
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator -(const Complex&c1, const Complex&c2)
{
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
Complex& operator ++(Complex&c1)                       //ǰ��++
{
	c1.real++;
	c1.imag++;
	return c1;
}
Complex operator ++(Complex&c1, int)                   //����++
{
	++c1;
	return c1;
}
ostream& operator <<(ostream&out, const Complex&c)           //���ز��������
{
	out << "real:" << c.real << "  imag:" << c.imag << endl;
	return out;
}
void Complex::display() const
{
	cout << "real:" << real << "  imag:" << imag << endl;
}

