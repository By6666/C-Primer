//函数适配器--绑定适配器：bind1st、bind2nd
//二元运算符有两个操作数，bind1st是将给定的操作数绑定到第一个位置，bind2nd是绑定到第二个位置

//函数适配器--组合适配器：not1、not2
//not1：用于一元谓词的逻辑取反
//not2：用于二元谓词的逻辑取反

//函数适配器--函数指针适配器：ptr_fun
//将一般函数的指针转化为函数对象，实质能够成为其他函数适配器的输入

#include <iostream>
#include <functional>     //函数对象头文件，包含函数对象和函数适配器
#include <vector>         //vector容器中含有相应的iterator
#include <algorithm>      //算法头文件，包含find_if等算法

using namespace std;

bool g(int x, int y)
{
	return x > y;
}

int main()
{
	int intArr[] = { 10,90,10,40,70,50,20,80 };
	const int N = sizeof(intArr) / sizeof(int);
	vector<int> a(intArr, intArr + N);
	//find_if算法，寻找[first,end)范围内的第一个满足条件的元素
	vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(greater<int>(), 10));              //输出第一个大于10的元素
    //vector<int>::iterator p = find_if(a.begin(), a.end(), not1(bind2nd(greater<int>(), 10)));      //输出第一个不大于10的元素
	//vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(not2(greater<int>()), 10));      //与上相同
	//vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(ptr_fun(g), 10));                //通过使用函数指针适配器ptr_fun，可以将一般的函数指针转化为函数对象

		if (p == a.end())    cout << "no element greater than 40" << endl;
	else  cout << "first element greater than 40 is: " << *p << endl;






	system("pause");
	return 0;
}