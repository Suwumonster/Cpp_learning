#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int main()
{
	int a = 0;	double x = 1.0, y;
	cin >> a;
	do 
	{
		y = x;
		x = 1 / 2.0 * (x + a / x);
	}
	while (abs(x - y) >= 1.e-5);
	cout << y;
	return 0;
}