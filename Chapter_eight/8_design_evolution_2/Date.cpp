#include "Date.h"

namespace {//namespaceʹ������Ķ���ֻ���ڵ�ǰ�ļ�����Ч
	const int DAYS_BEFORE_MONTH[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
}

Date::Date(int syear, int smonth, int sday)    //���캯��
	:year(syear),month(smonth),day(sday)
{
	if (day <= 0 || day > GetMaxDay())
	{
		cout << "Invalid date";
		Show();
		cout << endl;
		exit(1);     //����������ֹ�����ִ��        
	}
	totaldays = 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400
		+ DAYS_BEFORE_MONTH[month-1]
		+ day - 1;
	if (!IsLeapYear() && month > 2) totaldays += 1;
}

int Date::GetMaxDay() const                    //�õ���ǰ�µ�����
{
	if (!IsLeapYear() && month == 2)
		return(DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1] + 1);
	else
		return(DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1]);
}

bool Date::IsLeapYear() const                  //�ж��Ƿ�Ϊƽ�꣬ƽ�꣺1�����꣺0
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

//int Date::distance(const Date &date) const            //���㵱ǰ������ָ��������������
//{
//	return abs(totaldays - date.totaldays);
//}

int Date::operator - (const Date&c) const
{
	return (abs(totaldays - c.totaldays));
}
