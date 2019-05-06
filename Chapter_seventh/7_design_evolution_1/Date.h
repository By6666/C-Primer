#ifndef _DATE_
#define _DATE_
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>   //使用其中的exit()函数
using namespace std;

class Date
{
public:
	Date(int syear, int smonth, int sday);    //构造函数

	int GetYear()  const { return year; }     //返回年
	int GetMonth() const { return month; }    //返回月
	int GetDay()   const { return day; }      //返回日
	double GetTotaldays() const { return totaldays; }//返回相对日期

	int GetMaxDay() const;                    //得到当前月的天数
	bool IsLeapYear() const;                  //判断是否为平年，平年：1，闰年：0
	void Show() const { cout << year << "年" << setw(2) << setfill(' ') << month << "月" << setw(2) << setfill(' ') << day << "日"; }   //打印日期

	int distance(const Date &date) const;            //计算当前日期与指定日期相差的天数

private:
	int year,           //年
		month,          //月
		day;            //日
	double 	totaldays;      //总的相对日期，即距离1年1月1日的天数

};


#endif // !_DATE_

