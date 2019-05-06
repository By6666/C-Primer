#include "SavingAccount.h"
double SavingAccount::total = 0;                                //��ľ�̬��Աһ��Ҫ���ⲿ���г�ʼ��
SavingAccount::SavingAccount(const Date& date, const string& id, double rate)     //���캯��
	:lastDate(date),id(id),rate(rate),balance(0),accumulation(0)
{
	date.Show();
	cout <<  "\t#" << setw(8) << setfill('*') << id << " is created" << endl;
}

void SavingAccount::deposit(const Date& date, double amount, const string& desc)            //��Ǯ����
{
	record(date, amount, desc);
}

void SavingAccount::withdraw(const Date& date, double amount, const string& desc)           //ȡǮ����
{
	if (amount > Getbalance())
		error("Error:not enough money !!");
	else record(date, -amount, desc);
}

void SavingAccount::settle(const Date& date)                             //������Ϣ��ÿ��1��1�յ��øú���
{
	double interest = accumulate(date)*rate / 365;
	if (interest != 0)
		record(date, interest,"��Ϣ����");
	accumulation = 0;
}

void SavingAccount::Show()const                                  //��ʾ�˻���Ϣ
{
	cout << "#" << setw(8) << setfill('*') << id << "\tBalance:" << balance << endl;
}

void SavingAccount::record(const Date& date, double amount, const string& desc)              //��¼һ���ˣ�date�����ڣ�amount����desc��˵��
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;                    //floor����������ȡ���������õ�������һ�������������
	balance += amount;
	total += amount;
	date.Show();
	cout << "\t#" << setw(8) << setfill('*') << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

//e.g  floor��x+0.5��;   //��һ��������������
//����ȡ������  Ceil