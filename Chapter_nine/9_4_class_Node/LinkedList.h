#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include "Node.h"


template <class T>
class LinkedList
{
public:
	LinkedList();                                               //构造函数
	LinkedList(const LinkedList<T>& L);                         //复制构造函数
	~LinkedList();                                              //析构函数
	LinkedList<T>& operator = (const LinkedList<T>& L);         //重载运算符=

	void print();                                               //打印链表类里的数据及其数目
	int GetSize() const { return size; }                        //返回size
	bool isEmpty() const { return (front == rear) ? false : true; } //链表是否为空

	void reset(int pos = 0);                                    //初始化游标位置
	void next();                                                //使游标移动到下一个节点
	bool endOfList() const { return (currPtr == NULL) ? true : false; } //游标是否到了链尾
	int currentPosition();                                //返回游标当前位置

	void insertFront(const T& item);                            //在表头插入结点
	void insertRear(const T& item);                             //在表尾插入结点
	void insertAt(const T& item);                               //在当前结点之前插入结点
	void insertAfter(const T& item);                            //在当前结点之后插入结点

	T deleteFront();                                            //删除头结点
	void deleteCurrent();                                       //删除当前结点
	T& data();                                                  //返回对当前结点成员数据的引用
	const T& data() const;                                      //返回对当前结点成员数据的常引用
	void clear();                                               //清空链表：释放所有结点的内存空间。被析构函数、operator=调用

private:
	Node<T>* front, *rear;        //表头和表尾指针
	Node<T>* prevPtr, *currPtr;   //记录当前遍历位置的指针，由插入和删除操作更新
	int size;                     //表中的元素个数
	int position;                 //当前元素在表中的位置序号，由reset函数使用
	Node<T>* newNode(const T& item, Node<T>* ptrNext = NULL); //生成新的结点
	void freeNode(Node<T>* p);    //释放结点
	void copy(const LinkedList<T>& L);  //将链表L复制到当前链表
};

template <class T>
Node<T>* LinkedList<T>::newNode(const T& item, Node<T>* ptrNext) //生成新的结点
{
	Node<T>* tempPtr = new Node<T>(item, ptrNext);
	return tempPtr;
}

template <class T>
void LinkedList<T>::freeNode(Node<T>* p)    //释放结点
{
	delete p;
}

template <class T>
void LinkedList<T>::copy(const LinkedList<T>& L)  //将链表L复制到当前链表
{
	L.reset();
	for (int i = 0; i < L.size; i++)
	{
		insertRear(L.data());
		L.next();
	}
}

template <class T>
LinkedList<T>::LinkedList()                                    //构造函数
{
	size = 0;
	front = rear = new Node<T>(0);
	currPtr = prevPtr = front;
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L)                         //复制构造函数
{
	size = 0;
	front = rear = new Node<T>(0);
	currPtr = prevPtr = front;
	copy(L);
	cout << "调用复制构造函数" << endl;
}

template <class T>
LinkedList<T>::~LinkedList()                                              //析构函数
{
	clear();
	delete front;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& L)         //重载运算符=
{
	clear();
	front->next = NULL;
	copy(L);
	cout << "调用重载运算符=" << endl;
	return *this;
}

template <class T>
void LinkedList<T>::print()                                               //打印链表类里的数据及其数目
{
	reset();
	while (!endOfList())
	{
		cout << data() << " ";
		next();
	}
	cout << endl;
	cout << "size = " << GetSize() << endl;
}

template <class T>
void LinkedList<T>::reset(int pos)                                    //初始化游标位置
{
	prevPtr = front;
	currPtr = front->nextNode();
	position = pos;
	for (int i = 0; i < position; i++)
	{
		prevPtr = currPtr;
		currPtr = currPtr->nextNode();
	}
}

template <class T>
void LinkedList<T>::next()                                                //使游标移动到下一个节点
{
	prevPtr = currPtr;
	currPtr = currPtr->nextNode();
}

template <class T>
int LinkedList<T>::currentPosition()                                 //返回游标当前位置
{
	Node<T>* tempPtr = front->nextNode();
	position = 0;
	while (tempPtr != currPtr)
	{
		tempPtr = tempPtr->nextNode();
		position++;
	}
	return position;
}

template <class T>
void LinkedList<T>::insertFront(const T& item)                            //在表头插入结点
{
	prvePtr = currPtr;
	currPtr = newNode(item, front->nextNode());
	front->next = currPtr;
	if (rear == front)
	{
		rear = currPtr;
	}
	size++;
}

template <class T>
void LinkedList<T>::insertRear(const T& item)                             //在表尾插入结点
{
	prevPtr = currPtr;
	currPtr = newNode(item, rear->nextNode());
	rear->next = currPtr;
	rear = currPtr;
	size++;
}

template <class T>
void LinkedList<T>::insertAfter(const T& item)                               //在当前结点之后插入结点
{
	prvePtr = currPtr;
	Node<T>* tempPtr = newNode(item, currPtr->nextNode());
	currPtr->next = tempPtr;
	if (currPtr == rear)
	{
		rear = tempPtr;
	}
	currPtr = tempPtr;
	size++;
}

template <class T>
void LinkedList<T>::insertAt(const T& item)                            //在当前结点之前插入结点
{
	currPtr = newNode(item, prevPtr->nextNode());
	precPtr->next = currPtr;
	size++;
}

template <class T>
T LinkedList<T>::deleteFront()                                            //删除头结点
{
	currPtr = front->nextNode();
	delete front;
	front = currPtr;
	size--;
	return front->data;
}

template <class T>
void LinkedList<T>::deleteCurrent()                                       //删除当前结点
{
	Node<T>* tempPtr = currPtr;
	prevPtr->deleteAfter();
	delete tempPtr;
	currPtr = prevPtr;
	size--;
}

template <class T>
T& LinkedList<T>::data()                                                  //返回对当前结点成员数据的引用
{
	return currPtr->data;
}

template <class T>
const T& LinkedList<T>::data() const                                      //返回对当前结点成员数据的常引用
{
	return currPtr->data;
}

template <class T>
void LinkedList<T>::clear()                                               //清空链表：释放所有结点的内存空间。被析构函数、operator=调用
{
	Node<T>*tempPtr = front->nextNode();
	while (tempPtr != NULL)
	{
		Node<T>*tempQ = tempPtr;
		tempPtr = tempPtr->nextNode();
		delete tempQ;
		size--;
	}
	rear = front;
	currPtr = prevPtr = front;
}




#endif // !_LINKEDLIST_
