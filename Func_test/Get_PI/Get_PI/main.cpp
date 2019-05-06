#include <iostream>
#include <cmath>
using namespace std;
double arctan(double x);       //���arctan����


int main()
{
	double a(0), b(0);
	a = 16.0*arctan(1 / 5.0);
	b = 4.0 *arctan(1 / 239.0);
	cout << "PI��ֵΪ��" << a - b << endl;

	system("pause");
	return 0;
}


double arctan(double x)     //��arctan��x��
{
	double sqr = -(x*x);
	double e = x;          //ÿ����ķ�ĸ
	double r(0);           //������յ���ͽ��
	int i(1);          
	while (abs(e / i) > 1e-10)  //�����ж�
	{
		double f = e / i;     //���ÿһ���
		//r = (i % 4 == 1) ? r + f : r - f; //��ÿ��������ۼ�
		r += f;
		e = e*sqr;         //��ĸ�����ۼ�
		i += 2;            //����
	}
	return r;
}