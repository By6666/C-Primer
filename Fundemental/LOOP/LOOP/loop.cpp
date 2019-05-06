#include <iostream>
using namespace std;

int main()
{
	using ABC = int;        //定义类型别名 用typedef也可以
	ABC i(1), sum(0);
	double sums(0);
	enum MyEnum
	{
		MON, TUE, WED, THU, FRI, SAT, SUN
	};
    
	typedef MyEnum  DEF;   //使用typedef定义类型名
	DEF d;
	cout << "MON=" << MON + 1 << endl; //输出enum类型

	do
	{
		sum += i;
		i++;
	} while (i <= 10);

	cout << "sum=" << static_cast<float>(sum / 1.2) << "\n";

	system("pause");
	return 0;
}