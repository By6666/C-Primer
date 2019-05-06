//除了构造函数和静态成员函数不能是虚函数外，析构函数也可以是虚函数


//*************纯虚函数***************
//拥有纯虚函数的类成为抽象类，这样的类不能进行实体化，也就是说不能定义该类的对象，就只能用来做基类
//因为纯虚函数是很多派生类的基类，所以这样就统一了函数的接口，也就是说，我就一个接口，但是接上不同类型的东西以后还能实现与该东西相匹配的功能

#ifndef _DERIVED_
#define _DERIVED_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;


class Base1 
{
public:
	virtual void display() const ;
//	virtual void display() const = 0;     //纯虚函数
	virtual~Base1() { cout << "destroy a base1!!" << endl; }

};

class Base2:public Base1
{
public:
	void display() const override { cout << "Base2::display()" << endl; }  //override是让编译器替我们检查虚函数的重载是否正确
};

class Derived :public Base2
{
public:
	void display()const { cout << "Derived::display()" << endl; }
	virtual ~Derived() { cout << "destroy a Derives!!" << endl; }
};

void fun(Base1* ptr);
void fun(const Base1& ptr);      //这个函数就是一个接口，通过这个接口可以接上不同种类的东西然后实现相应的功能，是多态性的体现

#endif // !_DERIVED_

