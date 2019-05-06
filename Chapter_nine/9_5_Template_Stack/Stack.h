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

	void push(const T& item);                      //入栈
	T pop();                                       //出栈
	void clear() { top = -1; }                     //清空栈
	const T& peek() const;                         //读取栈顶的元素
	bool isEmpty() const { return (top < 0) ? true : false; }            //判断是否栈空
	bool isFull()  const { return (top >= (SIZE - 1)) ? true : false; }  //判断是否栈满

private:
	T list[SIZE];
	int top;                           //指向栈顶的指针
};

template<class T, int SIZE>
void Stack<T, SIZE>::push(const T& item)
{
	assert(!isFull());               //0:错误  1:正确
	list[++top] = item;
}
template<class T, int SIZE>
T Stack<T, SIZE>::pop()                          //出栈
{
	assert(!isEmpty());
	return list[top--];
}

template<class T, int SIZE>
const T& Stack<T, SIZE>::peek() const            //读取栈顶的元素
{
	assert(!isEmpty());
	return list[top];                            //返回栈顶元素
}




#endif // !_STACK_

