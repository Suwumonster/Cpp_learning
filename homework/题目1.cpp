#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;

typedef struct student
{
	int id;
	char name[20];
	char sex[2];
	struct student * next;
}stu;
int fun(stu* person, int n);
stu* link(int n);
int main()
{
	int n = 0;
	printf("请输入本次存入学生的个数:>");
	scanf("%d", &n);
	stu* person = link(n);
	cout << fun(person, n);
	return 0;
}
stu* link(int n)//链表建立
{
	stu* head = new stu[sizeof(stu)];//头指针
	stu* p;//用来开辟新结点的指针
	stu* temp;//当前指针
	temp = head;//指向头指针
	int i = 0;
	for (i = 0; i < n; i++)
	{
		p = new stu[sizeof(stu)];
		cout << "第"<< i + 1 <<"个学生的 学号 名字 性别(M/W):" << endl;
		cin >> p->id;
		cin >> p->name;
		cin >> p->sex;
		p->next = NULL;
		temp->next = p;
		temp = p;
	}
	return head;
}
int fun(stu* person, int n)
{
	int i = 0;
	stu* temp;
	temp = person->next;//首元结点
	int count = 0;
	while (n--)
	{
		if (strcmp((temp->sex),"M") == 0)
		{
			count++;
		}
		temp = temp->next;//进入下一个结点
	}
	return count;
}
