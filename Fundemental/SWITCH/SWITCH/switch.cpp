#include <iostream>
using namespace std;

const float PI = 3.1416;

int main()
{
	short itype(0);
	double a(0), b(0), area(0);

	while (1)
	{
		cout << "������Ҫ����ͼ�ε����ͣ�Բ��-1��������-2��������-3��\n";
		cin >> itype;

		switch (itype)
		{
		case 1:cout << "������Բ�εİ뾶��\n";
			   cin >> a;
			   area = a*a*PI;
			   cout << "�뾶Ϊ" << a << "��Բ�����Ϊ��" << area << endl;
			   break;

		case 2:cout << "�����볤���εĳ��Ϳ�\n";
			   cin >> a >> b;
			   area = a*b;
			   cout << "�߳�Ϊ" << a << "��" << b << "�ĳ��������Ϊ��" << area << endl;
			   break;

		case 3:cout << "�����������εı߳���\n";
			   cin >> a;
			   area = a*a;
			   cout << "�߳�Ϊ" << a << "�������ε����Ϊ��" << area << endl;
			   break;

		default: cout << "�������ʹ������������룡��\n";
			  break;
		}
		cout << "\n" << "\n";
	}

	return 0;
}