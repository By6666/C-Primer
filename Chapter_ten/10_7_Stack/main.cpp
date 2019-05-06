//利用  栈   反向输出单词
#include <iostream>
#include <string>
#include <functional>       //函数对象头文件
#include <iterator>         //迭代器头文件
#include <algorithm>        //算法头文件
//容器类的头文件
#include <vector>           //向量
#include <list>             //链表
#include <forward_list>     //单向链表
#include <array>            //数组
#include <stack>            //栈
#include <queue>            //队列

using namespace std;


int main()
{
	stack<char> s;
	string str;
	cin >> str;      //从键盘输入一个字符串

	for (string::iterator iter = str.begin();iter != str.end();++iter)
		s.push(*iter);        //入栈

	while (!s.empty())
	{
		cout << s.top();      //打印栈头
		s.pop();              //弹出栈头元素
	}

	cout << endl;



	system("pause");
	return 0;
}