#include <iostream>
using namespace std;

int main()
{
	using ABC = int;        //�������ͱ��� ��typedefҲ����
	ABC i(1), sum(0);
	double sums(0);
	enum MyEnum
	{
		MON, TUE, WED, THU, FRI, SAT, SUN
	};
    
	typedef MyEnum  DEF;   //ʹ��typedef����������
	DEF d;
	cout << "MON=" << MON + 1 << endl; //���enum����

	do
	{
		sum += i;
		i++;
	} while (i <= 10);

	cout << "sum=" << static_cast<float>(sum / 1.2) << "\n";

	system("pause");
	return 0;
}