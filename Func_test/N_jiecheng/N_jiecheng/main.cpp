#include <iostream>
using namespace std;
unsigned fac(unsigned n);

int main()
{
	unsigned n(0);
	while (1)
	{
		cout << "������Ҫ��׳˵���ֵn��\n";
		cin >> n;
		cout << n << "�Ľ׳�Ϊ��" << fac(n) << endl;
	}

	system("pause");
	return 0;
}


unsigned fac(unsigned n)              //��n�Ľ׳ˣ�ʹ���˺����ĵݹ����
{
	unsigned f = 0;

	if (n == 0)  f = 1;
	else f = n*fac(n - 1);

	return f;
}