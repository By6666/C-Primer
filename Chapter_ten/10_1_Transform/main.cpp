#include <iostream>
#include <vector>               //vector类 头文件
#include <iterator>             //迭代器 头文件
#include <algorithm>            //算法 头文件
#include <functional>           //函数对象 头文件
using namespace std;

int main()
{
	const int N = 5;
	vector<int> s(5);
	for (int i = 0; i < N; i++)		cin >> s[i];

	//algorithm of transform顺序遍历first和last两个迭代器所指向的元素,下面是函数实现
	//template <class InputIterator,class OutputIterator,class UnaryFunction>
	//OutputIterator transform(InputIterator fitst,InputIterator last,OutputIterator result,UnaryFunction op);
	transform(s.begin(), s.end(), ostream_iterator<int>(cout, " "), negate<int>());
	cout << endl;


	int a[2] = { 1,2 };
	ostream_iterator<int> abc(cout,"\n");         //输出迭代器

	*abc++ = a[0];
	*abc++ = a[1];




	system("pause");
	return 0;
}