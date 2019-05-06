//关联容器--set（集合）
//set的特性是，所有元素都会根据元素的键值自动排序，set的元素不像map那样可以同时拥有实值(value)和键值(key),
//set元素的键值就是实值，实值就是键值。set不允许两个元素有相同的键值。

//集合用来存储一组无重复的元素（即没有相同的元素），集合本身是有序的，可以高效的查找指定元素，
//也可以方便地得到指定元素大小范围的元素在容器中所处的区间如：upper_bound()、lower_bound()、equal_range()
//equal_range()--返回集合中与给定值相等的上下限的两个迭代器

#include <iostream>
#include <iterator>
#include <utility>   //utility头文件定义重载的关系运算符,简化关系运算符的写入,他还定义了pair类型,该类型是一种模板类型,可以存储一对值.这些功能在库的其他地方使用.
#include <set>       //集合容器头文件

using namespace std;


int main()
{
	set<double> s;
	while (true)
	{
		double v;
		cin >> v;
		if (v == 0) break;  //输入0表示退出
		pair<set<double>::iterator, bool> r = s.insert(v);  //pair在<utility>头文件中,用于判断set容器中是否存在V
		if (!r.second)
			cout << v << " is exist !!" << endl;      //如果V已经存在，输出提示信息
	}
	//copy(s.begin(), s.end(), ostream_iterator<double>(cout, "  "));

	set<double>::iterator iter1 = s.begin();
	set<double>::iterator iter2 = s.end();

	double medium = (*iter1 + *(--iter2)) / 2;
	cout << "<=medium: ";
	copy(s.begin(), s.upper_bound(medium), ostream_iterator<double>(cout, "  "));   //upper_bound()--返回大于某个值元素的迭代器
	cout << endl;

	cout << ">=medium: ";
	copy(s.lower_bound(medium), s.end(), ostream_iterator<double>(cout, "  "));  //lower_bound()--返回指向大于（或等于）某值的第一个元素的迭代器
	cout << endl;





	system("pause");
	return 0;
}