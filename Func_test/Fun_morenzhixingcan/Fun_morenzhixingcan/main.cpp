#include <iostream>
#include <iomanip>       //Ŀǰֻ�õ���setw��setfill�Ⱥ���
#include <cmath>         //���Ǻ����⣬������Ĳ���������ǻ���ֵ
using namespace std;
void getVolume(int length, int width=2, int height=2);//��Ĭ���β�ֵ�ĺ�����ֻ������һ�Σ�����Ĭ��ֵ���β��ұ߱�����Ĭ���β�
 
int sum_of_square(int a, int b);                      //���غ���������ͨ���βεĸ�����ͬ�������Ͳ�ͬ����������������
double sum_of_square(double a, double b);
float sum_of_square(float a, float b);

int main()
{
	int x(10), y(10), z(10);
//	getVolume(x,y);           //���õ�ʱ�����ֻ����һ������
//	pow()  ��X��y�η�����
	int sum(0),value(0);
	while (cin>>value)     //cin���з���ֵ�ļ�����״̬���������������ʱΪ�ɹ�״̬��1�����������Ͳ�����ʱΪʧ��״̬��0��Windousϵͳ������Ctrl+Z�ַ���ʾ�ļ��Ľ�����
	{
		sum += value;
	}
	cout << "SUM is :" << sum << endl;



	

	system("pause");

}

void getVolume(int length, int width, int height)  //���ļ���ʼ�������󣬾Ͳ����ٴ���������Ĭ��ֵ�βεĺ���
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