#include "Array.h"

int main()
{
	Array<int> a;
	int n, count = 0;
	cout << "please input n vaule:" << endl;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		bool isPrime = true;
		for (int j = 0; j < count; j++)
		{
			if (i%a[j] == 0)                         //�ж��Ƿ�Ϊ������ֻ���жϸ����ܷ�����С�ڱ������������
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			if (count == a.GetSize())
				a.Resize(count * 2);
			a[count++] = i;
		}
	}

	for (int i = 0; i < count; i++)
		cout << setw(8) << a[i];
	cout << endl;

	system("pause");
	return 0;
}