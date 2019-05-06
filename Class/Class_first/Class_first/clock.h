#ifndef _CLOCK_
#define _CLOCK_

//********���Ա����********
//1����������������ԭ��
//2���������������������ʵ�֣����ں�����ǰʹ�����������޶�
//3��Ҳ����ֱ�������и��������壬�γ���������������������ӷּ򵥣�
//4�������������غ����ʹ�Ĭ�ϲ����ĺ���
//**************************


//********���캯��**********
//���ʣ�1�����е����⺯��
//���ã�1������������ʼ���㷨������˵���ǳ�ʼ�����еı�����
//*************************

//******���캯����ʽ********
//1����������������ͬ
//2�����ܶ��巵��ֵ����
//3���������βΣ�Ҳ����û���β�
//4����������������
//5����������
//6�����Դ�Ĭ�ϵĲ���ֵ
//����ʱ�����ڴ�������ʱ�����ã����ù��캯���Ǳ���ģ���������һ�����й��캯��
//**************************

//****�������ɵĹ��캯��****
//�������û��д���캯�������������������Զ�����һ��Ĭ�ϵĹ��캯��
//�ص����£�
//1�������б�Ϊ�գ���Ϊ��Ա���ó�ʼֵ
//2��������ڶ����˳�Ա�ĳ�ʼֵ����ʹ�����ڶ���ĳ�ʼֵ
//3�����û�ж������ڵĳ�ʼֵ������Ĭ�ϵķ�ʽ���г�ʼ��
//4���������͵�����Ĭ�ϳ�ʼ����ֵ�ǲ�ȷ����
//***************************

//*****ֱ�ӳ�ʼ���͸��Ƴ�ʼ������*****
//��������������˵�����Ƴ�ʼ����ֱ�ӳ�ʼ������û�в��
//���������������������������Ͷ���ʱ����ʼ���ĸ�����ʽ��ֱ����ʽ������ͬ��
//ֱ�ӳ�ʼ��ֱ�ӵ�����ʵ��ƥ��Ĺ��캯�������Ƴ�ʼ�����ǵ��ø��ƹ��캯����
//���Ƴ�ʼ������ʹ��ָ�����캯������һ����ʱ����Ȼ��ʹ�ø��ƹ��캯�����Ǹ���ʱ�����Ƶ����ڴ����Ķ���

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
	//Clock()=default;   //ʹ����仰�ǣ��ñ������Զ����ɹ��캯������ʹ��仰��д��������Ҳ��Ĭ������һ��clock�������Ĺ��캯��   
	                       //��ʹ�������ʹ���һ������ʱ�����캯���Զ�������
	Clock(int year = 0, int month = 0, int day = 0, int hour = 0, int minute = 0, int second = 0); //��������Ĭ��ֵ���βΣ���������к�����ʵ��
	void setTime();
	void showTime();

private:
	MyStruct daliy_time/*{0,0,0,0,0,0}*/;   //Ҳ�����������private��Ա���г�ʼ������ȻҲ���Բ���
	int iyear = 0,            //��ݱ�־λ��0-ƽ�ꣻ1-���ꣻ2-������ݣ�     
		imonth = 0,           //�·ݱ�־λ��0-���£�1-С�£�2-2�£�3-�����·ݣ�
		iday = 0,             //���ڱ�־λ��0-��ȷ��1-����
		ihour = 0,            //Сʱ��־λ��0-��ȷ��1-����
		iminute = 0,          //���ӱ�־λ��0-��ȷ��1-����
		isecond = 0;          //������־λ��0-��ȷ��1-����
};


Clock::Clock(int year, int month, int day, int hour, int minute, int second)        //���캯����ʵ��
	:daliy_time{ year,month ,day,hour,minute ,second }/*,iyear(0),imonth(0),iday(0),ihour(0),iminute(0),isecond(0)*/  //Ҳ�����������private��Ա���г�ʼ�����Ƽ�ʹ�����ַ���
{
	//iyear = 0; imonth = 0; iday = 0; ihour = 0; iminute = 0; isecond = 0;          //�����ڹ��캯�����private��Ա�������г�ʼ������C++11֧���ڶ���ʱֱ�ӽ��г�ʼ��
}

