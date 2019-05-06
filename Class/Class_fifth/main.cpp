#include "computer.h"


int main()
{
	CPU a(P4,25,3.3);
	a.CPU_run();
	a.CPU_stop();
	cout << "***********************" << endl;
	
	RAM b(DDR2,0,0);
	b.RAM_run();
	b.RAM_stop();
	cout << "***********************" << endl;

	CD_RAM c(SATA, 20, external);
	c.CDROM_run();
	c.CDROM_stop();
	cout << "***********************" << endl;

	Computer d(a, b, c, 25, 8);
	d.Run();
	d.Stop();



	return 0;
}

