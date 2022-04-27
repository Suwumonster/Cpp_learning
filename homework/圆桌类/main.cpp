#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "Roundtable.h"
using namespace std;
int main()
{
	float rr, hh;
	char c[10];
	cout << "ÇëÊäÈëÔ²×ÀÐÅÏ¢: Ô²×À°ë¾¶¡¢Ô²×À¸ß¡¢Ô²×ÀÑÕÉ«" << endl;
	cin >> rr >> hh >> c;
	Roundtable a(rr, hh, c);
	a.display();
	return 0;
}