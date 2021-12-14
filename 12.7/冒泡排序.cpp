#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void change(int arr[], int n);
int main()
{
	int arr[15] = { 0 };
	int count;
	for (count = 0; count < 15; count++)
	{
		cin >> arr[count];
	}
	change(arr, 15);
	for (count = 0; count < 15; count++)
	{
		cout << arr[count] << endl;
	}
	return 0;
}
void change(int arr[], int n)
{
	int i, temp, k, j;
	for (i = 0;i < n - 1;i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}