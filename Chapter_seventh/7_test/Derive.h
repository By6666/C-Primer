//�̳еķ�ʽ��1�����м̳У�2��˽�м̳У�3�������̳�

//���м̳У������public��protect���������еķ������Բ��䣬private����ֱ�ӷ���
//          ������ĳ�Ա����������ֱ�ӷ��ʻ����е�public��protect�������ܷ���private
//          ������Ķ���    ֻ�ܷ��ʻ����public��Ա����ȻҲ�����������Լ���public��

//˽�м̳У������public��protect���������еķ������Ա�Ϊprivate��private����ֱ�ӷ���
//          ������ĳ�Ա����������ֱ�ӷ��ʻ����е�public��protect�������ܷ���private
//          ������Ķ���    ���ܷ��ʻ�����κγ�Ա

//�����̳У������public��protect���������еķ������Ա�Ϊprotect��private����ֱ�ӷ���
//          ������ĳ�Ա����������ֱ�ӷ��ʻ����е�public��protect�������ܷ���private
//          ������Ķ���    ���ܷ��ʻ�����κγ�Ա


#ifndef _DERIVE_
#define _DERIVE_
#include "line.h"

class Derive:public Point
{
public:
	Derive() { cout << "Calling a Derive class" << endl; };
	Derive(int a, int b, int w, int h)
		:Point(a,b),w(w),h(h),p(a,b)
	{}
	Derive(const Derive&d);
	
	void asda() { w=Point::getX(); }

private:
	int w, h;
	Point p;
};

Derive::Derive(const Derive&d)                   //������ĸ��ƹ��캯��������ʱֻ��Ҫ��������Ķ���ֱ�Ӵ�������Ϳ�����
	:Point(d),p(d.p),w(d.w),h(d.h)               //��Ϊ�ڲ���һ������ת����������Ķ����������ת��Ϊ�������
{}                                               //�Լ�д�˸��ƹ��캯���Ͳ���������Ĭ�Ϲ��캯�������Լ�д�ĸ��ƹ��캯���У�û��д�ĳ�Ա�Ͱ���Ĭ�ϵķ�ʽ���г�ʼ��



#endif // !_DERIVE_

