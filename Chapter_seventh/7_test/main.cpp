#include "line.h"
#include "Derive.h"

int main()
{
	Derive a(1,2,3,4);
//	a.asda();
	Derive b(a);
	cout << b.getX() << endl;
	



	system("pause");
	return 0;
}