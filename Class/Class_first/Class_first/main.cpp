#include <iostream>
#include "clock.h"

using namespace std;

int main()
{
	//Clock d;
	//d.showTime();

	//Clock daliy_T(); �����Ķ������������Ϊ��������һ����������ΪClock��daliy_T����������C2228


	Clock daliy_T(0, 0, 0, 0, 0, 0);

	 while (1)
	 {
		 daliy_T.setTime();
		 daliy_T.showTime();
	 }

	system("pause");
	return 0;
}


