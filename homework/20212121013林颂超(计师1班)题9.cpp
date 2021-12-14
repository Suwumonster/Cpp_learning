#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int i = 1;
void Hanoi(int n, char A, char B, char C)//n个盘，A B C柱子
{
	if (1 == n)
	{
		cout<<"第"<<i++<<"次,"<< A <<" -> "<< C <<endl;
	}
	else
	{
		Hanoi(n - 1, A, C, B);
		cout << "第" << i++ << "次," << A << " -> " << C << endl;
		Hanoi(n - 1, B, A, C);
	}
}
int main()
{
	int n = 0;
	char A = 'A', B = 'B', C = 'C';
	cin >> n;
	Hanoi(n, A, B, C);
	return 0;
}