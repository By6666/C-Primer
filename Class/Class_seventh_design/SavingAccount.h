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

	void deposit(const Date& date, double amount, const string& desc);     //��Ǯ����
	void withdraw(const Date& date, double amount, const string& desc);    //ȡǮ����
	void settle(const Date& date);                     //������Ϣ��ÿ��1��1�յ��øú���
	void Show() const;                               //��ʾ�˻���Ϣ

	static double GetTotal() { return total; }  //ͨ����̬��Ա��������̬���ݳ�Ա
	

private:
	string id;              //�˺�ID
	Date  lastDate;        //�ϴ����䶯����
	double 
		balance,          //���
		rate,            //����������
		accumulation;      //�����ۼ�֮��
	static double total;   //��¼�����˻����ܽ��ֵ

	void record(const Date& date, double amount, const string& desc);//��¼һ���ˣ�date�����ڣ�amount����desc��˵��
	double accumulate(const Date& date) const { return accumulation + balance*(lastDate.distance(date)); } //��õ�ָ������Ϊֹ�Ĵ����ۼ�ֵ

};



#endif // !_SAVINGACCOUNT_

