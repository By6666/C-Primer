#include <iostream>
#include <cmath>
using namespace std;
double G_sin(double x);
const double TINY_value = 1e-10;       //求解精度1*10（-10）次方

int main()
{
	double  k(0), r(0), s(0);
	while (1)
	{
		cout << "请输入r和s：\n";
		cin >> r >> s;

		k = (r*r <= s*s) ? (sqrt(G_sin(r)*G_sin(r) + G_sin(s)*G_sin(s))) : (G_sin(r*s) / 2);    
		cout << "最终结果K= " << k << endl;
	}

	return 0;
}

double G_sin(double x)               //求解sin（x）函数
{
	double g(0);      //存放最终结果
	double t(x);      //存放每一个级数
	int n(1);         //计数变量，是第n项
	do
	{
		g += t;       //将每项累加
		n++;
		t = -t*x*x / ((2 * n - 1)*(2 * n - 2));   //第n项级数的表达式

	} while (fabs(t)>= TINY_value);               //判断是否达到了精度

	return g;
}