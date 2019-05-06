#ifndef _ACCUMULATOR_
#define _ACCUMULATOR_

#include "Date.h"

class Accumulator
{
public:
	Accumulator(const Date& date,double vaule)
		:lastDate(date),value(vaule),sum(0)
	{}


	double Getsum(const Date& date) const;                 //�����ۼ�ֵ
	void Change(const Date& date, double vaule);           //��ָ�����ڸ�����ֵ
	void Reset(const Date& date, double vaule);            //���ú���


private:
	Date lastDate;        //���ǰ����
	double value,         //��ǰ�ۼ���ֵ
		   sum;           //���ǰ���ۼ��ܺ�

};





#endif // !_ACCUMULATOR_

