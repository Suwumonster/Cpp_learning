#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
#define A(s,x,y,z) sqrt(s*(s - x)*(s - y)*(s - z))//书上海伦公式忘记开根号了
#define S(x,y,z) 1.0/2*(x + y + z)
using namespace std;
int main()
{
	double s, a, b, c,ar;
	cin >> a >> b >> c;
	s = S(a, b, c);
	ar = A(s, a, b, c);
	cout << ar << endl;
	return 0;
}

