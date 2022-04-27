#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class nauticalmile_kilometer
{
public:
	nauticalmile_kilometer();
	nauticalmile_kilometer(double);
	void print();
	void Double();
private:
	double kilometer;
};
nauticalmile_kilometer::nauticalmile_kilometer()
{
	kilometer = 0;
}
nauticalmile_kilometer::nauticalmile_kilometer(double x)
{
	kilometer = x;
}
void nauticalmile_kilometer::print()
{
	cout << kilometer << endl;
}
void nauticalmile_kilometer::Double()
{
	cout << "转为海里为：" << kilometer / 1.852 << "mile" << endl;
}
int main()
{
	double b;
	cin >> b;
	nauticalmile_kilometer a(b);
	a.print();
	a.Double();
	return 0;
}