//继承的方式：1、共有继承，2、私有继承，3、保护继承

//公有继承：基类的public和protect在派生类中的访问属性不变，private不能直接访问
//          派生类的成员函数：可以直接访问基类中的public、protect，但不能访问private
//          派生类的对象：    只能访问基类的public成员（当然也包括派生类自己的public）

//私有继承：基类的public和protect在派生类中的访问属性变为private，private不能直接访问
//          派生类的成员函数：可以直接访问基类中的public、protect，但不能访问private
//          派生类的对象：    不能访问基类的任何成员

//保护继承：基类的public和protect在派生类中的访问属性变为protect，private不能直接访问
//          派生类的成员函数：可以直接访问基类中的public、protect，但不能访问private
//          派生类的对象：    不能访问基类的任何成员


#ifndef _DERIVE_
#define _DERIVE_
#include "line.h"

class Derive:public Point
{
public:
	Derive() { cout << "Calling a Derive class" << endl; };
	Derive(int a, int b, int w, int h)
		:Point(a,b),w(w),h(h),p(a,b)
	{}
	Derive(const Derive&d);
	
	void asda() { w=Point::getX(); }

private:
	int w, h;
	Point p;
};

Derive::Derive(const Derive&d)                   //派生类的复制构造函数，复制时只需要将派生类的对象直接传给基类就可以了
	:Point(d),p(d.p),w(d.w),h(d.h)               //因为内部有一个隐含转换，派生类的对象可以隐含转化为基类对象
{}                                               //自己写了复制构造函数就不会再生成默认构造函数，在自己写的复制构造函数中，没有写的成员就按照默认的方式进行初始化



#endif // !_DERIVE_

