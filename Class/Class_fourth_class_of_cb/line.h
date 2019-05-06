//�������ϰ,��ľ�̬��ԱӦ�ã���Ԫ��������Ԫ���Ӧ��


//*******��Ԫ��������Ԫ��*****
//Ŀ�ģ���ͨ�����еĳ�Ա����ȥ��ȡ���е�˽�����ݳ�Ա������ֱ�ӻ�ȡ���е�˽�����ݳ�Ա���������Լ��ٺ������õĿ���
//C++����Ԫ��ϵ�ǵ���ģ�������B��A����Ԫ!=A��B����Ԫ

#ifndef _LINE_           
#define _LINE_
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define Fri 1    //�Ƿ���Ԫ
#define Ref 1    //�Ƿ�����

class Point
{
#if Fri
	friend class Line;
#endif 

public: 
	Point(int a, int b);            //���캯��
	Point() = default;             //Ĭ�Ϲ��캯��
	Point(const Point &p);         //���ƹ��캯��
	~Point() { cnt--; }
	int getX() const { return x; }       //��Ա����
	int getY()  { return y; }
	void setx(int a) { x = a; }
	static void ShowCnt(){ cout << "Object Cnt = " << cnt << endl; }   //��̬������Ա�����ڴ���̬���ݳ�Ա

	friend float dist(const Point &a, const Point &b);       //����dist����ΪPoint�����Ԫ����,�����Ǹ���ĳ�Ա����
	                                             //�������������������ʹ�����е�˽�г�Ա
private:
	int x, y;
	static int cnt;                 //��̬���ݳ�Ա���������ڼ�¼��ĸ�����
	                                //����������������еģ�����ĳ�����������
};
int Point::cnt = 0;                 //��̬���ݳ�Ա���������ⶨ��ͳ�ʼ��

Point::Point(int a, int b)                     //���캯��ʵ��
	:x(a),y(b)
{
	cnt++;
	cout << "constructor Point: " << x << "," << y << endl;
}
Point::Point(const Point &p)                   //���ƹ��캯��ʵ��
{
	x = p.x;
	y = p.y;
	cnt++;
	cout << "constructor Point copy succeed!!" << endl;
}
float dist(const Point &a, const Point &b)                 //��Ԫ����ʵ�֣��ڸú�������Է���˽�г�Ա
{
	double x, y;
	x = a.x - b.x;
	y = a.y - b.y;
	return (float)(sqrt)(x*x + y*y);
}

//���������
class Line                                //���еĳ�Ա����һ����Ķ���
{
public:
#if Ref
	Line(Point &pstarst, Point &pend);     //���Դ�����
#else
	Line(Point pstarst, Point pend);       //constructor function
#endif // Ref

	Line(const Line &L);                   //copy constructor function
	float getDis();

private:
	Point  Lstart,Lend;                   //˽�г�Ա�Ǳ����Ķ�������˳������˹��캯����ʼ����˳��

};

#if Ref
Line::Line(Point &pstarst, Point &pend)      //���캯��ʵ�֣��������ǲ����б�ð�ź����ǳ�ʼ���б������������Ǻ���ʵ��
	:Lstart(pstarst), Lend(pend)             //��ʼ����˳�����ʼ���б��˳���޹أ���Line���е�˽�г�Ա����������˳���й�
{
	cout << "constructor Line" << endl;      //Line�Ĺ��캯���������ϵͳ�Զ�����pstarst��pend
}
#else
Line::Line(Point pstarst, Point pend)     //���캯��ʵ�֣��������ǲ����б�ð�ź����ǳ�ʼ���б������������Ǻ���ʵ��
	: Lstart(pstarst), Lend(pend)             //��ʼ����˳�����ʼ���б��˳���޹أ���Line���е�˽�г�Ա����������˳���й�
{
	cout << "constructor Line" << endl;      //Line�Ĺ��캯���������ϵͳ�Զ�����pstarst��pend
}
#endif // Ref



Line::Line(const Line &L)                 //���ƹ��캯��
	:Lstart(L.Lstart),Lend(L.Lend)
{
	cout << "constructor Line copy succeed!!" << endl;
}
float Line::getDis()                     //��Line��ĳ�Ա����ʵ��
{
	double x, y;

#if !Fri
	x = Lend.getX() - Lstart.getX();
	y = Lend.getY() - Lstart.getY();
#else
	//�����������ͬ���������䣬ԭ���ǽ�Line��ΪPoint����Ԫ������
	//����Line�е�Point�����Ϳ���ֱ�ӵ���Point���е�˽�����ݳ�Ա
	x = Lend.x - Lstart.x;
	y = Lend.y - Lstart.y;
#endif // !Fri

	return (float)(sqrt)(x*x + y*y);
}



#endif // !_LINE_
