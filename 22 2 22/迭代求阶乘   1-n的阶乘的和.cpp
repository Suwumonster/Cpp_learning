#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int main()
{
	int i;
	int sum = 0;
	int ret = 1;
	int n = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		ret *= i;
		sum += ret;
	}
	cout << "n的阶乘" << ret << endl;
	cout << "1-n的阶乘之和" << sum << endl;
	return 0;
}