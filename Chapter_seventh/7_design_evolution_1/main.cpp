#include "SavingAccount.h"
#include "Date.h"
#include "Accumulator.h"

int main()
{
	Date sdate(2012, 1, 1);

	SavingAccount savingaccounts[] = { SavingAccount(sdate, "Mls_ssb", 0.015),SavingAccount(sdate,"Mls_dsb",0.015) };
	CreditAccount creditaccounts[] = { CreditAccount(sdate,"Mls_sgb",10000,0.09,100),CreditAccount(sdate,"Mls_dgb",10000,0.09,100) };

	creditaccounts[0].deposit(Date(2012, 2, 1), 1200, "salary");
//	creditaccounts[0].withdraw(Date(2012, 5, 1), 5000, "shoping");

	creditaccounts[0].settle(Date(2013, 1, 1));
	creditaccounts[0].Show();
	

	cout << creditaccounts[0].GetFee() << "   "
		<< creditaccounts[0].GetAvaliableCredie() << "   "
		<< creditaccounts[0].Getbalance() << "   "
		<< creditaccounts[0].GetCredit() << "   "
		<< creditaccounts[0].GetDebt() << "   "
		<< creditaccounts[0].Getid() << "   "
		<< creditaccounts[0].GetRate() << "   " << endl;




	system("pause");
	return 0;
}