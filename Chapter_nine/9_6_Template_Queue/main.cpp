#include "Queue.h"


int main()
{
	Queue<int,10> q;

	for (int i = 0; i < 20; i++)
	{
		q.insert(i);
		cout<<q.remove()<<"  ";
	}
	cout << endl;
	cout << q.getFront() << "  " << q.getLength() << "  " << q.isEmpty() << "  " << q.isFull() << endl;

	//cout << q.remove() << endl;

	//cout << q.getFront() << "  " << q.getLength() << "  " << q.isEmpty() << "  " << q.isFull() << endl;
	//cout << q.remove() << endl;
	//cout << q.getFront() << "  " << q.getLength() << "  " << q.isEmpty() << "  " << q.isFull() << endl;
	//cout << q.remove() << endl;
	//cout << q.remove() << endl;
	//cout << q.remove() << endl;
	//cout << q.getFront() << "  " << q.getLength() << "  " << q.isEmpty() << "  " << q.isFull() << endl;
	//cout << q.remove() << endl;


	system("pause");
	return 0;
}