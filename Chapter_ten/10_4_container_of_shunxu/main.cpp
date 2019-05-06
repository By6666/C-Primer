#include <iostream>
#include <list>   //链表
#include <deque>  //双端队列
#include <iterator>
using namespace std;


//输出指定的顺序容器的元素
template<class T>
void printContainer(const char* msg, const T& s)
{
	cout << msg << ":";
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, "  "));
	cout << endl;
}

int main()
{
	deque<int> s;         //deque双向队列是一种双向开口的连续线性空间，可以高效的在头尾两端插入和删除元素
	for (int i = 0; i < 10; i++)
	{
		int x;
		cin >> x;
		s.push_front(x);
	}
	printContainer("deque at first", s);

	//用s容器内容的逆顺序构造列表容器
	list<int> l(s.rbegin(), s.rend());
	printContainer("list at first", l);

	//将列表容器l的每相邻两个元素顺序颠倒
	list<int>::iterator iter = l.begin();
	while (iter != l.end())
	{
		int v = *iter;
		iter = l.erase(iter);
		l.insert(++iter, v);
	}
	printContainer("list at last", l);

	//用列表容器l的内容给s赋值，将s输出
	s.assign(l.begin(), l.end());
	printContainer("deque at last", s);


	system("pause");
	return 0;
}