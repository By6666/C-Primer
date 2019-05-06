#include <iostream>

using namespace std;
int main()
{
	enum MyEnum {MON,TUE,WED,THU,FRI};
	cout << "The char size is "  << sizeof(char)  << " bytes\n";
	cout << "The short size is " << sizeof(short) << " bytes\n";
	cout << "The int size is "   << sizeof(int)   << " bytes\n";
	cout << "The long size is "  << sizeof(long)  << " bytes\n";
	cout << "The float size is " << sizeof(float) << " bytes\n";
	cout << "The double size is "<< sizeof(double)<< " bytes\n";


//	int a(0), b(0), c(0);

//	cout << "Please enter a value of a \n";
//	cin >> a >> b;
//	cout << "Please enter a value of b \n";
//	cin >> b;
//	c = (a - b) > 0 ? (a - b) : (b - a);
//	cout << "The different of a and b is " << c << "\n"; 

	cout << MyEnum(1) << "\n";

	system("pause");
	return 0;
}