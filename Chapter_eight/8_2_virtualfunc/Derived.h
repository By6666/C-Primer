//���˹��캯���;�̬��Ա�����������麯���⣬��������Ҳ�������麯��


//*************���麯��***************
//ӵ�д��麯�������Ϊ�����࣬�������಻�ܽ���ʵ�廯��Ҳ����˵���ܶ������Ķ��󣬾�ֻ������������
//��Ϊ���麯���Ǻܶ�������Ļ��࣬����������ͳһ�˺����Ľӿڣ�Ҳ����˵���Ҿ�һ���ӿڣ����ǽ��ϲ�ͬ���͵Ķ����Ժ���ʵ����ö�����ƥ��Ĺ���

#ifndef _DERIVED_
#define _DERIVED_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;


class Base1 
{
public:
	virtual void display() const ;
//	virtual void display() const = 0;     //���麯��
	virtual~Base1() { cout << "destroy a base1!!" << endl; }

};

class Base2:public Base1
{
public:
	void display() const override { cout << "Base2::display()" << endl; }  //override���ñ����������Ǽ���麯���������Ƿ���ȷ
};

class Derived :public Base2
{
public:
	void display()const { cout << "Derived::display()" << endl; }
	virtual ~Derived() { cout << "destroy a Derives!!" << endl; }
};

void fun(Base1* ptr);
void fun(const Base1& ptr);      //�����������һ���ӿڣ�ͨ������ӿڿ��Խ��ϲ�ͬ����Ķ���Ȼ��ʵ����Ӧ�Ĺ��ܣ��Ƕ�̬�Ե�����

#endif // !_DERIVED_

