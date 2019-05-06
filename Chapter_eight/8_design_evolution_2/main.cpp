#include "SavingAccount.h"
#include "Date.h"
#include "Accumulator.h"

int main()
{
	Date sdate(2008, 11, 1);

	SavingAccount savingaccounts[] = { SavingAccount(sdate, "Mls_ssb", 0.015),SavingAccount(sdate,"Mls_dsb",0.015) };
	CreditAccount creditaccounts[] = { CreditAccount(sdate,"Mls_sgb",10000,0.0005,100),CreditAccount(sdate,"Mls_dgb",10000,0.0005,100) };

	Account*accounts[] = { savingaccounts ,savingaccounts + 1, creditaccounts ,creditaccounts + 1 };
	const int n = sizeof(accounts) / sizeof(Account*);
	cout << "账户总数为： " << n << endl;

	cout << "(d)deposit,(w)withdraw,(s)show,(c)change_day,(n)next_month,(e)exit" << endl;
	char cmd;
	do{
		sdate.Show();
		cout << "\tTotal:" << Account::GetTotal() << endl;
		cout << "please input cmd> ";
		cin >> cmd;

		int index,  //第几个账户
			day;
		double amount;
		string desc;

		switch (cmd)
		{
		case 'd':  //存入现金
			cin >> index >> amount;
			getline(cin, desc);
			accounts[index]->deposit(sdate, amount, desc);
			break;

		case 'w':  //取出现金
			cin >> index >> amount;
			getline(cin, desc);
			accounts[index]->withdraw(sdate, amount, desc);
			break;

		case 's':  //查询各账户信息
			for (int i = 0; i < n; i++)
			{
				cout << "[ " << i << " ]  :";
				accounts[i]->Show();
			}
			break;

		case 'c':  //改变日期
			cin >> day;
			if (day < sdate.GetDay())
				cout << "You cannot specify a previous day" << endl;
			else if (day > sdate.GetMaxDay())
				cout << "Invail day" << endl;
			else
				sdate = Date(sdate.GetYear(), sdate.GetMonth(), day);
			break;

		case 'n':  //进入下个月
			if (sdate.GetMonth() == 12)
				sdate = Date(sdate.GetYear() + 1, 1, 1);
			else
				sdate = Date(sdate.GetYear(), sdate.GetMonth() + 1, 1);
			for (int i = 0; i < n; i++)
				accounts[i]->settle(sdate);
			break;

		default:
			break;
		}

	   } while (cmd!='e');
	
	//creditaccounts[0].deposit(Date(2012, 2, 1), 1200, "salary");
	//creditaccounts[0].withdraw(Date(2012, 5, 1), 5000, "shoping");

	//creditaccounts[0].settle(Date(2013, 1, 1));
	//creditaccounts[0].Show();

	//cout << creditaccounts[0].GetFee() << "   "
	//	<< creditaccounts[0].GetAvaliableCredie() << "   "
	//	<< creditaccounts[0].Getbalance() << "   "
	//	<< creditaccounts[0].GetCredit() << "   "
	//	<< creditaccounts[0].GetDebt() << "   "
	//	<< creditaccounts[0].Getid() << "   "
	//	<< creditaccounts[0].GetRate() << "   " << endl;




	system("pause");
	return 0;
}