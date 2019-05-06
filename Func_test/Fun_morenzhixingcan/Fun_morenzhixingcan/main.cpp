#include <iostream>
#include <iomanip>       //目前只用到了setw、setfill等函数
#include <cmath>         //三角函数库，但带入的参数必须得是弧度值
using namespace std;
void getVolume(int length, int width=2, int height=2);//带默认形参值的函数，只能声明一次，且有默认值的形参右边必须是默认形参
 
int sum_of_square(int a, int b);                      //重载函数，可以通过形参的个数不同或者类型不同来定义多个重名函数
double sum_of_square(double a, double b);
float sum_of_square(float a, float b);

int main()
{
	int x(10), y(10), z(10);
//	getVolume(x,y);           //调用的时候可以只输入一个参数
//	pow()  求X的y次方函数
	int sum(0),value(0);
	while (cin>>value)     //cin是有返回值的即流的状态，当输入符合类型时为成功状态：1；当输入类型不符合时为失败状态：0；Windous系统下输入Ctrl+Z字符表示文件的结束符
	{
		sum += value;
	}
	cout << "SUM is :" << sum << endl;



	

	system("pause");

}

void getVolume(int length, int width, int height)  //在文件开始声明过后，就不能再次声明带有默认值形参的函数
{
	cout << setw(5)<<setfill('9')<<length << "  " << width << "  " << height << "\n";
	
}


int sum_of_square(int a, int b)
{
	return a*a + b*b;
}

double sum_of_square(double a, double b)
{
	return a*a + b*b;
}
float sum_of_square(float a, float b)
{
	return a*a + b*b;
}