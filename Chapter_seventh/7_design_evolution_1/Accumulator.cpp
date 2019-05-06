#include "Accumulator.h"


double Accumulator::Getsum(const Date& date) const                 //�����ۼ�ֵ
{
	return (sum + value*(lastDate.distance(date)));

}
void Accumulator::Change(const Date& date, double vaule)           //��ָ�����ڸ�����ֵ
{
	sum = Getsum(date);
	lastDate = date;
	value = vaule;
}
void Accumulator::Reset(const Date& date, double vaule)            //���ú���
{
	sum = 0;
	lastDate = date;
	value = vaule;
}
