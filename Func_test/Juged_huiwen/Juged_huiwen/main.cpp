#include <iostream>
using namespace std;
bool judge_huiwen(unsigned x);

int main()                                       //��11~999֮�䣬n��n*n��n*n*n��Ϊ���ĵ���
{
	unsigned n(0);
	cout << "�������������У�\n";
	for (int i = 11; i < 1000; i++)
	{
		if (judge_huiwen(i) && judge_huiwen(i*i) && judge_huiwen(i*i*i))
		{
			cout << i << " ";
		}
			
	}
	cout << endl;
		

	system("pause");
	return 0;
}


bool judge_huiwen(unsigned x)          //�ж��Ƿ�Ϊ���ģ��������ݽ��з�ת��ԭ���ݽ��бȽϿ��Ƿ����
{
	unsigned v(x),     //��Ž���X��ֵ��������ԭ����
		     m(0);     //��Ż���

	while (x>0)
	{
		m = m * 10 + x % 10;
		x /= 10;
	}

	return m == v;                    //ֱ�ӷ���bool����
}