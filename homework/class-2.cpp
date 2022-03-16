#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class people
{
public:
	void begin();
	void eatting();
	void sporting();
	void sleeping();
	void display();
private:
	int age;
	int high;
	int weight;
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
void people::display()
{
	cout << "age:" << age << endl;
	cout << "high:" << high << endl;
	cout << "weight:" << weight << endl;
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
			person.display();
		}
		else if (n == 2)
		{
			person.sporting();
			person.display();
		}
		else if (n == 3)
		{
			person.sleeping();
			person.display();
		}
		else if (n == -1)
		{
			break;
		}
	}
	return 0;
}