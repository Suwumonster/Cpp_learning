#define _crt_secure_no_warnings 1

//1.在一个线性表中找出一个最小值并删除之。
//（1）利用顺序存储的方法来实现，可以直接采用数组来完成。
//（2）利用循环链表的方法来实现。
//
//（1）题解
#include <iostream>
using namespace std;


void del_min_arr(int arr[], int& n)
{
	int min = arr[0];
	int min_mark = 0;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			min_mark = i;
		}
	}
	for (i = min_mark; i < n; i++)
	{
		if (i < n - 1)
		{
			arr[i] = arr[i + 1];
		}
		else
		{
			arr[i] = 0;
		}
	}
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