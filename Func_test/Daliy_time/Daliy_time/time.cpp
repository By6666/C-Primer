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

int main()
{
	int iyear(0),            //年份标志位，0-平年；1-闰年；2-错误年份；
		imonth(0),           //月份标志位，0-大月；1-小月；2-2月；3-错误月份；
		iday(0),             //日期标志位，0-正确；1-错误；
		ihour(0),            //小时标志位，0-正确；1-错误；
		iminute(0),          //分钟标志位，0-正确；1-错误；
		isecond(0);          //秒数标志位，0-正确；1-错误；

	MyStruct daliy_time;

	while (1)
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
					if(daliy_time.month==4|| daliy_time.month==6|| daliy_time.month==9|| daliy_time.month==11)  imonth = 1; //小月
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

		cout << "输入的日期为：" << daliy_time.year << "年" << setw(2) << setfill('0') << daliy_time.month << "月" << setw(2) << setfill('0') << daliy_time.day << "日" << setw(2) << setfill('0') << daliy_time.hour << ":" << setw(2) << setfill('0') << daliy_time.minute << ":" << setw(2) << setfill('0') << daliy_time.second;

		cout << "\n" << endl;
	}


	return 0;
}