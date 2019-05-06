#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "line.h"
using namespace std;

void (*func1)(int, int);           //函数指针

void func3(int a, int b);
int main()
{  
	vector<int> gfd(10);
	vector<int> tyu(gfd.begin(), gfd.end() - 1);   //使用gfd来初始化tyu
	cout << gfd.size() << endl;                     //输出10


	Point* asd;
	

	vector<int*>abc(5);
	vector<int>bcd(5);
	abc[0] = &bcd[0];

	////动态申请二维数组
	//int hang, lie;
	//cin >> hang >> lie;
	//int **abc;
	//abc = new int*[hang];
	//for (int i = 0; i < hang; i++)
	//{
	//	abc[i] = new int[lie];
	//}

	//ArrayofPoint points(2);     //动态数组类创建对象
	//points.element(0).getX();
	char str[] = "program";
	cout << str << endl;
	string a ( "aaaaaaa");
	cout << a << endl;
	a = a + str;
	vector<int>arr(5);            //使用vector类创建各种类型的数组，切记arr不代表数组的首地址,内部初始值都为0
	cout << arr[4] << endl;
	//auto p = arr.begin();
	//cout << *arr.begin()<< endl;
	for(auto &i:arr)
		cout << i << "  ";
	cout << endl; 
	//int a[3][4] = {0};           //基于范围for循环遍历二维数组
	//for (auto &row : a)
	//{
	//	for (int i : row)
	//	{
	//		cout << i << "  " << endl;
	//	}
	//}


	//vector<Point>prr(5);
	//prr[1].getX();

	//int* ptr;                //动态内存分配
	//ptr = new int();
	//*ptr = 10;
	//delete ptr; 
	//ptr = new int[10]{0};      //一维数组
	//ptr[1] = 10;
	//delete[] ptr;

	//Point* ptrc;            //类类型
	//ptrc = new Point;
	//ptrc->getX();
	//delete ptrc;

	//ptrc = new Point[2]{Point(1,1),Point(4,5)};    //数组类
	//ptrc[0].getX();
	//delete[] ptrc;

	//int(*ptre)[5];         //二维数组
	//ptre = new int[3][5];

	//Point pc[2];                     //对象数组的初始化
	//pc[1] = Point(1, 1);      
	//Point pc2[2] = { Point(1,1),Point(2,2) };

	//int a[10], b[10];              //指针数组
	//int *p[2] = { a,b };
	//cout << sizeof(p) << endl;
	//cout << p << endl;
	//cout << &p[0] << endl;
	//cout << p[0] << endl;
	//cout << a << endl;
	//cout << p[1] << endl;
	//
	//cout << sizeof(&a[0]) << endl;
	//cout << &a[0] << endl;
	//func1 = func3;
	//func1(5, 4);
	//cout << sizeof(func1) << endl;


	system("pause");
	return 0;
}


void func3(int a, int b)
{

}