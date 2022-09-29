#define _CRT_SECURE_NO_WARNINGS 1

//1.����Ƴ��������������ݹ麯���ĳ���
//��1����Ƶݹ麯������ʵ�ֵ�����Ľ�����
//��2����Ƶݹ麯������ʵ�ֵ�����������
//��3����Ƶݹ麯������ʵ�ֵ���������á�

#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}node;
//(1)��� ����-1ֹͣ����
node* set_fun()
{
	int x;
	cin >> x;
	if (x == -1)
	{
		return 0;
	}
	node* p = new node;
	p->data = x;
	p->next = set_fun();
	return p;
}
//(2)���
void print_fun(node* p)
{
	if (p == 0)
	{
		return;
	}
	cout << p->data << " ";//˳�����
	print_fun(p->next);
	//cout ���������������
}
//(3)���
//����ֵ��������������һ�����
node* inverse_fun(node *p, node *&h)
{
	if (p->next == 0)
	{
		h = p;
		return p;
	}
	inverse_fun(p->next, h)->next = p;
	p->next = 0;
	return p;
}
int main()
{
	node* p = set_fun();
	node* newh = new node;
	print_fun(p);
	cout << endl;
	inverse_fun(p, newh);
	print_fun(newh);
	cout << endl;
	return 0;
}
