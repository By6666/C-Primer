#ifndef _DATE_
#define _DATE_
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>   //ʹ�����е�exit()����
using namespace std;

class Date
{
public:
	Date(int syear, int smonth, int sday);    //���캯��

	int GetYear()  const { return year; }     //������
	int GetMonth() const { return month; }    //������
	int GetDay()   const { return day; }      //������
	double GetTotaldays() const { return totaldays; }//�����������

	int GetMaxDay() const;                    //�õ���ǰ�µ�����
	bool IsLeapYear() const;                  //�ж��Ƿ�Ϊƽ�꣬ƽ�꣺1�����꣺0
	void Show() const { cout << year << "��" << setw(2) << setfill(' ') << month << "��" << setw(2) << setfill(' ') << day << "��"; }   //��ӡ����

	int distance(const Date &date) const;            //���㵱ǰ������ָ��������������

private:
	int year,           //��
		month,          //��
		day;            //��
	double 	totaldays;      //�ܵ�������ڣ�������1��1��1�յ�����

};


#endif // !_DATE_

