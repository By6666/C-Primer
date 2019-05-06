#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;


template <typename T>      //函数模板，使用template关键字，而参数表中的关键字可以是typename，也可以是class
T abs(T x)
{
	return x < 0 ? -x : x;
}

int main()
{
	int a = -5;
	double b = -5.236987;

	cout << abs<int>(a) << endl;     //使用的时候用<>符号
	cout << abs<double>(b) << endl;



	system("pause");
	return 0;
}