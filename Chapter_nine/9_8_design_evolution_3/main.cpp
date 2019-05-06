#include "SavingAccount.h"
#include "Date.h"
#include "Accumulator.h"
#include "Array.h"

int main()
{
	Date sdate(2008, 11, 1);

	Array<Account*>accounts(0);
	//SavingAccount savingaccounts[] = { SavingAccount(sdate, "Mls_ssb", 0.015),SavingAccount(sdate,"Mls_dsb",0.015) };
	//CreditAccount creditaccounts[] = { CreditAccount(sdate,"Mls_sgb",10000,0.0005,100),CreditAccount(sdate,"Mls_dgb",10000,0.0005,100) };

	//Account*accounts[] = { savingaccounts ,savingaccounts + 1, creditaccounts ,creditaccounts + 1 };
	//const int n = sizeof(accounts) / sizeof(Account*);
	//cout << "�˻�����Ϊ�� " << n << endl;

	cout << "(a)add(s,c),(d)deposit,(w)withdraw,(s)show,(c)change_day,(n)next_month,(e)exit" << endl;
	char cmd;
	do{
		sdate.Show();
		cout << "\tTotal:" << Account::GetTotal() << endl;
		cout << "please input cmd> ";
		cin >> cmd;

		int index,  //�ڼ����˻�
			day;
		double amount, rate, credit, fee;
		string desc,id;
		char type;
		Account* account;
		switch (cmd)
		{
		case 'a':  //����˻�
			cin >> type >> id;
			if (type == 's')
			{
				cin >> rate;
				account = new SavingAccount(sdate, id, rate);
			}
			else 
			{
				cin >> credit >> rate >> fee;
				account = new CreditAccount(sdate, id, credit, rate, fee);
			}
			accounts.Resize(accounts.GetSize() + 1);
			accounts[accounts.GetSize() - 1] = account;
			break;
		case 'd':  //�����ֽ�
			cin >> index >> amount;
			getline(cin, desc);
			accounts[index]->deposit(sdate, amount, desc);
			break;

		case 'w':  //ȡ���ֽ�
			cin >> index >> amount;
			getline(cin, desc);
			accounts[index]->withdraw(sdate, amount, desc);
			break;

		case 's':  //��ѯ���˻���Ϣ
			for (int i = 0; i < accounts.GetSize(); i++)
			{
				cout << "[ " << i << " ]  :";
				accounts[i]->Show();
			}
			break;

		case 'c':  //�ı�����
			cin >> day;
			if (day < sdate.GetDay())
				cout << "You cannot specify a previous day" << endl;
			else if (day > sdate.GetMaxDay())
				cout << "Invail day" << endl;
			else
				sdate = Date(sdate.GetYear(), sdate.GetMonth(), day);
			break;

		case 'n':  //�����¸���
			if (sdate.GetMonth() == 12)
				sdate = Date(sdate.GetYear() + 1, 1, 1);
			else
				sdate = Date(sdate.GetYear(), sdate.GetMonth() + 1, 1);
			for (int i = 0; i < accounts.GetSize(); i++)
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

	   for (int i = 0; i < accounts.GetSize(); i++)
	   {
		   delete accounts[i];
	   }

	return 0;
}