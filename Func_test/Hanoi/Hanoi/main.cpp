#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;
void move(char src, char dest);
void hanoi(int n, char src, char medium, char dest);

int cnt(0);

int main()
{
	int n(0);
	while (1)
	{
		clock_t start, end;
		cout << "���������ӵĸ�����\n";
		cin >> n;
		start = clock();
		hanoi(n, 'A', 'B', 'C');
		end = clock();
		cout << "�ܹ�ִ����" << cnt << "��\n";     //��������2��n�η�-1
		cout.setf(ios::fixed);
		cout << "Spend time: " << setprecision(10) << (float)(end - start) / CLOCKS_PER_SEC << endl;
		cnt = 0;
	}
	
//	system("pause");
	return 0;

}

void move(char src, char dest)
{
	//printf("%c --> %c ", src, dest);
	//cout << src << " --> " << dest;
	cnt++;
}
 
void hanoi(int n, char src, char medium, char dest)
{
	if (n == 1) move(src, dest);
	else
	{
		hanoi(n - 1, src, dest, medium);   //��һ������n-1�������ƶ���medium
		move(src, dest);                   //�ڶ���������n�������ƶ���dest��
		hanoi(n - 1, medium, src, dest);   //����������n-1�������ƶ���dest��
	}
}