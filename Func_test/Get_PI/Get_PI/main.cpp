#include <iostream>
#include <cmath>
using namespace std;
double arctan(double x);       //求解arctan函数


int main()
{
	double a(0), b(0);
	a = 16.0*arctan(1 / 5.0);
	b = 4.0 *arctan(1 / 239.0);
	cout << "PI的值为：" << a - b << endl;

	system("pause");
	return 0;
}


double arctan(double x)     //求arctan（x）
{
	double sqr = -(x*x);
	double e = x;          //每项级数的分母
	double r(0);           //存放最终得求和结果
	int i(1);          
	while (abs(e / i) > 1e-10)  //精度判断
	{
		double f = e / i;     //存放每一项级数
		//r = (i % 4 == 1) ? r + f : r - f; //对每项级数进行累加
		r += f;
		e = e*sqr;         //分母进行累加
		i += 2;            //分子
	}
	return r;
}