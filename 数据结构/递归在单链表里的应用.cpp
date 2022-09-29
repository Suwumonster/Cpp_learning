#define _CRT_SECURE_NO_WARNINGS 1

//1.请设计出含有以下三个递归函数的程序。
//（1）设计递归函数，以实现单链表的建立。
//（2）设计递归函数，以实现单链表的输出。
//（3）设计递归函数，以实现单链表的逆置。

#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}node;
//(1)题解 输入-1停止读入
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
//(2)题解
void print_fun(node* p)
{
	if (p == 0)
	{
		return;
	}
	cout << p->data << " ";//顺序输出
	print_fun(p->next);
	//cout 放在这里逆序输出
}
//(3)题解
//返回值是逆置链表的最后一个结点
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
