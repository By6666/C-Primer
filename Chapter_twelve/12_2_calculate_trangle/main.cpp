//标准库中为我们提供了许多中异常接口，他们都是exception类的子类，只需调用相关的异常即可


//***********关于cin的状态函数******************
//1、eof()
//如果读文件到达文件末尾，返回true。
//2、bad()
//如果在读写过程中出错，返回true。 例如：当我们要对一个不是打开为写状态进行写入时，或者我们要写入的设备没有剩余空间的时候。
//3、fail()
//出了与bad()同样的情况下会返回true以外，加上格式错误也会返回true，例如当想要读入一个整数，但输入了一个字母的时候，或者遇到eof，eof是一种fail，但fail不是一种eof。
//4、good()
//这是最通用的：如果调用以上任何一个函数返回true的话，此函数返回false。
//5、clear()
//标志位一旦被置位，这些标志将不会被改变，要想重置以上成员函数所检查的状态标志，你可以使用成员函数clear，没有参数。比如：通过函数移动文件指针，并不会使eofbit自动重置。
//6、ignore()


//清除cin的缓存区
//cin.ignore(numeric_limits<std::streamsize>::max(), ’\n’);//清除输入缓冲区的当前行 　　
//cin.ignore(numeric_limits<std::streamsize>::max()); //清除输入缓冲区里所有内容(慎用)
//cin.ignore()//清除一个字符


#include <iostream>
#include <cmath>
#include <stdexcept>   //标准程序异常库

using namespace std;

double area(double a, double b, double c);

int main()
{
	double a, b, c;

	cout << "please input the side lengths of a triangle:" << endl;
	cin >> a >> b >> c;
	cout << cin.fail() << endl;      
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cin >> a;
	cout << cin.fail() << endl;
	while (cin.get()!=EOF)          //判断是否接收到结尾Ctrl+Z
	{
		try
		{
			double s = area(a, b, c);
			cout << "Area: " << s << endl;
		}
		catch (const std::exception& e)
		{
			cout << "Error:" << e.what() << endl;
		}
		cout << "please reinput:" << endl;
		cin >> a >> b >> c;

	}


	system("pause");
	return 0;
}



double area(double a, double b, double c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		throw invalid_argument("the side length should be positive");   //抛出异常
	if (a + b <= c || b + c <= a || a + c <= b)
		throw invalid_argument("the side length should fit the triangle inequation");
	double s = (a + b + c) / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}