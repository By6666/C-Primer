#ifndef _ACCUMULATOR_
#define _ACCUMULATOR_

#include "Date.h"

class Accumulator
{
public:
	Accumulator(const Date& date,double vaule)
		:lastDate(date),value(vaule),sum(0)
	{}


	double Getsum(const Date& date) const;                 //计算累加值
	void Change(const Date& date, double vaule);           //在指定日期更改数值
	void Reset(const Date& date, double vaule);            //重置函数


private:
	Date lastDate;        //变更前日期
	double value,         //当前累加数值
		   sum;           //变更前的累加总和

};





#endif // !_ACCUMULATOR_

