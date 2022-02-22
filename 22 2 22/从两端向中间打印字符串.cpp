#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;
int main()
{
	char arr1[] = "Salvation lies within.";
	char arr2[] = "**********************";
	int left = 0;
	int right = strlen(arr1) - 1;
	cout << arr2 << endl;
	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		Sleep(1000);
		system("cls");
		cout << arr2 << endl;
		left++;
		right--;
	}
	return 0;
}