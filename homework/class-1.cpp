#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class people
{
public:
	int age;
	int high;
	int weight;
	void begin();
	void eatting();
	void sporting();
	void sleeping();
};
void people::begin()
{
	age = 18;
	high = 170;
	weight = 120;
}
void people::eatting()
{
	weight++;
}
void people::sporting()
{
	high++;
}
void people::sleeping()
{
	age++;
	high++;
	weight++;
}
int main()
{
	people person;
	people* p = &person;
	person.begin();
	int n = 0;
	while (1)
	{
		cout << "输入一个数，1进食，2运动，3睡觉,-1退出程序" << endl;
		cin >> n;
		if (n == 1)
		{
			person.eatting();
			cout << "age:" << p->age << endl;
			cout << "high:" << p->high << endl;
			cout << "weight:" << p->weight << endl;
		}
		else if (n == 2)
		{
			person.sporting();
			cout << "age:" << p->age << endl;
			cout << "high:" << p->high << endl;
			cout << "weight:" << p->weight << endl;
		}
		else if (n == 3)
		{
			person.sleeping();
			cout << "age:" << p->age << endl;
			cout << "high:" << p->high << endl;
			cout << "weight:" << p->weight << endl;
		}
		else if (n == -1)
		{
			break;
		}
	}
	return 0;
}