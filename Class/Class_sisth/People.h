#ifndef _PEOPLE_
#define _PEOPLE_

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

struct DateStruct
{
	int year;
	int month;
	int day;
};

class Date
{
public:
	Date(int y=1900,int m=1,int d=1)
		:daliy_date{y,m,d}
	{ cout << "构造了一个Date！！" << endl; }

	~Date(){ cout << "析构了一个Date！！" << endl; }

	Date(const Date &d);

	void Setdate();
	void Showdate() const;

private:
	DateStruct daliy_date;
	int iyear,            //年份标志位，0-平年；1-闰年；2-错误年份；     
		imonth,           //月份标志位，0-大月；1-小月；2-2月；3-错误月份；
		iday;             //日期标志位，0-正确；1-错误；

};
Date::Date(const Date &d)
{
	daliy_date.year = d.daliy_date.year;
	daliy_date.month = d.daliy_date.month;
	daliy_date.day = d.daliy_date.day;
	cout << "复制构造了一个Date！！" << endl;
}
void Date::Setdate()
{
	//**********年份判断******************
	do
	{
		cout << "请输入年份\n";
		cin >> daliy_date.year;
		if (daliy_date.year < 0)
		{
			iyear = 2;                                          //错误年份
			cout << "输入年份错误！！\n";
		}
		else
		{
			if ((daliy_date.year % 4) != 0) iyear = 0;          //平年
			else
			{
				if ((daliy_date.year % 100) != 0) iyear = 1;    //闰年
				else
				{
					if ((daliy_date.year % 400) == 0)  iyear = 1;//闰年
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
		cin >> daliy_date.month;
		if (daliy_date.month > 12 || daliy_date.month < 1)
		{
			imonth = 3;                              //错误月份3
			cout << "输入月份错误！！\n";
		}
		else
		{
			if (daliy_date.month == 2)  imonth = 2; //月份2
			else
			{
				if (daliy_date.month == 4 || daliy_date.month == 6 || daliy_date.month == 9 || daliy_date.month == 11)  imonth = 1; //小月
				else imonth = 0; //大月
			}
		}
	} while (imonth>2);
	//		cout << "输入的月份类型为：" << imonth << "  月份为：" << daliy_time.month << endl;

	//**********日期判断******************
	do
	{
		cout << "请输入日期\n";
		cin >> daliy_date.day;
		switch (imonth)
		{
		case 0:if (daliy_date.day < 1 || daliy_date.day>31)
		{
			cout << "输入日期错误！！\n";
			iday = 1;
		}
			   else iday = 0;     break;


		case 1:if (daliy_date.day < 1 || daliy_date.day>30)
		{
			cout << "输入日期错误！！\n";
			iday = 1;
		}
			   else iday = 0;     break;


		case 2:if (iyear == 0)                                    //平年2月分
		{
			if (daliy_date.day < 1 || daliy_date.day>28)
			{
				cout << "输入日期错误！！\n";
				iday = 1;
			}
			else iday = 0;
		}
			   else                                               //闰年2月份
			   {
				   if (daliy_date.day < 1 || daliy_date.day>29)
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

}
void Date::Showdate() const
{
	cout << "生日：" << daliy_date.year << "年" << setw(2) << setfill('0') << daliy_date.month << "月" << setw(2) << setfill('0') << daliy_date.day << "日" << endl;
}


class People
{
public:
	People(string n, bool s, Date &b, string i)
		:number(n),sex(s),birthday(b),id(i)
	{	cout << "构造了一个People！！" << endl;  }

	~People() { cout << "析构了一个People！！" << endl; }

	People(const People &p)
		:number(p.number),sex(p.sex), birthday(p.birthday),id(p.id)
	{   cout << "复制构造了一个People！！" << endl;  }

	void Setnumber(string n) { number = n; }
	void Setsex(bool s) { sex = s; }
	void Setbirthday() { birthday.Setdate(); }
	void Setid(string i) { id = i; }

	void Shownumber() const { cout << "编号：" << number << endl; }
	void Showsex() const  { cout << "性别：" << (sex ? "女" : "男") << endl; }
	void Showbirthday() const  { birthday.Showdate(); }
	void Showid() const  { cout << "身份证号：" << id << endl; }

	void Showall();

private:
	string number;          //字符串类的编号
	bool sex;               //布尔类型的性别0：男，1：女
	Date birthday;          //Date类型的birthday
	string id;              //字符串类型的身份证号

};

void People::Showall()
{
	Shownumber();
	Showsex();
	Showbirthday();
	Showid();
}





#endif // !_PEOPLE_

