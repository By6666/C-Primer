#include "People.h"

int main()
{
	Date a;
//	a.Setdate();

	People b("007",false,a,"410882199510250575");

	b.Showall();
	b.Setbirthday();
	b.Showall();

	People c(b);

	c.Showall();


	system("pause");
	return 0;
}