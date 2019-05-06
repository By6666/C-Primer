//����������--��Ա����������mem_fun��men_fun_ref
//����ĳ�Ա��������Ϊ��������ǰ������Ϊָ�룬��������Ϊ����

#include <iostream>
#include <functional>     //��������ͷ�ļ���������������ͺ���������
#include <vector>         //vector�����к�����Ӧ��iterator
#include <algorithm>      //�㷨ͷ�ļ�������find_if���㷨

using namespace std;


struct Car
{
	int id;
	Car(int id) { this->id = id; }
	void display() const { cout << "car" << id << endl; }
};

int main()
{
	vector<Car*> pcars;
	vector<Car> cars;

	for (int i = 0;i < 5;i++)  pcars.push_back(new Car(i));

	for (int i = 5; i < 10; i++) cars.push_back(Car(i));

	cout << "elements in pcars: " << endl;
	for_each(pcars.begin(), pcars.end(), mem_fun(&Car::display));
	cout << endl;

	for_each(cars.begin(), cars.end(), mem_fun_ref(&Car::display));
	cout << endl;


	for (size_t i = 0;i < pcars.size();++i)
	{
		delete pcars[i];
	}



	system("pause");
	return 0;
}