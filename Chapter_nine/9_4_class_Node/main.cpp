#include "Node.h"
#include "LinkedList.h"


int main()
{
	//Node<int> c(15,0); 
	//Node<int> b(10,&c);
	//Node<int> a(5, &b);
	//Node<int> a1(6,0);

	//a.insertAfter(&a1);

	//cout << a.deleteAfter()->GetData() << endl;

	LinkedList<int> list;
	cout << list.data() << endl;
	cout << "Please input ten num:" << endl;
	for (int i = 0; i < 10; i++)
	{
		int item;
		cin >> item;
		list.insertRear(item);
	}
	cout << endl;
	cout << "list:" << endl;
	list.print();
	cout << "currentPosition: " << list.currentPosition() << endl;     //µ±Ç°Î»ÖÃ

	cout << endl;
	cout << "Please input the num of delete:" << endl;
	int item;
	cin >> item;

	list.reset();
	while (!list.endOfList())
	{
		if (list.data() == item) list.deleteCurrent();	
		list.next();
	}
	list.print();


	system("pause");
	return 0;
}