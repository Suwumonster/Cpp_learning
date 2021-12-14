#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//二分查找有序数组
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 17;//目标数
	int sz = sizeof(arr) / sizeof(arr[0]);//数组元素个数
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			cout << "找到了，下标为：" << mid << endl;
			break;
		}
	}
	if (left > right)
	{
		cout << "没找到" << endl;
	}
	return 0;
}