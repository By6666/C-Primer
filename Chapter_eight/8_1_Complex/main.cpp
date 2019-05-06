#include "Complex.h"

int main()
{
	int i=0, j=0;
	j = i++;
	cout << j << "   " << i << endl;
	Complex a(5, 4), b(2, 10), c;
	int a1 = 5, b1 = 2;
	cout << "a = "<<a; //a.display();
	cout << "b = "<<b; //b.display();

	c = a + b;
	cout << "c = a + b = "<<c; //c.display();
	c = a - b;
	cout << "c = a - b = "<<c; //c.display();

	c=++a; 
	cout << "a = " << a << "c = " << c; //a.display();
	cout << "b = " << b;
	c=b++;
	cout << "b = " << b << "c = " << c; //b.display();

	system("pause");
	return 0;
}


