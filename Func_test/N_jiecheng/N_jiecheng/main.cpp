#include <iostream>
using namespace std;
unsigned fac(unsigned n);

int main()
{
	unsigned n(0);
	while (1)
	{
		cout << "请输入要求阶乘的数值n：\n";
		cin >> n;
		cout << n << "的阶乘为：" << fac(n) << endl;
	}

	system("pause");
	return 0;
}


unsigned fac(unsigned n)              //求n的阶乘，使用了函数的递归调用
{
	unsigned f = 0;

	if (n == 0)  f = 1;
	else f = n*fac(n - 1);

	return f;
}