#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int i=10;
	const int* ptr = &i;     //constָ�룬���ܸı���ָ�����ֵ�����ǿ��Ըı�ָ�뱾������ָ������һ������
	                         //�൱��һ��ֻ����ָ��
	int j;
	ptr = &j;               //constָ�뱾���ǿ��Ըı��
//	*ptr = 50;              //����ָ��������޸�

//��ȻҲ���Զ��峣��ָ��,����ָ�뱾����Ϊ�������ܸı�
	int* const ptr2 = &j;       //������ָ������޸ĸõ�ַ�µĶ��󣬲������ǿɶ���Ҳ����д
	*ptr2 = 10;               //��ȷ
//	ptr2 = &i;                //����ָ�뱾�������޸�



	system("pause");
	return 0;
}