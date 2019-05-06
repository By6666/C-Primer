#ifndef _SAVINGACCOUNT_
#define _SAVINGACCOUNT_
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "Date.h"
using namespace std;

class SavingAccount
{
public:
	SavingAccount(const Date& date,const string& id,double rate);

	string Getid() const { return id; }
	double Getbalance() const { return balance; }
	double Getrate() const { return rate; }
	void error(const string& msg) { cout << msg << endl; }

	void deposit(const Date& date, double amount, const string& desc);     //存钱函数
	void withdraw(const Date& date, double amount, const string& desc);    //取钱函数
	void settle(const Date& date);                     //结算利息，每年1月1日调用该函数
	void Show() const;                               //显示账户信息

	static double GetTotal() { return total; }  //通过静态成员函数处理静态数据成员
	

private:
	string id;              //账号ID
	Date  lastDate;        //上次余额变动日期
	double 
		balance,          //余额
		rate,            //存款的年利率
		accumulation;      //余额按日累加之和
	static double total;   //记录所有账户的总金额值

	void record(const Date& date, double amount, const string& desc);//记录一笔账，date：日期，amount：金额，desc：说明
	double accumulate(const Date& date) const { return accumulation + balance*(lastDate.distance(date)); } //获得到指定日期为止的存款按日累计值

};



#endif // !_SAVINGACCOUNT_

