#include <iostream>
using namespace std;

double power(double v, int n);

int main()
{
	double value_D(0);
	char ch('\0');

	while (1)
	{
		cout << "������һ��8λ�Ķ���������\n";
		for (short i = 7; i >= 0; i--)
		{
			cin >> ch;
			if (ch == '1')  value_D += power(2, i);
		}

		cout << "ת���Ľ��Ϊ��" << value_D << "\n" <<endl;
		value_D = 0;
	}

	return 0;
}


double power(double v, int n)    //��V��n�η�
{
	double value(1.0);
	while (n--)
	{
		value *= v;
	}
	return value;
}