//����ָ���ʹ�ã�ð������
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

void sort(int* arr, int size, bool(*cmp)(int, int));
bool up(int a, int b);
bool down(int a, int b);


int main()
{
	int Numb,            //����Ҫ�������ݵĸ���
		up_or_down;      //�����ǽ���  up��1��down��0
	int* a;              //����һ��ָ�����            
	cout << "��������Ҫ��������ݸ�����" << endl;
	cin >> Numb;
	cout << "��ȷ�������ǽ���  up��1��down��0" << endl;
	cin >> up_or_down;
	cout << "������Ҫ�����"<< Numb<<"�����ݣ�" << endl;
	a = new int[Numb];   //��̬����numb��int�Ϳռ䣬�������׵�ַ��a
	for (int i = 0; i < Numb; i++) //��ӡ��̬������ڴ��ַ
	{
		cout << a + i << "  ";
	}
	cout << endl;
	for (int i = 0; i < Numb; i++)
	{
		cin >> *(a + i);
	}
	if(up_or_down)  sort(a, Numb, up);
	else            sort(a, Numb, down);

	cout << "�������Ϊ��" << endl;
	for (int i = 0; i < Numb; i++)
	{
		cout << *(a + i) << "  ";
	}
	cout << endl;


	system("pause");
	delete[] a;
	return 0;
}

void sort(int* arr, int size, bool(*cmp)(int, int))
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (!cmp(arr[i], arr[j]))
			{
				int temp;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}


bool up(int a, int b)
{
	if (a <= b)  return 1;
	else return 0;
}
bool down(int a, int b)
{
	if (a >= b) return 1;
	else return 0;
}