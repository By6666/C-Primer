#include <iostream>
#include <iomanip>

using namespace std;


class MyClass
{
public:
	MyClass(int HOUR, int MINUTE, int SECOND)        //��Ϊί�й��캯���ı��壬ֻ���޸�����������һ�����޸�������ί�еĹ��캯��
		:hour(HOUR), minute(MINUTE), second(SECOND)
	{}
	////MyClass()                      //���ú����湹�캯����ͬ
	////	:hour(0),minute(0),second(0)
	////{}
	//MyClass()                        //������������������ͬ
	//	:MyClass(0,0,0)              //ί�й��캯����ʹ�õ�һ�����캯����ʼ���ڶ������캯��
	//{}
	void setTime(int HOUR = 0, int MINUTE = 0, int SECOND = 0);          //��Ĭ��ֵ���β�
	void showTime();


private:
	int hour, minute, second;

};

void MyClass::setTime(int HOUR, int MINUTE, int SECOND)
{
	hour = HOUR; minute = MINUTE; second = SECOND;

}
void MyClass::showTime()
{
	cout << hour << ":" << setw(2)<<setfill('0')<<minute << ":" << setw(2) << setfill('0') << second << endl;
}

MyClass func()
{
	return MyClass(14,10,55);
}

int main()
{
	//MyClass Tim;                     //��͵����������Ĺ��캯��
	//Tim.setTime(21, 0, 0);
	//Tim.showTime();
	func().showTime();

	system("pause");
	return 0;	

}