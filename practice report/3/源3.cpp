#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int main()
{
	int x, y;
	for (x = 10; x < 100; x += 10)
	{
		for (y = 0; y < 10; y++)
		{
			if ((x + 2) * (70 + y) == 3848)
				cout << x / 10 << "2*7" << y << "=3848" << endl;
		}
	}
	return 0;
}