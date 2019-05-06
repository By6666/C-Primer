#include <iostream>
#include <cmath>
using namespace std;
double G_sin(double x);
const double TINY_value = 1e-10;       //��⾫��1*10��-10���η�

int main()
{
	double  k(0), r(0), s(0);
	while (1)
	{
		cout << "������r��s��\n";
		cin >> r >> s;

		k = (r*r <= s*s) ? (sqrt(G_sin(r)*G_sin(r) + G_sin(s)*G_sin(s))) : (G_sin(r*s) / 2);    
		cout << "���ս��K= " << k << endl;
	}

	return 0;
}

double G_sin(double x)               //���sin��x������
{
	double g(0);      //������ս��
	double t(x);      //���ÿһ������
	int n(1);         //�����������ǵ�n��
	do
	{
		g += t;       //��ÿ���ۼ�
		n++;
		t = -t*x*x / ((2 * n - 1)*(2 * n - 2));   //��n����ı��ʽ

	} while (fabs(t)>= TINY_value);               //�ж��Ƿ�ﵽ�˾���

	return g;
}