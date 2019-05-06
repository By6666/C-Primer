#include "SavingAccount.h"
#include "Date.h"
double Account::total = 0;                                //类的静态成员一定要在外部进行初始化

//*********Account类成员函数的实现*******
void Account::Show() const                               //显示账户信息
{
	cout << "#" << setw(8) << setfill('*') << id << "\tBalance:" << balance << endl;
}
void Account::record(const Date& date, double amount, const string& desc) //记录一笔账，date：日期，amount：金额，desc：说明
{
//	lastdate = date;
	amount = floor(amount * 100 + 0.5) / 100;                    //floor函数，向下取整，用来得到不大于一个数的最大整数
	balance += amount;
	total += amount;
	date.Show();
	cout << "\t#" << setw(8) << setfill('*') << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

//***************************************



//*******SavingAccount类成员函数的实现*******
SavingAccount::SavingAccount(const Date& date, const string& id, double rate)     //构造函数
	:Account(date, id), rate(rate), acc(date, 0)
{
	date.Show();
	cout << "\t#" << "SavingAccount" << "\t" << setw(8) << setfill('*') << id << " is created" << endl;
}
void SavingAccount::deposit(const Date& date, double amount, const string& desc)     //存钱函数
{
	record(date, amount, desc);
	acc.Change(date, Getbalance());
}
void SavingAccount::withdraw(const Date& date, double amount, const string& desc)    //取钱函数
{
	if (amount > Getbalance())
		error("Error:not enough money !!");
	else record(date, -amount, desc);

	acc.Change(date, Getbalance());
}
void SavingAccount::settle(const Date& date)                     //结算利息，每年1月1日调用该函数
{
	//double interest = accumulate(date)*rate / 365;
	//if (interest != 0)
	//	record(date, interest, "利息结算");
	//accumulation = 0;
	if (date.GetMonth() == 1)
	{
		double interest = acc.Getsum(date)*rate / 365;
		if (interest != 0)
			record(date, interest, "利息结算");
		acc.Reset(date, Getbalance());
	}
}
//*******************************************


//*******CreditAccount类成员函数的实现*******
CreditAccount::CreditAccount(const Date& date, const string& id, double credit, double rate, double fee)
	:Account(date, id), credit(credit), rate(rate), fee(fee),acc(date,0)
{
	date.Show();
	cout << "\t#" << "CreditAccount" << "\t" << setw(8) << setfill('*') << id << " is created" << endl;
}

void CreditAccount::deposit(const Date& date, double amount, const string& desc)     //存钱函数
{
	record(date, amount, desc);
	acc.Change(date, Getbalance());
}
void CreditAccount::withdraw(const Date& date, double amount, const string& desc)    //取钱函数
{
	if (amount > GetAvaliableCredie())
		error("Error:not enough money !!");
	else record(date, -amount, desc);

	acc.Change(date, Getbalance());
}
void CreditAccount::settle(const Date& date)                     //结算利息，每月1日调用该函数
{
	double interest = acc.Getsum(date)*rate / 365;
	if (interest != 0)
		record(date, interest, "利息结算");
	if(date.GetMonth() == 1)
	acc.Reset(date, (Getbalance()-fee));
	else acc.Reset(date, Getbalance() );
}
void CreditAccount::Show() const                               //显示账户信息
{
	cout << "#" << setw(8) << setfill('*') << Getid() << "\tBalance:" << Getbalance() <<"\tAvaliableCredie:"<< GetAvaliableCredie()<<endl;
}

//*******************************************


//e.g  floor（x+0.5）;   //对一个数做四舍五入
//向上取整函数  Ceil