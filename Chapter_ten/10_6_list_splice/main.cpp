//splice函数，接合操作
//调用：s1.splice(p,s2,q1,q2);
//将s2中[q1,q2)范围中的节点移动到s1中p所指向的元素之前
//移动过后，s2中不再有[q1,q2)范围中的节点

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
using namespace std;


int main()
{
	string names1[] = { "Alice","Helen","Lucy","Susan" };   //定义两个数组string类
	string names2[] = { "Bob","David","Levin","Mike" };
	 
	list<string> s1(names1, names1 + 4);    //使用string数组类初始化s1，s2
	list<string> s2(names2, names2 + 4);

	s2.splice(s2.end(), s1, s1.begin());    //将s1的首元素接合到s2的末尾
	list<string>::iterator iter1 = s1.begin(); //声明指针iter1指向s1.bengin
	advance(iter1, 2);                      //iter1向前移动两个元素，其将指向name1的第三个元素

	list<string>::iterator iter2 = s2.begin(); //声明指针iter2指向s2.bengin
	++iter2;                                   //iter2后移一位

	list<string>::iterator iter3 = iter2;    //将iter2赋予iter3
	advance(iter3, 2);                       //iter3前移2位，将指向name2的尾元素

	s1.splice(iter1, s2, iter2, iter3);      //将[iter2,iter3）范围的节点移动到iter1之前

    //输出s1和s2
	copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, "  "));   
	cout << endl;
	copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, "  "));
	cout << endl;

	array<int,10> a;

	system("pause");
	return 0;
}