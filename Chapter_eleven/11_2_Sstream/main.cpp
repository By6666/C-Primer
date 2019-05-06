//使用stringstream进行数字与字符串之间的相互转换速度很慢，仅用于少量的数据转换
//使用sprintf和scanf函数进行转换速度快
//还可以使用内部函数atoi()、atof()、atol()、atoll()进行转换

//可以把ftream和stringstream类似与iostream，使用方法类似


#include <iostream>
#include <sstream>    //字符串输入输出流
#include <string>
#include <fstream>

using namespace std;

template <class T>
T fromString(const string& str)
{
	stringstream is;
	is << str;
	T buff;
	is >> buff;
	return buff;
}

int main()
{

	//cout << fromString<double>("3.12") << endl;
	//
	//stringstream os;
	//double a ,b;
	//os << 3.1215926<< " "<<3.12;

	fstream fs("C:\\Users\\By\\Desktop\\234.txt");
	cout << fs.is_open() << endl;
	fs.seekg(0);
	string a;
	getline(fs, a);
	fs.close();
	cout << a << endl;







	system("pause");
	return 0;
}
