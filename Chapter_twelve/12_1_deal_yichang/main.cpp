//异常处理实列


#include <iostream>
#include <cassert>
using namespace std;

#pragma warning (disable:4290)           //下面这样声明可能会报出警告，使用这样的语句来屏蔽警告
int divide(int x, int y) throw(int)      //在函数声名的时候说明可能会抛出的异常类型，使用throw（A,B,C,D）
{
	if (y == 0)  throw x;
	return x / y;
}

int main()
{
	try                                              //将可能会抛出异常的代码段放到try里
	{
		cout << "5/2= " << divide(5, 2) << endl;
		cout << "8/0= " << divide(8, 0) << endl;
	}
	catch (int e)                                   //try后的catch关键字用来捕捉抛出的异常
	{
		cout << e << " is divided by zero!!" << endl;
	}

	cout << "That's ok !!" << endl;



	system("pause");
	return 0;
}



