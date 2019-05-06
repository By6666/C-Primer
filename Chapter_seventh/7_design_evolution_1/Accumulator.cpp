#include "Accumulator.h"


double Accumulator::Getsum(const Date& date) const                 //计算累加值
{
	return (sum + value*(lastDate.distance(date)));

}
void Accumulator::Change(const Date& date, double vaule)           //在指定日期更改数值
{
	sum = Getsum(date);
	lastDate = date;
	value = vaule;
}
void Accumulator::Reset(const Date& date, double vaule)            //重置函数
{
	sum = 0;
	lastDate = date;
	value = vaule;
}
