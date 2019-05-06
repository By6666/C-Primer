//***********类模板****************
//使用方法与函数模板相同，只是在类成员函数需要在类外进行定义时需加上template<class T>的声明

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

template <class T>            //定义类模板
class Store
{
public:
	Store();
	T& getElem();              //提取数据函数
	void putElem(const T& x);  //存入数据函数

private:
	T item;
	bool haveValue;

};
template <class T>       //类中的成员函数需要在类外进行定义时必须加上类模板的声明
Store<T>::Store()        //成员函数在类外进行定义时，类名发生了变化，需要加上<T>
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
	return item;             //返回引用说明是左值（可以被赋值）
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
	s2.getElem() = 10;     //因为getElem为引用，所以可以被赋值
	cout << s1.getElem() << "  " << s2.getElem() << endl;

	Student g = { 1000,23 };
	Store<Student> s3;
	s3.putElem(g);
	cout << "The student id is " << s3.getElem().id << endl;

	system("pause");
	return 0;
}