//奇偶排序
//先按照从大到小的顺序输出奇数，再按照从小到大顺序输出偶数
#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;


int main()
{
	istream_iterator<int> i1(cin), i2; //建立一对输入输入流迭代器
	vector<int> s1(i1, i2);            //通过输入流迭代器从标准输入流中输入数据
	sort(s1.begin(), s1.end());        //排序
	deque<int> s2;

	for (vector<int>::iterator iter = s1.begin();iter != s1.end();++iter)
	{
		if (*iter % 2 == 0)
			s2.push_back(*iter);      //偶数放到s2尾部
		else
			s2.push_front(*iter);     //奇数放到s2首部
	}

	copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));  //输出s2
	cout << endl;

	system("pause");
	return 0;
}