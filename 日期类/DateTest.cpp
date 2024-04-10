#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"
void test1()//测试了 构造 析构 赋值 拷贝 +=
{
	Date a(2024, 4, 10);
	Date b;
	Date c = b = a;
	a += 10000;
	
}

void test2()//测试 + -= - 加减负数的情况 前置++ 后置++
{
	Date a(2024, 4, 10);
	Date b = a + 100;
	Date c = b - 99;
	b -= 99;
	b += -99;
	c -= -99;

	cout << a;
	cout << ++a;
	cout << a++;
	cout << a;
}

void test3() //测试了 前置-- 后置-- > == >= < <= != 天数相减
{
	Date a(2024, 4, 10);
	//cout << a;
	//cout << --a;
	//cout << a--;
	//cout << a;

	Date b(3000, 1, 1);
	//cout << (b != a);
	cout << b - a << endl;
}

int main()
{
	test3();
	return 0;
}