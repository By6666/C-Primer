#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//���ڶ�ά����a[3][4]��˵����a��a[0]��ֵ��ͬ,��ָ������Ͳ�ͬ��aΪһά�������͵�ָ�룬a[0]Ϊ�������͵�ָ��

void Sum(int *p, int hang, int lie);


int main()
{
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int(*ptr)[4] = a;                         //����ָ�룬Ҳ����ָ�룬���ά������ͬ

	for (auto &elem : a)
	{
		for(int elem2:elem)
		cout << elem2<<"   ";
	}
	cout << endl;
	//���ά������к���
	//int len1, len2, len3;    
	//cout << sizeof(a) << "  " << sizeof(a[0]) << "  " << sizeof(a[0][0]) << endl;
	//len1 = sizeof(a) / sizeof(int);
	//len2 = sizeof(a[0]) / sizeof(int);    //����
	//len3 = len1 / len2;                   //����
	//cout << len1 << "  " << len2 << "  " << len3 << endl;

	cout << ptr << endl;
	cout << *ptr << endl;
	cout << ptr+1 << endl;
	cout << ptr+2 << endl;
	Sum(*ptr, 3, 4);

	//for (auto &p : a)                       //���ڷ�Χ��forѭ��������������ά����
	//{
	//	for (int elem : p)
	//		cout << elem << "  ";
	//}
	//cout << endl;

	for (int i = 0; i < 3; i++)           //��ʾ����������Ԫ�ص�ֵ
		for (int j = 0; j < 4; j++)
		{
			cout << *(*(a + i) + j) << " ";
		}
	cout << endl;

	cout << a << endl;                //�ᷢ��a��ֵ��*a��ֵ����ͬ��,*a=a[0],�����ǵ�����ʱ����ͬ��
	cout << *a << endl;
	int *p = (int*)a;                 //��ΪaΪ�������͵�ָ�룬����Ҫ����ǿ��ת��Ϊ�������͵�ָ��
	cout << *p << endl;
	cout << **a << endl;
	cout << a+1 << endl;              //a+1�����ַ����4*4�ֽ�
	cout << a+2 << endl;
	cout << "*************" << endl;
	for (int i = 0; i < 3; i++)       //��ӡ����a[i]�ĵ�ַ
	{
		cout << &a[i] << endl;
	}
	cout << "*************" << endl;
	for(int i = 0; i < 3; i++)        //��ӡ����Ԫ�صĵ�ַ
		for (int j = 0; j < 4; j++)
		{
			cout << &a[i][j] << endl;   //�ᷢ�ֶ�ά�������ڴ��������������洢��
		}

	Sum(a[0], 3, 4);      //������뺯�����м���



	system("pause");
	return 0;
}

void Sum(int *p, int hang, int lie)
{
	for (int i = 1; i < lie; i++)
	{
		for (int j = 0; j < hang; j++)
		{
			*(p + lie * j) += *(p + lie * j + i);
		}
		//*p += *(p + i);
		//*(p + hang*1) += *(p + hang*1 + i);
		//*(p + hang*2) += *(p + hang*2 + i);
	}
	for (int j = 0; j < hang; j++)
	{
		cout << *(p+ lie*j) << endl;
	}
	//cout << *p << endl;
	//cout << *(p+4) << endl;
	//cout << *(p+8) << endl;
}

//��ά���鴫�ݵ����ַ�ʽ
void func1(int arr[][4], int hang)   //1���������飬��Ҫ�����ڶ�ά�Ĵ�С
{

}

void func2(int(*arr)[4])             //2����������ָ�룬���������ڶ�ά�Ĵ�С
{

}
void func3(int *arr)                 //3������ָ�룬ָ��ָ����Ԫ�أ���������ʱ��Ҫǿ������ת��
{

}