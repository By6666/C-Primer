#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <list>
//#include <typeinfo.h>
#include <vcruntime_typeinfo.h>
using namespace std;
void swap(int &a, int &b);

int main()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << " -> " << (char)i << endl;
	}
	cout<<endl;

	char buff[20];
	int x = 0, y = 0;
	int &i = x;
	int* j;
	j = &y;

	*j = 2;


	sprintf_s(buff, "afpiamnf");
	printf(buff);
	cout << sizeof(i) << endl;
	cout << sizeof(j) << endl;
	//while (1)
	//{
	//	cout << "请输入两个数，系统将进行交换\n";
	//	cin >> x >> y;

	//	swap(x, y);
	//	cout << "x=" << x << "   y=" << y << endl;
	//}
	/*string str = "sdadasdf";
	reverse(str.begin(), str.end());
	cout << str << endl;*/


	vector<int> a(5, 2);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	vector<int> b(3, 6);
	a.insert(a.end(), b.begin(),b.end());
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;

	cout << typeid(x).name() << endl;
	if (typeid(x)== typeid(int)) cout << "true";
	else cout << "false";

	cout << endl;

	int* h = new int[10]{0};
	for (int i = 0; i < 10; i++)
	{
		cout << h[i] << "  ";
	}
	cout << endl;

	map<int, int> test_map;
	int mp_data[] = { 0,1,2,3,4,0 };
	for (int i = 0; i < 6; i++)
	{
		test_map[mp_data[i]] = i;
	}
	cout << test_map[0] << endl;
	while (1)
	{
		int key;
		cout << "input key: ";
		cin >> key;

		cout << test_map.count(key) << endl;


	}
	system("pause");
	return 0;
}

void swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;

}