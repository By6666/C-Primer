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
		cout << "请输入盘子的个数：\n";
		cin >> n;
		start = clock();
		hanoi(n, 'A', 'B', 'C');
		end = clock();
		cout << "总共执行了" << cnt << "步\n";     //步数等于2的n次方-1
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
		hanoi(n - 1, src, dest, medium);   //第一步：将n-1个盘子移动到medium
		move(src, dest);                   //第二部：将第n个盘子移动到dest上
		hanoi(n - 1, medium, src, dest);   //第三部：将n-1个盘子移动到dest上
	}
}