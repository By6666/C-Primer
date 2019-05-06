#include <iostream>
using namespace std;
bool judge_huiwen(unsigned x);

int main()                                       //求11~999之间，n、n*n、n*n*n都为回文的数
{
	unsigned n(0);
	cout << "满足条件的数有：\n";
	for (int i = 11; i < 1000; i++)
	{
		if (judge_huiwen(i) && judge_huiwen(i*i) && judge_huiwen(i*i*i))
		{
			cout << i << " ";
		}
			
	}
	cout << endl;
		

	system("pause");
	return 0;
}


bool judge_huiwen(unsigned x)          //判断是否为回文，即将数据进行反转与原数据进行比较看是否相等
{
	unsigned v(x),     //存放进来X的值，看作是原数据
		     m(0);     //存放回文

	while (x>0)
	{
		m = m * 10 + x % 10;
		x /= 10;
	}

	return m == v;                    //直接返回bool类型
}