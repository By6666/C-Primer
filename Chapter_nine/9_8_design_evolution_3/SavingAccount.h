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
	virtual void Show() const;                               //��ʾ�˻���Ϣ  (�ڶ����������ú�������Ϊ�麯��)
	static double GetTotal() { return total; }  //ͨ����̬��Ա��������̬���ݳ�Ա

//�ڶ��������������к�������Ϊ���麯��
	virtual void deposit(const Date& date, double amount, const string& desc) = 0;     //��Ǯ����
	virtual void withdraw(const Date& date, double amount, const string& desc) = 0;    //ȡǮ����
	virtual void settle(const Date& date) = 0;                     //������Ϣ��ÿ��1��1�յ��øú���

protected:
	void record(const Date& date, double amount, const string& desc);//��¼һ���ˣ�date�����ڣ�amount����desc��˵��
	void error(const string& msg) { cout << msg << endl; }

private:
	//Date lastdate;
	string id;              //�˺�ID
	double balance;         //���
	static double total;    //��¼�����˻����ܽ��ֵ

};



class SavingAccount :public Account
{
public:
	SavingAccount(const Date& date, const string& id, double rate);
	double Getrate() const { return rate; }

	void deposit(const Date& date, double amount, const string& desc);     //��Ǯ����
	void withdraw(const Date& date, double amount, const string& desc);    //ȡǮ����
	void settle(const Date& date);                     //������Ϣ��ÿ��1��1�յ��øú���
	

private:
	Accumulator acc;
	double		rate;            //����������

};


class CreditAccount :public Account
{
public:
	CreditAccount(const Date& date, const string& id, double credit, double rate, double fee);

	double GetDebt() const { return -Getbalance(); }                        //ծ��
	double GetCredit() const { return credit; }                             //������ö��
	double GetRate() const { return rate; }                                 //����������
	double GetFee() const { return fee; }                                   //������
	double GetAvaliableCredie() const { return credit + Getbalance(); }     //���ö��

	void deposit(const Date& date, double amount, const string& desc);     //��Ǯ����
	void withdraw(const Date& date, double amount, const string& desc);    //ȡǮ����
	void settle(const Date& date);                     //������Ϣ��ÿ��1��1�յ��øú���
	virtual void Show() const override;                               //��ʾ�˻���Ϣ


private:
	Accumulator acc;
	double
		credit,      //���ö��
		rate,        //������
		fee;         //���

};



#endif // !_SAVINGACCOUNT_

