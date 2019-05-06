#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//对于二维数组a[3][4]来说其中a与a[0]的值相同,但指针的类型不同。a为一维数组类型的指针，a[0]为整数类型的指针

void Sum(int *p, int hang, int lie);


int main()
{
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int(*ptr)[4] = a;                         //数组指针，也叫行指针，与二维数组相同

	for (auto &elem : a)
	{
		for(int elem2:elem)
		cout << elem2<<"   ";
	}
	cout << endl;
	//求二维数组的行和列
	//int len1, len2, len3;    
	//cout << sizeof(a) << "  " << sizeof(a[0]) << "  " << sizeof(a[0][0]) << endl;
	//len1 = sizeof(a) / sizeof(int);
	//len2 = sizeof(a[0]) / sizeof(int);    //列数
	//len3 = len1 / len2;                   //行数
	//cout << len1 << "  " << len2 << "  " << len3 << endl;

	cout << ptr << endl;
	cout << *ptr << endl;
	cout << ptr+1 << endl;
	cout << ptr+2 << endl;
	Sum(*ptr, 3, 4);

	//for (auto &p : a)                       //基于范围的for循环，遍历整个二维数组
	//{
	//	for (int elem : p)
	//		cout << elem << "  ";
	//}
	//cout << endl;

	for (int i = 0; i < 3; i++)           //显示数组中所有元素的值
		for (int j = 0; j < 4; j++)
		{
			cout << *(*(a + i) + j) << " ";
		}
	cout << endl;

	cout << a << endl;                //会发现a的值与*a的值是相同的,*a=a[0],但他们的类型时不相同的
	cout << *a << endl;
	int *p = (int*)a;                 //因为a为数组类型的指针，所以要将其强制转化为整数类型的指针
	cout << *p << endl;
	cout << **a << endl;
	cout << a+1 << endl;              //a+1代表地址加了4*4字节
	cout << a+2 << endl;
	cout << "*************" << endl;
	for (int i = 0; i < 3; i++)       //打印所有a[i]的地址
	{
		cout << &a[i] << endl;
	}
	cout << "*************" << endl;
	for(int i = 0; i < 3; i++)        //打印所有元素的地址
		for (int j = 0; j < 4; j++)
		{
			cout << &a[i][j] << endl;   //会发现二维数组在内存中是依次连续存储的
		}

	Sum(a[0], 3, 4);      //数组带入函数进行计算



	system("pause");
	return 0;
}

void Sum(int *p, int hang, int lie)
{
	for (int i = 1; i < lie; i++)
	{
		for (int j = 0; j < hang; j++)
		{
			*(p + lie * j) += *(p + lie * j + i);
		}
		//*p += *(p + i);
		//*(p + hang*1) += *(p + hang*1 + i);
		//*(p + hang*2) += *(p + hang*2 + i);
	}
	for (int j = 0; j < hang; j++)
	{
		cout << *(p+ lie*j) << endl;
	}
	//cout << *p << endl;
	//cout << *(p+4) << endl;
	//cout << *(p+8) << endl;
}

//二维数组传递的三种方式
void func1(int arr[][4], int hang)   //1、传递数组，但要声明第二维的大小
{

}

void func2(int(*arr)[4])             //2、传递数组指针，仍需声明第二维的大小
{

}
void func3(int *arr)                 //3、传递指针，指针指向首元素，但传参数时需要强制类型转换
{

}