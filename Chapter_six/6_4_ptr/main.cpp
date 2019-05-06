#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int i=10;
	const int* ptr = &i;     //const指针，不能改变所指对象的值，但是可以改变指针本身（可以指向另外一个对象）
	                         //相当于一个只读的指针
	int j;
	ptr = &j;               //const指针本身是可以改变的
//	*ptr = 50;              //错误，指针对象不能修改

//当然也可以定义常量指针,即将指针本身定义为常量不能改变
	int* const ptr2 = &j;       //这样的指针可以修改该地址下的对象，不仅仅是可读，也可以写
	*ptr2 = 10;               //正确
//	ptr2 = &i;                //错误，指针本身不能再修改



	system("pause");
	return 0;
}