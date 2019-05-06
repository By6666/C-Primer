#ifndef _CLOCK_
#define _CLOCK_

//********类成员函数********
//1、在类中声明函数原型
//2、可以在类外给出函数体实现，并在函数名前使用类名加以限定
//3、也可以直接在类中给出函数体，形成内联函数（但函数必须从分简单）
//4、允许声明重载函数和带默认参数的函数
//**************************


//********构造函数**********
//性质：1、类中的特殊函数
//作用：1、用于描述初始化算法（简单来说就是初始化类中的变量）
//*************************

//******构造函数形式********
//1、函数名与类名相同
//2、不能定义返回值类型
//3、可以有形参，也可以没有形参
//4、可以是内联函数
//5、可以重载
//6、可以带默认的参数值
//调用时机：在创建对象时被调用，调用构造函数是必须的，所以类中一定会有构造函数
//**************************

//****隐含生成的构造函数****
//如果我们没有写构造函数，则编译器会帮我们自动生成一个默认的构造函数
//特点如下：
//1、参数列表为空，不为成员设置初始值
//2、如果类内定义了成员的初始值，则使用类内定义的初始值
//3、如果没有定义类内的初始值，则以默认的方式进行初始化
//4、基本类型的数据默认初始化的值是不确定的
//***************************

//*****直接初始化和复制初始化区别*****
//对于内置类型来说，复制初始化和直接初始化几乎没有差别，
//对于类类型来讲，当创建类类型对象时，初始化的复制形式和直接形式有所不同：
//直接初始化直接调用与实参匹配的构造函数，复制初始化总是调用复制构造函数。
//复制初始化首先使用指定构造函数创建一个临时对象，然后使用复制构造函数将那个临时对象复制到正在创建的对象

#include <iostream>
#include <iomanip>
using namespace std;

struct MyStruct 
{
	int year;
	int month;
	int day;

	int hour;
	int minute;
	int second;
};

class Clock
{
public:
	//Clock()=default;   //使用这句话是：让编译器自动生成构造函数，即使这句话不写，编译器也会默认生成一个clock（）样的构造函数   
	                       //当使用类类型创建一个对象时，构造函数自动被调用
	Clock(int year = 0, int month = 0, int day = 0, int hour = 0, int minute = 0, int second = 0); //声明带有默认值的形参，在类外进行函数的实现
	void setTime();
	void showTime();

private:
	MyStruct daliy_time/*{0,0,0,0,0,0}*/;   //也可以在这里对private成员进行初始化，当然也可以不用
	int iyear = 0,            //年份标志位，0-平年；1-闰年；2-错误年份；     
		imonth = 0,           //月份标志位，0-大月；1-小月；2-2月；3-错误月份；
		iday = 0,             //日期标志位，0-正确；1-错误；
		ihour = 0,            //小时标志位，0-正确；1-错误；
		iminute = 0,          //分钟标志位，0-正确；1-错误；
		isecond = 0;          //秒数标志位，0-正确；1-错误；
};


Clock::Clock(int year, int month, int day, int hour, int minute, int second)        //构造函数的实现
	:daliy_time{ year,month ,day,hour,minute ,second }/*,iyear(0),imonth(0),iday(0),ihour(0),iminute(0),isecond(0)*/  //也可以在这里对private成员进行初始化，推荐使用这种方法
{
	//iyear = 0; imonth = 0; iday = 0; ihour = 0; iminute = 0; isecond = 0;          //可以在构造函数里对private成员变量进行初始化，但C++11支持在定义时直接进行初始化
}

void Clock::setTime()
{
	//**********年份判断******************
	do
	{
		cout << "请输入年份\n";
		cin >> daliy_time.year;
		if (daliy_time.year < 0)
		{
			iyear = 2;                                          //错误年份
			cout << "输入年份错误！！\n";
		}
		else
		{
			if ((daliy_time.year % 4) != 0) iyear = 0;          //平年
			else
			{
				if ((daliy_time.year % 100) != 0) iyear = 1;    //闰年
				else
				{
					if ((daliy_time.year % 400) == 0)  iyear = 1;//闰年
					else iyear = 0;                              //平年
				}
			}
		}
	} while (iyear>1);

	//		cout << "输入年份类型为" << iyear << "  年份为" << daliy_time.year << endl;


	//**********月份判断******************
	do
	{
		cout << "请输入月份\n";
		cin >> daliy_time.month;
		if (daliy_time.month > 12 || daliy_time.month < 1)
		{
			imonth = 3;                              //错误月份3
			cout << "输入月份错误！！\n";
		}
		else
		{
			if (daliy_time.month == 2)  imonth = 2; //月份2
			else
			{
				if (daliy_time.month == 4 || daliy_time.month == 6 || daliy_time.month == 9 || daliy_time.month == 11)  imonth = 1; //小月
				else imonth = 0; //大月
			}
		}
	} while (imonth>2);
	//		cout << "输入的月份类型为：" << imonth << "  月份为：" << daliy_time.month << endl;

	//**********日期判断******************
	do
	{
		cout << "请输入日期\n";
		cin >> daliy_time.day;
		switch (imonth)
		{
		case 0:if (daliy_time.day < 1 || daliy_time.day>31)
		{
			cout << "输入日期错误！！\n";
			iday = 1;
		}
			   else iday = 0;     break;


		case 1:if (daliy_time.day < 1 || daliy_time.day>30)
		{
			cout << "输入日期错误！！\n";
			iday = 1;
		}
			   else iday = 0;     break;


		case 2:if (iyear == 0)                                    //平年2月分
		{
			if (daliy_time.day < 1 || daliy_time.day>28)
			{
				cout << "输入日期错误！！\n";
				iday = 1;
			}
			else iday = 0;
		}
			   else                                               //闰年2月份
			   {
				   if (daliy_time.day < 1 || daliy_time.day>29)
				   {
					   cout << "输入日期错误！！\n";
					   iday = 1;
				   }
				   else iday = 0;
			   }
			   break;
		}
	} while (iday>0);
	//		cout << "输入的日期为：" << daliy_time.day << endl;

	//**********小时判断******************
	do
	{
		cout << "请输入小时数\n";
		cin >> daliy_time.hour;
		if (daliy_time.hour < 0 || daliy_time.hour>23)
		{
			ihour = 1;
			cout << "小时输入错误！！\n";
		}
		else ihour = 0;
	} while (ihour>0);

	//**********分钟判断******************
	do
	{
		cout << "请输入分钟数\n";
		cin >> daliy_time.minute;
		if (daliy_time.minute < 0 || daliy_time.minute>59)
		{
			iminute = 1;
			cout << "分钟输入错误！！\n";
		}
		else iminute = 0;
	} while (iminute>0);

	//**********秒判断******************
	do
	{
		cout << "请输入秒数\n";
		cin >> daliy_time.second;
		if (daliy_time.second < 0 || daliy_time.second>59)
		{
			isecond = 1;
			cout << "秒输入错误！！\n";
		}
		else isecond = 0;
	} while (isecond>0);

	
}



void Clock::showTime(void)
{
	cout << "输入的日期为：" << daliy_time.year << "年" << setw(2) << setfill('0') << daliy_time.month << "月" << setw(2) << setfill('0') << daliy_time.day << "日" << setw(2) << setfill('0') << daliy_time.hour << ":" << setw(2) << setfill('0') << daliy_time.minute << ":" << setw(2) << setfill('0') << daliy_time.second;
	cout << "\n" << endl;
}



#endif // !_CLOCK_

