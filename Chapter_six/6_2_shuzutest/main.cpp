//本测试要明白cin与cin.get的区别之处

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define Noself 1
const char Key[] = { 'a','b','c','d','a' };
const int NUM_QUES = 5;

int main()
{
	char c;
	int ques = 0, Correct_N = 0;
	cout << "Enter the " << NUM_QUES << " question tests." << endl;

#if Noself
	while (cin.get(c))                             //cin不能读取空格和换行符（'\n'）,所以使用cin.get()
	{
		if (c != '\n')
		{
			if (c == Key[ques])
			{
				Correct_N++;
				cout << " ";
			}
			else cout << "*";
			ques++;
		}
		else
		{
			cout << "Score" << static_cast<float>(Correct_N) / NUM_QUES * 100 << "%";
			ques = 0; Correct_N = 0; cout << endl;
		}
	}

#else

		while (cin>>c)                             //cin不能读取空格和换行符（'\n'）,所以使用cin.get(),当输入Ctrl+Z时返回错误状态
		{
			if (ques < 5)
			{
				if (c == Key[ques])
				{
					Correct_N++;
					cout << " ";
				}
				else cout << "*";
				ques++;
			}
			if (ques == 5)
			{
				cout << "Score" << static_cast<float>(Correct_N) / NUM_QUES * 100 << "%";
				ques = 0; Correct_N = 0; cout << endl;
			}
		}

#endif 



	system("pause");
	return 0;
}