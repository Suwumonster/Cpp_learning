#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void judge(int x)
{
	if (x > 0)
	{
		cout << x << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}
int main()
{
	int arr[5] = { -2, -1, 0, 1, 2 };
	int count;
	for (count = 0; count < 5; count++)
	{
		judge(arr[count]);
	}
	return 0;
}