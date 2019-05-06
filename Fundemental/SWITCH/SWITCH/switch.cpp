#include <iostream>
using namespace std;

const float PI = 3.1416;

int main()
{
	short itype(0);
	double a(0), b(0), area(0);

	while (1)
	{
		cout << "请输入要计算图形的类型：圆形-1；长方形-2；正方形-3；\n";
		cin >> itype;

		switch (itype)
		{
		case 1:cout << "请输入圆形的半径：\n";
			   cin >> a;
			   area = a*a*PI;
			   cout << "半径为" << a << "的圆的面积为：" << area << endl;
			   break;

		case 2:cout << "请输入长方形的长和宽：\n";
			   cin >> a >> b;
			   area = a*b;
			   cout << "边长为" << a << "和" << b << "的长方形面积为：" << area << endl;
			   break;

		case 3:cout << "请输入正方形的边长：\n";
			   cin >> a;
			   area = a*a;
			   cout << "边长为" << a << "的正方形的面积为：" << area << endl;
			   break;

		default: cout << "输入类型错误，请重新输入！！\n";
			  break;
		}
		cout << "\n" << "\n";
	}

	return 0;
}