#include "SavingAccount.h"
double SavingAccount::total = 0;                                //类的静态成员一定要在外部进行初始化
SavingAccount::SavingAccount(const Date& date, const string& id, double rate)     //构造函数
	:lastDate(date),id(id),rate(rate),balance(0),accumulation(0)
{
	date.Show();
	cout <<  "\t#" << setw(8) << setfill('*') << id << " is created" << endl;
}

void SavingAccount::deposit(const Date& date, double amount, const string& desc)            //存钱函数
{
	record(date, amount, desc);
}

void SavingAccount::withdraw(const Date& date, double amount, const string& desc)           //取钱函数
{
	if (amount > Getbalance())
		error("Error:not enough money !!");
	else record(date, -amount, desc);
}

void SavingAccount::settle(const Date& date)                             //结算利息，每年1月1日调用该函数
{
	double interest = accumulate(date)*rate / 365;
	if (interest != 0)
		record(date, interest,"利息结算");
	accumulation = 0;
}

void SavingAccount::Show()const                                  //显示账户信息
{
	cout << "#" << setw(8) << setfill('*') << id << "\tBalance:" << balance << endl;
}

void SavingAccount::record(const Date& date, double amount, const string& desc)              //记录一笔账，date：日期，amount：金额，desc：说明
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;                    //floor函数，向下取整，用来得到不大于一个数的最大整数
	balance += amount;
	total += amount;
	date.Show();
	cout << "\t#" << setw(8) << setfill('*') << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

//e.g  floor（x+0.5）;   //对一个数做四舍五入
//向上取整函数  Ceil