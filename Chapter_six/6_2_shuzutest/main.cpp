//������Ҫ����cin��cin.get������֮��

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
	while (cin.get(c))                             //cin���ܶ�ȡ�ո�ͻ��з���'\n'��,����ʹ��cin.get()
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

		while (cin>>c)                             //cin���ܶ�ȡ�ո�ͻ��з���'\n'��,����ʹ��cin.get(),������Ctrl+Zʱ���ش���״̬
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