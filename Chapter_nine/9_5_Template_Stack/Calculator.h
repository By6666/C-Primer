#ifndef _CALCULATOR_
#define _CALCULATOR_

#include "Stack.h"
#include <sstream>

class Calculator
{
public:
	void run();                  //运行计算器程序
	void clear();                //清空操作栈

private:
	Stack<double> s;                                     //操作数栈
	void enter(double num);                              //将操作数num压入栈
	bool getTwoOperands(double& opnd1, double& opnd2);  //连续弹出两个操作数分别放在open1，opend2中
	void computer(char op);                              //执行由操作符op指定的运算

};










#endif // !_CALCULATOR_

