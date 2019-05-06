#ifndef _NODE_
#define _NODE_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

template <class T>
class LinkedList;

template <class T>
class Node
{
public:
	Node(const T& item, Node<T>* next = 0);
	void insertAfter(Node<T>* p);
	Node<T>* deleteAfter();
	Node<T>* nextNode();
	const Node<T>* nextNode() const;

	T GetData()const { return data; }

	friend LinkedList<T>;

private:
	Node<T>* next;
	T data;

};

template <class T>
Node<T>::Node(const T& item, Node<T>* next /*= 0*/)
	:data(item),next(next)
{}


template <class T>
void Node<T>::insertAfter(Node<T>* p)             //节点插入函数，顺序不能改变
{                                   //以下顺序不能改变
	p->next = this->next;           //先使需要插入的节点指向后面的节点
	this->next = p;                 //再使之前的节点指向插入的节点
}


template <class T>
Node<T>* Node<T>::deleteAfter()
{
	Node<T>* tempPtr = next;
	if (next == 0)  return 0;

	this->next = tempPtr->next;
	return tempPtr;
}


template <class T>
Node<T>* Node<T>::nextNode()                     //获取后继结点的地址
{                                                //返回值为引用类型时为左值，否则为右值
	return this->next;
}


template <class T>
const Node<T>* Node<T>::nextNode() const
{
	return this->next;
}










#endif // !_NODE_

