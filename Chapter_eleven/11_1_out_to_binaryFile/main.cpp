//二进制的写入是最快的，当不需要进行观察的时候，可以使用二进制方式进行读写文件
//注意读写时候的类型转换，必要时使用reinterpret_cast<类型名指针>（被转换指针）

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Date
{
	int mon, day, year;
};

int main()
{
	fstream myfile( "C:\\Users\\By\\Desktop\\234.txt",ios_base::out|ios_base::app);
	myfile << "By666" << endl;
	cout << myfile.good() << endl;
	myfile.close();

	myfile.open("C:\\Users\\By\\Desktop\\234.txt", ios_base::in);
	string i,j,k;
	myfile >> i>>j>>k;
	cout << i<<j<<k<<endl;
	//char* buff;
	//buff = new char[sizeof(Date)];
	//ifstream myfile( "C:\\Users\\By\\Desktop\\date.dat", ios_base::binary|ios_base::in);
	//myfile.read(buff, sizeof(Date));

	//myfile.close();

	//cout << reinterpret_cast<Date*>(buff)->year << endl;

	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	//ofstream myfile("C:\\Users\\By\\Desktop\\123.dat", ios_base::binary);
	//if (!myfile)
	//{
	//	cerr << "open error!" << endl;
	//	abort();
	//}
	//myfile.write((char*)a, sizeof(a));


	//ifstream myfile("C:\\Users\\By\\Desktop\\123.dat", ios_base::binary | ios_base::in);
	//int* buff;
	//buff = new int[sizeof(a)];
	//myfile.read((char*)buff, sizeof(a));
	//
	//myfile.close();

	//cout << sizeof(a) <<"     "<<buff[9] << endl;

	//delete[] buff;

	system("pause");
	return 0;
}