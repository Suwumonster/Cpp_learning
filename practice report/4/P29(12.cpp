#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int main()
{
	int arr[50][50] = { 0 };
	int n, left = 0, right, up = 0, down, i = 1;
	int count,j;
	cin >> n;
	right = n;
	down = n;
	while (left <= right)//数字存入二维数组
	{
		for (count = up; count < down ; count++)
		{
			arr[count][left] = i++;
		}
		for (count = left + 1; count < right; count++)
		{
			arr[down - 1][count] = i++;
		}
		for (count = down - 2; count >= up; count--)
		{
			arr[count][right - 1] = i++;
		}
		for (count = right - 2; count > left; count--)
		{
			arr[up][count] = i++;
		}
		up++;
		left++;
		down--;
		right--;
	}
	for (count = 0; count < n; count++)//输出二维数组
	{
		for (j = 0; j < n; j++)
		{
			cout << arr[count][j]<< "\t";
		}
		cout << endl;
	}
	return 0;
}