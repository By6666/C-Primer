#include "Date.h"

namespace {//namespace使得下面的定义只能在当前文件中有效
	const int DAYS_BEFORE_MONTH[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
}

Date::Date(int syear, int smonth, int sday)    //构造函数
	:year(syear),month(smonth),day(sday)
{
	if (day <= 0 || day > GetMaxDay())
	{
		cout << "Invalid date";
		Show();
		cout << endl;
		exit(1);     //用来立即终止程序的执行        
	}
	totaldays = 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400
		+ DAYS_BEFORE_MONTH[month-1]
		+ day - 1;
	if (!IsLeapYear() && month > 2) totaldays += 1;
}

int Date::GetMaxDay() const                    //得到当前月的天数
{
	if (!IsLeapYear() && month == 2)
		return(DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1] + 1);
	else
		return(DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1]);
}

bool Date::IsLeapYear() const                  //判断是否为平年，平年：1，闰年：0
{
	if (year % 4 != 0)  return 1;
	else 
	{
		if (year % 100 != 0)   return 0;
		else
		{
			if(year % 400 == 0) return 0;
			else return 1;
		}
	}

}

//int Date::distance(const Date &date) const            //计算当前日期与指定日期相差的天数
//{
//	return abs(totaldays - date.totaldays);
//}

int Date::operator - (const Date&c) const
{
	return (abs(totaldays - c.totaldays));
}
