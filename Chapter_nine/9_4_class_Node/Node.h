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
void Node<T>::insertAfter(Node<T>* p)             //�ڵ���뺯����˳���ܸı�
{                                   //����˳���ܸı�
	p->next = this->next;           //��ʹ��Ҫ����Ľڵ�ָ�����Ľڵ�
	this->next = p;                 //��ʹ֮ǰ�Ľڵ�ָ�����Ľڵ�
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
Node<T>* Node<T>::nextNode()                     //��ȡ��̽��ĵ�ַ
{                                                //����ֵΪ��������ʱΪ��ֵ������Ϊ��ֵ
	return this->next;
}


template <class T>
const Node<T>* Node<T>::nextNode() const
{
	return this->next;
}










#endif // !_NODE_

