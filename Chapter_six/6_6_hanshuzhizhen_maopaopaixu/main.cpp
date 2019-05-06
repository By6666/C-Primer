//函数指针的使用，冒泡排序法
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

void sort(int* arr, int size, bool(*cmp)(int, int));
bool up(int a, int b);
bool down(int a, int b);


int main()
{
	int Numb,            //输入要排序数据的个数
		up_or_down;      //升序还是降序  up：1，down：0
	int* a;              //声明一个指针变量            
	cout << "请输入需要排序的数据个数：" << endl;
	cin >> Numb;
	cout << "请确定升序还是降序  up：1，down：0" << endl;
	cin >> up_or_down;
	cout << "请输入要排序的"<< Numb<<"个数据：" << endl;
	a = new int[Numb];   //动态申请numb个int型空间，并返回首地址给a
	for (int i = 0; i < Numb; i++) //打印动态分配的内存地址
	{
		cout << a + i << "  ";
	}
	cout << endl;
	for (int i = 0; i < Numb; i++)
	{
		cin >> *(a + i);
	}
	if(up_or_down)  sort(a, Numb, up);
	else            sort(a, Numb, down);

	cout << "排序过后为：" << endl;
	for (int i = 0; i < Numb; i++)
	{
		cout << *(a + i) << "  ";
	}
	cout << endl;


	system("pause");
	delete[] a;
	return 0;
}

void sort(int* arr, int size, bool(*cmp)(int, int))
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (!cmp(arr[i], arr[j]))
			{
				int temp;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}


bool up(int a, int b)
{
	if (a <= b)  return 1;
	else return 0;
}
bool down(int a, int b)
{
	if (a >= b) return 1;
	else return 0;
}