void Clock::setTime()
{
	//**********����ж�******************
	do
	{
		cout << "���������\n";
		cin >> daliy_time.year;
		if (daliy_time.year < 0)
		{
			iyear = 2;                                          //�������
			cout << "������ݴ��󣡣�\n";
		}
		else
		{
			if ((daliy_time.year % 4) != 0) iyear = 0;          //ƽ��
			else
			{
				if ((daliy_time.year % 100) != 0) iyear = 1;    //����
				else
				{
					if ((daliy_time.year % 400) == 0)  iyear = 1;//����
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
		cin >> daliy_time.month;
		if (daliy_time.month > 12 || daliy_time.month < 1)
		{
			imonth = 3;                              //�����·�3
			cout << "�����·ݴ��󣡣�\n";
		}
		else
		{
			if (daliy_time.month == 2)  imonth = 2; //�·�2
			else
			{
				if (daliy_time.month == 4 || daliy_time.month == 6 || daliy_time.month == 9 || daliy_time.month == 11)  imonth = 1; //С��
				else imonth = 0; //����
			}
		}
	} while (imonth>2);
	//		cout << "������·�����Ϊ��" << imonth << "  �·�Ϊ��" << daliy_time.month << endl;

	//**********�����ж�******************
	do
	{
		cout << "����������\n";
		cin >> daliy_time.day;
		switch (imonth)
		{
		case 0:if (daliy_time.day < 1 || daliy_time.day>31)
		{
			cout << "�������ڴ��󣡣�\n";
			iday = 1;
		}
			   else iday = 0;     break;


		case 1:if (daliy_time.day < 1 || daliy_time.day>30)
		{
			cout << "�������ڴ��󣡣�\n";
			iday = 1;
		}
			   else iday = 0;     break;


		case 2:if (iyear == 0)                                    //ƽ��2�·�
		{
			if (daliy_time.day < 1 || daliy_time.day>28)
			{
				cout << "�������ڴ��󣡣�\n";
				iday = 1;
			}
			else iday = 0;
		}
			   else                                               //����2�·�
			   {
				   if (daliy_time.day < 1 || daliy_time.day>29)
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

	//**********Сʱ�ж�******************
	do
	{
		cout << "������Сʱ��\n";
		cin >> daliy_time.hour;
		if (daliy_time.hour < 0 || daliy_time.hour>23)
		{
			ihour = 1;
			cout << "Сʱ������󣡣�\n";
		}
		else ihour = 0;
	} while (ihour>0);

	//**********�����ж�******************
	do
	{
		cout << "�����������\n";
		cin >> daliy_time.minute;
		if (daliy_time.minute < 0 || daliy_time.minute>59)
		{
			iminute = 1;
			cout << "����������󣡣�\n";
		}
		else iminute = 0;
	} while (iminute>0);

	//**********���ж�******************
	do
	{
		cout << "����������\n";
		cin >> daliy_time.second;
		if (daliy_time.second < 0 || daliy_time.second>59)
		{
			isecond = 1;
			cout << "��������󣡣�\n";
		}
		else isecond = 0;
	} while (isecond>0);

	
}



void Clock::showTime(void)
{
	cout << "���������Ϊ��" << daliy_time.year << "��" << setw(2) << setfill('0') << daliy_time.month << "��" << setw(2) << setfill('0') << daliy_time.day << "��" << setw(2) << setfill('0') << daliy_time.hour << ":" << setw(2) << setfill('0') << daliy_time.minute << ":" << setw(2) << setfill('0') << daliy_time.second;
	cout << "\n" << endl;
}



#endif // !_CLOCK_

