#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;


template <typename T>      //����ģ�壬ʹ��template�ؼ��֣����������еĹؼ��ֿ�����typename��Ҳ������class
T abs(T x)
{
	return x < 0 ? -x : x;
}

int main()
{
	int a = -5;
	double b = -5.236987;

	cout << abs<int>(a) << endl;     //ʹ�õ�ʱ����<>����
	cout << abs<double>(b) << endl;



	system("pause");
	return 0;
}