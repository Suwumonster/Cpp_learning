#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"
void test1()//������ ���� ���� ��ֵ ���� +=
{
	Date a(2024, 4, 10);
	Date b;
	Date c = b = a;
	a += 10000;
	
}

void test2()//���� + -= - �Ӽ���������� ǰ��++ ����++
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

void test3() //������ ǰ��-- ����-- > == >= < <= != �������
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