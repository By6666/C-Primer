#ifndef _STACK_
#define _STACK_

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

template<class T, int SIZE = 50>
class Stack
{
public:
	Stack()
		:top(-1)
	{}

	void push(const T& item);                      //��ջ
	T pop();                                       //��ջ
	void clear() { top = -1; }                     //���ջ
	const T& peek() const;                         //��ȡջ����Ԫ��
	bool isEmpty() const { return (top < 0) ? true : false; }            //�ж��Ƿ�ջ��
	bool isFull()  const { return (top >= (SIZE - 1)) ? true : false; }  //�ж��Ƿ�ջ��

private:
	T list[SIZE];
	int top;                           //ָ��ջ����ָ��
};

template<class T, int SIZE>
void Stack<T, SIZE>::push(const T& item)
{
	assert(!isFull());               //0:����  1:��ȷ
	list[++top] = item;
}
template<class T, int SIZE>
T Stack<T, SIZE>::pop()                          //��ջ
{
	assert(!isEmpty());
	return list[top--];
}

template<class T, int SIZE>
const T& Stack<T, SIZE>::peek() const            //��ȡջ����Ԫ��
{
	assert(!isEmpty());
	return list[top];                            //����ջ��Ԫ��
}




#endif // !_STACK_

