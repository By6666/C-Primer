#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int(*prf)(int, int);

int main()
{
	char *b = "Bai yang";
	cout << b << endl;

	cout << "������9�����ݹ���һ��3x3���󣡣�" << endl;

	static int a[3][3];
	int* ptr = a[0];
	for (int i = 0; i < 9; i++)
	{
		cin >> *(ptr+i);
	}
	cout << "������ɣ���" << "\n" << endl;

	cout << "����ľ������£�" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = i+1; j < 3; j++)
		{
			int t;
			t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
	}

	cout << "����ת�ý�����£�" << endl;
	for (int i = 1; i < 10; i++)
	{
		cout << *(ptr + i - 1);
		if (i % 3 == 0)  cout << endl;
		else cout << "   ";

	}

	system("pause");
	return 0;
}