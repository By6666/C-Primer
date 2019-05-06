#include "SavingAccount.h"
#include "Date.h"
double Account::total = 0;                                //��ľ�̬��Աһ��Ҫ���ⲿ���г�ʼ��

//*********Account���Ա������ʵ��*******
void Account::Show() const                               //��ʾ�˻���Ϣ
{
	cout << "#" << setw(8) << setfill('*') << id << "\tBalance:" << balance << endl;
}
void Account::record(const Date& date, double amount, const string& desc) //��¼һ���ˣ�date�����ڣ�amount����desc��˵��
{
//	lastdate = date;
	amount = floor(amount * 100 + 0.5) / 100;                    //floor����������ȡ���������õ�������һ�������������
	balance += amount;
	total += amount;
	date.Show();
	cout << "\t#" << setw(8) << setfill('*') << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

//***************************************



//*******SavingAccount���Ա������ʵ��*******
SavingAccount::SavingAccount(const Date& date, const string& id, double rate)     //���캯��
	:Account(date, id), rate(rate), acc(date, 0)
{
	date.Show();
	cout << "\t#" << "SavingAccount" << "\t" << setw(8) << setfill('*') << id << " is created" << endl;
}
void SavingAccount::deposit(const Date& date, double amount, const string& desc)     //��Ǯ����
{
	record(date, amount, desc);
	acc.Change(date, Getbalance());
}
void SavingAccount::withdraw(const Date& date, double amount, const string& desc)    //ȡǮ����
{
	if (amount > Getbalance())
		error("Error:not enough money !!");
	else record(date, -amount, desc);

	acc.Change(date, Getbalance());
}
void SavingAccount::settle(const Date& date)                     //������Ϣ��ÿ��1��1�յ��øú���
{
	//double interest = accumulate(date)*rate / 365;
	//if (interest != 0)
	//	record(date, interest, "��Ϣ����");
	//accumulation = 0;
	if (date.GetMonth() == 1)
	{
		double interest = acc.Getsum(date)*rate / 365;
		if (interest != 0)
			record(date, interest, "��Ϣ����");
		acc.Reset(date, Getbalance());
	}
}
//*******************************************


//*******CreditAccount���Ա������ʵ��*******
CreditAccount::CreditAccount(const Date& date, const string& id, double credit, double rate, double fee)
	:Account(date, id), credit(credit), rate(rate), fee(fee),acc(date,0)
{
	date.Show();
	cout << "\t#" << "CreditAccount" << "\t" << setw(8) << setfill('*') << id << " is created" << endl;
}

void CreditAccount::deposit(const Date& date, double amount, const string& desc)     //��Ǯ����
{
	record(date, amount, desc);
	acc.Change(date, Getbalance());
}
void CreditAccount::withdraw(const Date& date, double amount, const string& desc)    //ȡǮ����
{
	if (amount > GetAvaliableCredie())
		error("Error:not enough money !!");
	else record(date, -amount, desc);

	acc.Change(date, Getbalance());
}
void CreditAccount::settle(const Date& date)                     //������Ϣ��ÿ��1�յ��øú���
{
	double interest = acc.Getsum(date)*rate / 365;
	if (interest != 0)
		record(date, interest, "��Ϣ����");
	if(date.GetMonth() == 1)
	acc.Reset(date, (Getbalance()-fee));
	else acc.Reset(date, Getbalance() );
}
void CreditAccount::Show() const                               //��ʾ�˻���Ϣ
{
	cout << "#" << setw(8) << setfill('*') << Getid() << "\tBalance:" << Getbalance() <<"\tAvaliableCredie:"<< GetAvaliableCredie()<<endl;
}

//*******************************************


//e.g  floor��x+0.5��;   //��һ��������������
//����ȡ������  Ceil