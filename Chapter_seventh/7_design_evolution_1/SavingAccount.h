#ifndef _SAVINGACCOUNT_
#define _SAVINGACCOUNT_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "Accumulator.h"
#include "Date.h"

using namespace std;

class Account
{
public:
	Account(const Date& date,const string& id)
		:id(id),balance(0)
	{}

	string Getid() const { return id; }
	double Getbalance() const { return balance; }
	void Show() const;                               //显示账户信息
	static double GetTotal() { return total; }  //通过静态成员函数处理静态数据成员

protected:
	void record(const Date& date, double amount, const string& desc);//记录一笔账，date：日期，amount：金额，desc：说明
	void error(const string& msg) { cout << msg << endl; }

private:
	//Date lastdate;
	string id;              //账号ID
	double balance;         //余额
	static double total;    //记录所有账户的总金额值

};



class SavingAccount :public Account
{
public:
	SavingAccount(const Date& date, const string& id, double rate);

	double Getrate() const { return rate; }

	void deposit(const Date& date, double amount, const string& desc);     //存钱函数
	void withdraw(const Date& date, double amount, const string& desc);    //取钱函数
	void settle(const Date& date);                     //结算利息，每年1月1日调用该函数
	

private:
	Accumulator acc;
	double		rate;            //存款的年利率

};


class CreditAccount :public Account
{
public:
	CreditAccount(const Date& date, const string& id, double credit, double rate, double fee);

	double GetDebt() const { return -Getbalance(); }                        //债务
	double GetCredit() const { return credit; }                             //获得信用额度
	double GetRate() const { return rate; }                                 //贷款日利率
	double GetFee() const { return fee; }                                   //获得年费
	double GetAvaliableCredie() const { return credit + Getbalance(); }     //可用额度

	void deposit(const Date& date, double amount, const string& desc);     //存钱函数
	void withdraw(const Date& date, double amount, const string& desc);    //取钱函数
	void settle(const Date& date);                     //结算利息，每年1月1日调用该函数
	void Show() const;                               //显示账户信息


private:
	Accumulator acc;
	double
		credit,      //信用额度
		rate,        //日利率
		fee;         //年费

};



#endif // !_SAVINGACCOUNT_

