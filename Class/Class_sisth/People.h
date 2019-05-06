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
	{ cout << "������һ��Date����" << endl; }

	~Date(){ cout << "������һ��Date����" << endl; }

	Date(const Date &d);

	void Setdate();
	void Showdate() const;

private:
	DateStruct daliy_date;
	int iyear,            //��ݱ�־λ��0-ƽ�ꣻ1-���ꣻ2-������ݣ�     
		imonth,           //�·ݱ�־λ��0-���£�1-С�£�2-2�£�3-�����·ݣ�
		iday;             //���ڱ�־λ��0-��ȷ��1-����

};
Date::Date(const Date &d)
{
	daliy_date.year = d.daliy_date.year;
	daliy_date.month = d.daliy_date.month;
	daliy_date.day = d.daliy_date.day;
	cout << "���ƹ�����һ��Date����" << endl;
}
void Date::Setdate()
{
	//**********����ж�******************
	do
	{
		cout << "���������\n";
		cin >> daliy_date.year;
		if (daliy_date.year < 0)
		{
			iyear = 2;                                          //�������
			cout << "������ݴ��󣡣�\n";
		}
		else
		{
			if ((daliy_date.year % 4) != 0) iyear = 0;          //ƽ��
			else
			{
				if ((daliy_date.year % 100) != 0) iyear = 1;    //����
				else
				{
					if ((daliy_date.year % 400) == 0)  iyear = 1;//����
					else iyear = 0;                              //ƽ��
				}
			}
		}
	} while (iyear>1);

	//		cout << "�����������Ϊ" << iyear << "  ���Ϊ" << daliy_time.year << endl;


	//**********�·��ж�******************
	do
	{
		cout << "�������·�\n";
		cin >> daliy_date.month;
		if (daliy_date.month > 12 || daliy_date.month < 1)
		{
			imonth = 3;                              //�����·�3
			cout << "�����·ݴ��󣡣�\n";
		}
		else
		{
			if (daliy_date.month == 2)  imonth = 2; //�·�2
			else
			{
				if (daliy_date.month == 4 || daliy_date.month == 6 || daliy_date.month == 9 || daliy_date.month == 11)  imonth = 1; //С��
				else imonth = 0; //����
			}
		}
	} while (imonth>2);
	//		cout << "������·�����Ϊ��" << imonth << "  �·�Ϊ��" << daliy_time.month << endl;

	//**********�����ж�******************
	do
	{
		cout << "����������\n";
		cin >> daliy_date.day;
		switch (imonth)
		{
		case 0:if (daliy_date.day < 1 || daliy_date.day>31)
		{
			cout << "�������ڴ��󣡣�\n";
			iday = 1;
		}
			   else iday = 0;     break;


		case 1:if (daliy_date.day < 1 || daliy_date.day>30)
		{
			cout << "�������ڴ��󣡣�\n";
			iday = 1;
		}
			   else iday = 0;     break;


		case 2:if (iyear == 0)                                    //ƽ��2�·�
		{
			if (daliy_date.day < 1 || daliy_date.day>28)
			{
				cout << "�������ڴ��󣡣�\n";
				iday = 1;
			}
			else iday = 0;
		}
			   else                                               //����2�·�
			   {
				   if (daliy_date.day < 1 || daliy_date.day>29)
				   {
					   cout << "�������ڴ��󣡣�\n";
					   iday = 1;
				   }
				   else iday = 0;
			   }
			   break;
		}
	} while (iday>0);
	//		cout << "���������Ϊ��" << daliy_time.day << endl;

}
void Date::Showdate() const
{
	cout << "���գ�" << daliy_date.year << "��" << setw(2) << setfill('0') << daliy_date.month << "��" << setw(2) << setfill('0') << daliy_date.day << "��" << endl;
}


class People
{
public:
	People(string n, bool s, Date &b, string i)
		:number(n),sex(s),birthday(b),id(i)
	{	cout << "������һ��People����" << endl;  }

	~People() { cout << "������һ��People����" << endl; }

	People(const People &p)
		:number(p.number),sex(p.sex), birthday(p.birthday),id(p.id)
	{   cout << "���ƹ�����һ��People����" << endl;  }

	void Setnumber(string n) { number = n; }
	void Setsex(bool s) { sex = s; }
	void Setbirthday() { birthday.Setdate(); }
	void Setid(string i) { id = i; }

	void Shownumber() const { cout << "��ţ�" << number << endl; }
	void Showsex() const  { cout << "�Ա�" << (sex ? "Ů" : "��") << endl; }
	void Showbirthday() const  { birthday.Showdate(); }
	void Showid() const  { cout << "���֤�ţ�" << id << endl; }

	void Showall();

private:
	string number;          //�ַ�����ı��
	bool sex;               //�������͵��Ա�0���У�1��Ů
	Date birthday;          //Date���͵�birthday
	string id;              //�ַ������͵����֤��

};

void People::Showall()
{
	Shownumber();
	Showsex();
	Showbirthday();
	Showid();
}





#endif // !_PEOPLE_

