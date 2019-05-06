#include <iostream>
#include "clock.h"

using namespace std;

int main()
{
	//Clock d;
	//d.showTime();

	//Clock daliy_T(); 这样的定义编译器会认为是声明了一个返回类型为Clock的daliy_T函数，错误C2228


	Clock daliy_T(0, 0, 0, 0, 0, 0);

	 while (1)
	 {
		 daliy_T.setTime();
		 daliy_T.showTime();
	 }

	system("pause");
	return 0;
}


