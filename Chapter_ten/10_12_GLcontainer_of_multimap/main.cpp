//multimap允许重复的键值插入容器
//        **********************************************************    
//        * pair只包含一对数值:pair<int,char>                       *
//        * map是一个集合类型，永远保持排好序的，                   *
//  pair  * map每一个成员就是一个pair,例如：map<int,char>           *
//        * map的insert()可以把一个pair对象作为map的参数,例如map<p> *
//        ***********************************************************

#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <map>

using namespace std;


int main()
{
	multimap<string, string> courses;
	typedef multimap<string, string>::iterator CourseIter;

	//插入课程上课时间
	courses.insert(make_pair("C++", "2-6"));
	courses.insert(make_pair("COMPILER", "3-1"));
	courses.insert(pair<string, string>("COMPILER", "5-2"));
	courses.insert(make_pair("OS", "1-2"));
	courses.insert(make_pair("OS", "4-1"));
	courses.insert(make_pair("OS", "5-5"));

	//输入一个课程名，直到找到该课程为止，记下每周上课次数
	string name;
	int count;

	do
	{
		cin >> name;
		count = courses.count(name);
		if (count == 0)  cout << "Can not find this course !!" << endl;

	} while (count == 0);

	cout << count << "  lesson(s) per week:";
	pair<CourseIter, CourseIter> range = courses.equal_range(name);

	for (CourseIter iter = range.first;iter != range.second;++iter)
		cout << iter->second << "  ";

	cout << endl;



	system("pause");
	return 0;
}