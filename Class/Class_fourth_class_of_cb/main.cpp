#include "line.h"

int main()
{
	Point a[2] = { Point(1,1),Point(4,5) };    //��������
	int(*p1)[3];
	Point* p2;
	cout << sizeof(*p1) << "  " << sizeof(p2) << endl;//˵��ָ������Ĵ�С�㶨���Ҹ�����ϵͳ��λ���йأ�64λϵͳ��Ϊ8Byte
	//Point *ptr;                                //����ָ��
	//ptr = new Point;                           //��̬�ڴ���䣬new��������ص����������ڴ���׵�ַ
	//delete ptr;                                //delete��������ɾ��ָ����ָ������ڴ�ռ䣬���Ὣָ���������ɾ��
	//ptr = new Point(1, 1);                     //�ڶ����ڴ����뷽ʽ��ֱ�Ӹ�ֵ
	//delete ptr;

	Point myp1(1,1), myp2(4,5);
	myp1 = myp2;
	//const Point  a(0,0);                      //�����󣬲��ܱ��޸ģ�����ʱ�����ʼ��
	//a.setx(1);                             //����д�ͻᱨ��
	//a.getY();                              //����д�ᱨ����Ϊ������ֻ�ܵ������ĳ���Ա����
	Point::ShowCnt();
	Line ultimate(myp1, myp2);               //��������˳���������
	//Line ul_2(ultimate);

	//cout << "Distence of two point is " << ul_2.getDis() << endl;
	cout << "Distence of two point is " << dist(myp1,myp2) << endl;
//	cout << "Distence of two point is " << dist(a[0], a[1]) << endl;

	myp1.ShowCnt();
	myp2.ShowCnt();

	system("pause");
	return 0;
}

