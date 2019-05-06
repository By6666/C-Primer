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
	int iyear(0),            //��ݱ�־λ��0-ƽ�ꣻ1-���ꣻ2-������ݣ�
		imonth(0),           //�·ݱ�־λ��0-���£�1-С�£�2-2�£�3-�����·ݣ�
		iday(0),             //���ڱ�־λ��0-��ȷ��1-����
		ihour(0),            //Сʱ��־λ��0-��ȷ��1-����
		iminute(0),          //���ӱ�־λ��0-��ȷ��1-����
		isecond(0);          //������־λ��0-��ȷ��1-����

	MyStruct daliy_time;

	while (1)
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
					if(daliy_time.month==4|| daliy_time.month==6|| daliy_time.month==9|| daliy_time.month==11)  imonth = 1; //С��
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

		cout << "���������Ϊ��" << daliy_time.year << "��" << setw(2) << setfill('0') << daliy_time.month << "��" << setw(2) << setfill('0') << daliy_time.day << "��" << setw(2) << setfill('0') << daliy_time.hour << ":" << setw(2) << setfill('0') << daliy_time.minute << ":" << setw(2) << setfill('0') << daliy_time.second;

		cout << "\n" << endl;
	}


	return 0;
}