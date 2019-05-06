#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include "Node.h"


template <class T>
class LinkedList
{
public:
	LinkedList();                                               //���캯��
	LinkedList(const LinkedList<T>& L);                         //���ƹ��캯��
	~LinkedList();                                              //��������
	LinkedList<T>& operator = (const LinkedList<T>& L);         //���������=

	void print();                                               //��ӡ������������ݼ�����Ŀ
	int GetSize() const { return size; }                        //����size
	bool isEmpty() const { return (front == rear) ? false : true; } //�����Ƿ�Ϊ��

	void reset(int pos = 0);                                    //��ʼ���α�λ��
	void next();                                                //ʹ�α��ƶ�����һ���ڵ�
	bool endOfList() const { return (currPtr == NULL) ? true : false; } //�α��Ƿ�����β
	int currentPosition();                                //�����α굱ǰλ��

	void insertFront(const T& item);                            //�ڱ�ͷ������
	void insertRear(const T& item);                             //�ڱ�β������
	void insertAt(const T& item);                               //�ڵ�ǰ���֮ǰ������
	void insertAfter(const T& item);                            //�ڵ�ǰ���֮�������

	T deleteFront();                                            //ɾ��ͷ���
	void deleteCurrent();                                       //ɾ����ǰ���
	T& data();                                                  //���ضԵ�ǰ����Ա���ݵ�����
	const T& data() const;                                      //���ضԵ�ǰ����Ա���ݵĳ�����
	void clear();                                               //��������ͷ����н����ڴ�ռ䡣������������operator=����

private:
	Node<T>* front, *rear;        //��ͷ�ͱ�βָ��
	Node<T>* prevPtr, *currPtr;   //��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
	int size;                     //���е�Ԫ�ظ���
	int position;                 //��ǰԪ���ڱ��е�λ����ţ���reset����ʹ��
	Node<T>* newNode(const T& item, Node<T>* ptrNext = NULL); //�����µĽ��
	void freeNode(Node<T>* p);    //�ͷŽ��
	void copy(const LinkedList<T>& L);  //������L���Ƶ���ǰ����
};

template <class T>
Node<T>* LinkedList<T>::newNode(const T& item, Node<T>* ptrNext) //�����µĽ��
{
	Node<T>* tempPtr = new Node<T>(item, ptrNext);
	return tempPtr;
}

template <class T>
void LinkedList<T>::freeNode(Node<T>* p)    //�ͷŽ��
{
	delete p;
}

template <class T>
void LinkedList<T>::copy(const LinkedList<T>& L)  //������L���Ƶ���ǰ����
{
	L.reset();
	for (int i = 0; i < L.size; i++)
	{
		insertRear(L.data());
		L.next();
	}
}

template <class T>
LinkedList<T>::LinkedList()                                    //���캯��
{
	size = 0;
	front = rear = new Node<T>(0);
	currPtr = prevPtr = front;
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L)                         //���ƹ��캯��
{
	size = 0;
	front = rear = new Node<T>(0);
	currPtr = prevPtr = front;
	copy(L);
	cout << "���ø��ƹ��캯��" << endl;
}

template <class T>
LinkedList<T>::~LinkedList()                                              //��������
{
	clear();
	delete front;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& L)         //���������=
{
	clear();
	front->next = NULL;
	copy(L);
	cout << "�������������=" << endl;
	return *this;
}

template <class T>
void LinkedList<T>::print()                                               //��ӡ������������ݼ�����Ŀ
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
void LinkedList<T>::reset(int pos)                                    //��ʼ���α�λ��
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
void LinkedList<T>::next()                                                //ʹ�α��ƶ�����һ���ڵ�
{
	prevPtr = currPtr;
	currPtr = currPtr->nextNode();
}

template <class T>
int LinkedList<T>::currentPosition()                                 //�����α굱ǰλ��
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
void LinkedList<T>::insertFront(const T& item)                            //�ڱ�ͷ������
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
void LinkedList<T>::insertRear(const T& item)                             //�ڱ�β������
{
	prevPtr = currPtr;
	currPtr = newNode(item, rear->nextNode());
	rear->next = currPtr;
	rear = currPtr;
	size++;
}

template <class T>
void LinkedList<T>::insertAfter(const T& item)                               //�ڵ�ǰ���֮�������
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
void LinkedList<T>::insertAt(const T& item)                            //�ڵ�ǰ���֮ǰ������
{
	currPtr = newNode(item, prevPtr->nextNode());
	precPtr->next = currPtr;
	size++;
}

template <class T>
T LinkedList<T>::deleteFront()                                            //ɾ��ͷ���
{
	currPtr = front->nextNode();
	delete front;
	front = currPtr;
	size--;
	return front->data;
}

template <class T>
void LinkedList<T>::deleteCurrent()                                       //ɾ����ǰ���
{
	Node<T>* tempPtr = currPtr;
	prevPtr->deleteAfter();
	delete tempPtr;
	currPtr = prevPtr;
	size--;
}

template <class T>
T& LinkedList<T>::data()                                                  //���ضԵ�ǰ����Ա���ݵ�����
{
	return currPtr->data;
}

template <class T>
const T& LinkedList<T>::data() const                                      //���ضԵ�ǰ����Ա���ݵĳ�����
{
	return currPtr->data;
}

template <class T>
void LinkedList<T>::clear()                                               //��������ͷ����н����ڴ�ռ䡣������������operator=����
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
