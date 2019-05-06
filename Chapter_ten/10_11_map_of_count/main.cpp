#include <iostream>
#include <string>
#include <iterator>
#include <utility>
#include <map>
#include <cctype>        //C++ 字符处理库，里面包含许多字符处理函数

using namespace std;


int main()
{
	map<char, int> s;  //用来存储字母出现的次数
	char c;
	do
	{
		cin >> c;       //输入字母
		if (isalpha(c)) //判断是否为字母
		{
			c = tolower(c);  //将字母转换为小写
			s[c]++;          //出现频率加+1
		}
	} while (c != '.');      //到'.'结束

	for (map<char, int>::iterator iter = s.begin();iter != s.end();++iter)         
		cout << iter->first << " display number ->" << iter->second << endl;    //输出每个字母以及其出现的次数

	cout << endl;







	system("pause");
	return 0;
}