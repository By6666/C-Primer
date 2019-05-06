#include "SavingAccount.h"
#include "Date.h"
using namespace std;


int main()
{
	Date date(2008, 11, 1);
	SavingAccount accounts[] = { SavingAccount(date,"S37217",0.015),SavingAccount(date,"02342342",0.015) };
	const int n = sizeof(accounts) / sizeof(SavingAccount);
	accounts[0].deposit(Date(2008, 11, 5), 5000, "Salary");
	accounts[1].deposit(Date(2008, 11, 25), 10000, "Sell stock 0323");

	accounts[0].deposit(Date(2008, 12, 5), 5500, "Salary");
	accounts[1].withdraw(Date(2008, 12, 20), 4000, "Buy a laptop");

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		accounts[i].settle(Date(2009, 1, 1));
		accounts[i].Show();
	}
	cout << endl;
	cout << "Toal:" << SavingAccount::GetTotal() << endl;
	////SavingAccount *ptr;                     //对象指针的定义
	//SavingAccount sa0(1, 007, 0.015);
	//SavingAccount sa1(1, 118, 0.015);
	////ptr = &sa0;        //对象指针的赋值
	////(*ptr).deposit(5, 5000);                
	//////对象指针调用成员函数,以下两种方式
	////(*ptr).deposit(5, 5000);
	////ptr->deposit(5, 5000);

	//sa0.deposit(5, 5000);
	//sa1.deposit(25, 10000);
	//sa0.deposit(45, 5500);
	//sa1.withdraw(60, 4000);

	//sa0.settle(90);
	//sa1.settle(90);

	//sa0.Show(); cout << endl;
	//sa1.Show(); cout << endl;
	//
	//cout << "总存储金额为：" << SavingAccount::GetTotal() << endl;



	system("pause");
	return 0;
}


//测试Date类代码
//Date a(2018, 10, 1);
//a.Show();
//cout << a.IsLeapYear() << endl;
//Date b(2018, 9, 1);
//cout << a.distance(b) << endl;
