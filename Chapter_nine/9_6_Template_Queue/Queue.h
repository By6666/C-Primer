#ifndef _QUEUE_
#define _OUEUE_

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

#define Self 1                   //1:自己程序  0:原程序

template<class T, int SIZE = 50>
class Queue
{
public:
	Queue()
		:front(0), rear(0), count(0)
	{}

	void insert(const T& item);
	T remove();
	void clear();
	const T& getFront() const { return front; }
#if Self
	bool isEmpty() const { return (front == rear); }
	bool isFull()  const { return (rear-front == SIZE); }
	int getLength() const { return (rear - front); }


#else
	bool isEmpty() const { return (count == 0); }
	bool isFull()  const { return (count == SIZE); }
	int getLength() const { return count; }

#endif

private:
	int front, rear, count;    //对头指针、队尾指针、元素个数
	T list[SIZE];              //队列元素个数
};

#if Self
template<class T, int SIZE>
void Queue<T, SIZE>::insert(const T& item)
{
	assert((rear - front) != SIZE);
	list[rear%SIZE] = item;
	rear++;
}

template<class T, int SIZE>
T Queue<T, SIZE>::remove()
{
	assert(front != rear);
	front++;
	return list[(front-1)%SIZE];
}
#else
template<class T, int SIZE>
void Queue<T, SIZE>::insert(const T& item)
{
	assert(count != SIZE);
	count++;
	list[rear] = item;
	rear++;
	rear = (rear + 1) % SIZE;
}

template<class T, int SIZE>
T Queue<T, SIZE>::remove()
{
	assert(count != 0);
	int temp = front;
	count--;
	front = (front + 1) % SIZE;
	front++;
	return list[temp];
}
#endif

template<class T, int SIZE>
void Queue<T, SIZE>::clear() 
{
	front = rear = count = 0;
}



#endif // !_QUEUE_
