#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

//将来自输入迭代器的n个T类型的数值排序，将结果通过输出迭代器result输出
template<class T, class InputIterator, class OutputTterator>
void mySort(InputIterator first, InputIterator last, OutputTterator result)
{
	vector<T> s;
	for (;first != last;first++)  s.push_back(*first); //通过输入迭代器将输入数据存入s容器
	//对s进行排序，sort函数的参数必须是随机访问的迭代器 
	sort(s.begin(), s.end());           //升序排列
//	sort(s.rbegin(), s.rend());         //降序排列           
	copy(s.begin(), s.end(), result);   //将s序列通过输出迭代器输出
}

int main()
{
	double a[5] = { 1.2,2.4,0.8,3.3,3.2 };
	mySort<double>(a,a+5,ostream_iterator<double>(cout,"\t"));
	cout << endl;
	mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, "\t"));
	cout << endl;



	system("pause");
	return 0;
}