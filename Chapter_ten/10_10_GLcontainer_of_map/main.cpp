//关联容器-map（映射）
//映射与集合同属于关联容器，他们的主要区别在于--集合的元素类型是键本身，而映射元素类型是由键和附加数据所构成的二元组（这里需要使用pair类型）
//集合中按键查找一个元素时，一般是用来判断这个元素是否存在，二映射中按照键查找一个元素时，除了能确定他的存在性外，还可以得到相应的附加数据

#include <iostream>
#include <string>
#include <iterator>
#include <utility>
#include <map>

using namespace std;

 

int main()
{
	map<string, int> courses;
	//将课程信息插入courses映射中
	courses.insert(make_pair("CSAPP", 3));
	courses.insert(pair<string,int>("C++", 2));
	courses.insert(make_pair("CSARCH", 4));
	courses.insert(make_pair("COMPILER", 4));
	courses.insert(make_pair("OS", 5));

	//输出所有课程和学分
	map<string, int>::iterator iter = courses.begin();
	cout << "All----(course name,vaule)" << endl;
	while (iter != courses.end())
	{
		cout << "(" << iter->first << "," << iter->second << ")";
		cout << "      ";
		iter++;
	}
	cout << endl;

	int n = 3;      //剩下的可选次数
	int sum = 0;    //学分总和

	while (n > 0)
	{
		string name;
		cin >> name;
		map<string, int>::iterator iter = courses.find(name);
		if (iter == courses.end())  cout << name << " is not available !!" << endl;
		else
		{
			cout << "choice succeed !!" << endl;
			sum += iter->second;
			courses.erase(iter);
			n--;
		}
	}
	cout << "Total credit: " << sum << endl;  //输出总学分





	system("pause");
	return 0;
}
