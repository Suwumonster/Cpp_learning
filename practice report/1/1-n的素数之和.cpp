#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n = 0, i, j, s = 3, p = 0;
	cin >> n;
	if (n == 1)
	{
		s = 1;
	}
	else if (n == 2)
	{
		s = 3;
	}
	else
	{
		for (i = 3; i <= n; i++)
		{
			for (j = 2; j < i; j++)
			{
				if (i % j == 0 && i != 1)
				{
					p = 0;
					break;
				}
				else
				{
					p = 1;
				}
			}
			if (p == 1)
			{
				s += i;
			}
		}
	}
	cout << s << endl;
	return 0;
}