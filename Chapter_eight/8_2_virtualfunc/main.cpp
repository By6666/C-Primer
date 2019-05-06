#include "Derived.h"


int main()
{
//	Base1 base1;
	Base2 base2;
	Derived derived;

//	fun(&base1);
	fun(base2);
	fun(derived);


//	cout << sizeof(base1) << endl;

	Base1* p = new Derived();

	delete p;

	system("pause");
	return 0;
}