#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream> 
#include<iomanip> 
using namespace std;
void main()
{
	double weight, price, real_pay, per;
	cout << "请输入苹果重量(斤)：";
	cin >> weight;
	if (weight > 10)
		per = 0.8;
	else if (weight > 8)
		per = 1.0;
	else if (weight > 6)
		per = 1.2;
	else if (weight > 4)
		per = 1.5;
	else
		per = 1.8;
	price = weight * per;
	cout << setprecision(2);
	cout << fixed;
	cout << "应付货款：" << price << endl;
	cout << "顾客实际付款：";
	cin >> real_pay;
	cout << "应找回钱数：" << real_pay - price << endl;
}