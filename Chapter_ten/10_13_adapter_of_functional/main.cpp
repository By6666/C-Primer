//����������--����������bind1st��bind2nd
//��Ԫ�������������������bind1st�ǽ������Ĳ������󶨵���һ��λ�ã�bind2nd�ǰ󶨵��ڶ���λ��

//����������--�����������not1��not2
//not1������һԪν�ʵ��߼�ȡ��
//not2�����ڶ�Ԫν�ʵ��߼�ȡ��

//����������--����ָ����������ptr_fun
//��һ�㺯����ָ��ת��Ϊ��������ʵ���ܹ���Ϊ��������������������

#include <iostream>
#include <functional>     //��������ͷ�ļ���������������ͺ���������
#include <vector>         //vector�����к�����Ӧ��iterator
#include <algorithm>      //�㷨ͷ�ļ�������find_if���㷨

using namespace std;

bool g(int x, int y)
{
	return x > y;
}

int main()
{
	int intArr[] = { 10,90,10,40,70,50,20,80 };
	const int N = sizeof(intArr) / sizeof(int);
	vector<int> a(intArr, intArr + N);
	//find_if�㷨��Ѱ��[first,end)��Χ�ڵĵ�һ������������Ԫ��
	vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(greater<int>(), 10));              //�����һ������10��Ԫ��
    //vector<int>::iterator p = find_if(a.begin(), a.end(), not1(bind2nd(greater<int>(), 10)));      //�����һ��������10��Ԫ��
	//vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(not2(greater<int>()), 10));      //������ͬ
	//vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(ptr_fun(g), 10));                //ͨ��ʹ�ú���ָ��������ptr_fun�����Խ�һ��ĺ���ָ��ת��Ϊ��������

		if (p == a.end())    cout << "no element greater than 40" << endl;
	else  cout << "first element greater than 40 is: " << *p << endl;






	system("pause");
	return 0;
}