#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "line.h"
using namespace std;

void (*func1)(int, int);           //����ָ��

void func3(int a, int b);
int main()
{  
	vector<int> gfd(10);
	vector<int> tyu(gfd.begin(), gfd.end() - 1);   //ʹ��gfd����ʼ��tyu
	cout << gfd.size() << endl;                     //���10


	Point* asd;
	

	vector<int*>abc(5);
	vector<int>bcd(5);
	abc[0] = &bcd[0];

	////��̬�����ά����
	//int hang, lie;
	//cin >> hang >> lie;
	//int **abc;
	//abc = new int*[hang];
	//for (int i = 0; i < hang; i++)
	//{
	//	abc[i] = new int[lie];
	//}

	//ArrayofPoint points(2);     //��̬�����ഴ������
	//points.element(0).getX();
	char str[] = "program";
	cout << str << endl;
	string a ( "aaaaaaa");
	cout << a << endl;
	a = a + str;
	vector<int>arr(5);            //ʹ��vector�ഴ���������͵����飬�м�arr������������׵�ַ,�ڲ���ʼֵ��Ϊ0
	cout << arr[4] << endl;
	//auto p = arr.begin();
	//cout << *arr.begin()<< endl;
	for(auto &i:arr)
		cout << i << "  ";
	cout << endl; 
	//int a[3][4] = {0};           //���ڷ�Χforѭ��������ά����
	//for (auto &row : a)
	//{
	//	for (int i : row)
	//	{
	//		cout << i << "  " << endl;
	//	}
	//}


	//vector<Point>prr(5);
	//prr[1].getX();

	//int* ptr;                //��̬�ڴ����
	//ptr = new int();
	//*ptr = 10;
	//delete ptr; 
	//ptr = new int[10]{0};      //һά����
	//ptr[1] = 10;
	//delete[] ptr;

	//Point* ptrc;            //������
	//ptrc = new Point;
	//ptrc->getX();
	//delete ptrc;

	//ptrc = new Point[2]{Point(1,1),Point(4,5)};    //������
	//ptrc[0].getX();
	//delete[] ptrc;

	//int(*ptre)[5];         //��ά����
	//ptre = new int[3][5];

	//Point pc[2];                     //��������ĳ�ʼ��
	//pc[1] = Point(1, 1);      
	//Point pc2[2] = { Point(1,1),Point(2,2) };

	//int a[10], b[10];              //ָ������
	//int *p[2] = { a,b };
	//cout << sizeof(p) << endl;
	//cout << p << endl;
	//cout << &p[0] << endl;
	//cout << p[0] << endl;
	//cout << a << endl;
	//cout << p[1] << endl;
	//
	//cout << sizeof(&a[0]) << endl;
	//cout << &a[0] << endl;
	//func1 = func3;
	//func1(5, 4);
	//cout << sizeof(func1) << endl;


	system("pause");
	return 0;
}


void func3(int a, int b)
{

}