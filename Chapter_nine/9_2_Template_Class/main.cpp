//***********��ģ��****************
//ʹ�÷����뺯��ģ����ͬ��ֻ�������Ա������Ҫ��������ж���ʱ�����template<class T>������

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Student
{
	int id;
	float gpa;
};

template <class T>            //������ģ��
class Store
{
public:
	Store();
	T& getElem();              //��ȡ���ݺ���
	void putElem(const T& x);  //�������ݺ���

private:
	T item;
	bool haveValue;

};
template <class T>       //���еĳ�Ա������Ҫ��������ж���ʱ���������ģ�������
Store<T>::Store()        //��Ա������������ж���ʱ�����������˱仯����Ҫ����<T>
	:haveValue(false)
{}

template <class T>
T& Store<T>::getElem()
{
	if (!haveValue)
	{
		cout << "No item present!" << endl;
		exit(1);
	}
	return item;             //��������˵������ֵ�����Ա���ֵ��
}

template <class T>
void Store<T>::putElem(const T& x)
{
	haveValue = true;
	item = x;
}



int main()
{
	Store<int> s1, s2;
	s1.putElem(3);
	s2.putElem(-7);
	s2.getElem() = 10;     //��ΪgetElemΪ���ã����Կ��Ա���ֵ
	cout << s1.getElem() << "  " << s2.getElem() << endl;

	Student g = { 1000,23 };
	Store<Student> s3;
	s3.putElem(g);
	cout << "The student id is " << s3.getElem().id << endl;

	system("pause");
	return 0;
}