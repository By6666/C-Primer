#include "Derived.h"

void fun(Base1* ptr)      //�����������һ���ӿڣ�ͨ������ӿڿ��Խ��ϲ�ͬ����Ķ���Ȼ��ʵ����Ӧ�Ĺ��ܣ��Ƕ�̬�Ե�����
{
	ptr->display();
}

void Base1::display() const
{ 
	cout << "Base1::display()" << endl; 
}
void fun(const Base1& ptr)      //�����������һ���ӿڣ�ͨ������ӿڿ��Խ��ϲ�ͬ����Ķ���Ȼ��ʵ����Ӧ�Ĺ��ܣ��Ƕ�̬�Ե�����
{
	ptr.display();
}
