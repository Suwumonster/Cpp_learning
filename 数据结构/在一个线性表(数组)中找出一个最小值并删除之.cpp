#define _CRT_SECURE_NO_WARNINGS 1

//1.��һ�����Ա����ҳ�һ����Сֵ��ɾ��֮��
//��1������˳��洢�ķ�����ʵ�֣�����ֱ�Ӳ�����������ɡ�
//��2������ѭ������ķ�����ʵ�֡�

//��1�����
#include <iostream>
#include <stdlib.h>
using namespace std;

int int_cmp(const void* a, const void* b)
{
	return *((int*)b) - *((int*)a);
}

void del_min_arr(int arr[], int& n)
{
	qsort(arr, n, sizeof(int), int_cmp);
	arr[n - 1] = 0;
	n--;
}

void show_arr(int arr[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[20] = { 0 };
	int n = 0;
	int i = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	del_min_arr(arr, n);
	show_arr(arr, n);
	return 0;
}