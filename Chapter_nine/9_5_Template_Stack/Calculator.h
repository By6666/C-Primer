#ifndef _CALCULATOR_
#define _CALCULATOR_

#include "Stack.h"
#include <sstream>

class Calculator
{
public:
	void run();                  //���м���������
	void clear();                //��ղ���ջ

private:
	Stack<double> s;                                     //������ջ
	void enter(double num);                              //��������numѹ��ջ
	bool getTwoOperands(double& opnd1, double& opnd2);  //�������������������ֱ����open1��opend2��
	void computer(char op);                              //ִ���ɲ�����opָ��������

};










#endif // !_CALCULATOR_

