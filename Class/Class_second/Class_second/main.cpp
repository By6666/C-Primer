#include <iostream>
#include <iomanip>

using namespace std;


class MyClass
{
public:
	MyClass(int HOUR, int MINUTE, int SECOND)        //作为委托构造函数的本体，只需修改这个函数便可一次性修改其他被委托的构造函数
		:hour(HOUR), minute(MINUTE), second(SECOND)
	{}
	////MyClass()                      //作用和下面构造函数相同
	////	:hour(0),minute(0),second(0)
	////{}
	//MyClass()                        //本函数和上面作用相同
	//	:MyClass(0,0,0)              //委托构造函数，使用第一个构造函数初始化第二个构造函数
	//{}
	void setTime(int HOUR = 0, int MINUTE = 0, int SECOND = 0);          //带默认值的形参
	void showTime();


private:
	int hour, minute, second;

};

void MyClass::setTime(int HOUR, int MINUTE, int SECOND)
{
	hour = HOUR; minute = MINUTE; second = SECOND;

}
void MyClass::showTime()
{
	cout << hour << ":" << setw(2)<<setfill('0')<<minute << ":" << setw(2) << setfill('0') << second << endl;
}

MyClass func()
{
	return MyClass(14,10,55);
}

int main()
{
	//MyClass Tim;                     //这就调用了隐含的构造函数
	//Tim.setTime(21, 0, 0);
	//Tim.showTime();
	func().showTime();

	system("pause");
	return 0;	

}