#include "Derived.h"

void fun(Base1* ptr)      //这个函数就是一个接口，通过这个接口可以接上不同种类的东西然后实现相应的功能，是多态性的体现
{
	ptr->display();
}

void Base1::display() const
{ 
	cout << "Base1::display()" << endl; 
}
void fun(const Base1& ptr)      //这个函数就是一个接口，通过这个接口可以接上不同种类的东西然后实现相应的功能，是多态性的体现
{
	ptr.display();
}
