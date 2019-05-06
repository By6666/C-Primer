#include <iostream>
using namespace std;


enum class MyEnum :char { MON='1', TUE, WED, THU, FRI };    //强枚举类无法直接输出

enum a
{
	M=1,T,W
};
int main()
{
	MyEnum s = MyEnum::FRI;
	int a;
	a = (char)MyEnum::FRI;
	cout << a << endl;

	cout <<M<< endl;

	system("pause");

	return 0;
}