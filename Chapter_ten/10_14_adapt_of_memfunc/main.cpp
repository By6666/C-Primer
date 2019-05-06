//函数适配器--成员函数适配器mem_fun、men_fun_ref
//将类的成员函数适配为函数对象，前者适配为指针，后者适配为引用

#include <iostream>
#include <functional>     //函数对象头文件，包含函数对象和函数适配器
#include <vector>         //vector容器中含有相应的iterator
#include <algorithm>      //算法头文件，包含find_if等算法

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