#include <iostream>
using namespace std;

double power(double v, int n);

int main()
{
	double value_D(0);
	char ch('\0');

	while (1)
	{
		cout << "请输入一个8位的二进制数：\n";
		for (short i = 7; i >= 0; i--)
		{
			cin >> ch;
			if (ch == '1')  value_D += power(2, i);
		}

		cout << "转换的结果为：" << value_D << "\n" <<endl;
		value_D = 0;
	}

	return 0;
}


double power(double v, int n)    //求V的n次方
{
	double value(1.0);
	while (n--)
	{
		value *= v;
	}
	return value;
}