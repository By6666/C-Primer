#include <iostream>
#include <vector>
using namespace std;

int b[10];                            //全局数组默认初始化为0

int main()
{
	vector <int> brr(5,1);
	cout << brr.size() << endl;

	static int a[10];                 //数组的定义,若定义为静态数组则初始值自动默认为0
	                                  //           若是局部的非静态数组则初始化为垃圾数据
	//数组初始化的三种方式（二维数组初始化类推）
	//int a[10] = { 0,1,2,3,4,5,6,7,8,9 }; //1、列出全部元素的初始值
	//int a[10] = { 0,1,2,3,4 };           //2、列出部分元素的初始值（则剩下的元素会被自动初始化为0）
	//int a[] = { 0,1,2,3,4,5,6,7,8,9 };   //3、列出全部元素的初始值，可以不指定数组的长度

	a[0] = 55;
	a[1] = 66;
	cout << "a[0]= " << *(b+2) << endl;

	for (int &p : brr)                      //基于范围的for循环，方便处理容器类的数据
	{
		cout << p << "  ";
	}
	cout << endl;

	system("pause");
	return 0;
}