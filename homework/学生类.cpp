#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
	Student(int, string, char);
	friend class Student1;
private:
	int num;
	string name;
	char sex;
};
Student::Student(int x, string y, char z)
{
	num = x;
	name = y;
	sex = z;
}
class Student1: private Student
{
public:
	Student1(int x, string y, char z, int a, string b);
	void display();
private:
	int age;
	string addr;
};
Student1::Student1(int x, string y, char z, int a, string b):Student(x, y, z)
{
	age = a;
	addr = b;
}
void Student1::display()
{
	cout << "num:" << num << endl;
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
	cout << "age:" << age << endl;
	cout << "address:" << addr << endl;

}
int main()
{
	int x;
	string y;
	char z;
	int a;
	string b;
	cout << "输入 学号 名字 性别(m/w) 年龄 地址" << endl;
	cin >> x >> y >> z >> a >> b;
	Student1 s(x, y, z, a, b);
	s.display();
	return 0;
}