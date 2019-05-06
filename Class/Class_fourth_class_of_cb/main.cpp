#include "line.h"

int main()
{
	Point a[2] = { Point(1,1),Point(4,5) };    //对象数组
	int(*p1)[3];
	Point* p2;
	cout << sizeof(*p1) << "  " << sizeof(p2) << endl;//说明指针变量的大小恒定，且跟操作系统的位数有关，64位系统恒为8Byte
	//Point *ptr;                                //对象指针
	//ptr = new Point;                           //动态内存分配，new运算符返回的是所申请内存的首地址
	//delete ptr;                                //delete操作符是删除指针所指对象的内存空间，不会将指针变量进行删除
	//ptr = new Point(1, 1);                     //第二种内存申请方式，直接赋值
	//delete ptr;

	Point myp1(1,1), myp2(4,5);
	myp1 = myp2;
	//const Point  a(0,0);                      //常对象，不能被修改，定义时必须初始化
	//a.setx(1);                             //这样写就会报错
	//a.getY();                              //这样写会报错，因为常对象只能调用他的常成员函数
	Point::ShowCnt();
	Line ultimate(myp1, myp2);               //参数传递顺序从右向左
	//Line ul_2(ultimate);

	//cout << "Distence of two point is " << ul_2.getDis() << endl;
	cout << "Distence of two point is " << dist(myp1,myp2) << endl;
//	cout << "Distence of two point is " << dist(a[0], a[1]) << endl;

	myp1.ShowCnt();
	myp2.ShowCnt();

	system("pause");
	return 0;
}

