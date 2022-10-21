#define _CRT_SECURE_NO_WARNINGS 1

//1.在一个线性表中找出一个最小值并删除之。
//（1）利用顺序存储的方法来实现，可以直接采用数组来完成。
//（2）利用循环链表的方法来实现。

//（2）题解
#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}node;

node* tail_set_link(int n)
{
	node* h = 0;
	node* tail = 0;
	node* a;
	if (n == 0)
	{
		return 0;
	}
	h = new node;
	cin >> h->data;
	h->next = 0;
	tail = h;
	n--;

	while (n--)
	{
		a = new node;
		cin >> a->data;
		a->next = 0;
		tail->next = a;
		tail = a;
	}
	if (tail != h)
	{
		tail->next = h;
	}
	return tail;
}


void del_min(node*& t)
{
	if (t == 0)
	{
		return;
	}
	if (t->next == 0)
	{
		t = 0;
		return;
	}
	node* p = t->next;
	node* q = 0;
	int min = p->data;
	while (p != t)
	{
		if (min > p->data)
		{
			min = p->data;
		}
		p = p->next;
	}
	if (min > p->data)
	{
		min = p->data;
	}

	q = t->next;
	while (q != t)
	{
		if (min == q->data)
		{
			p->next = q->next;
			delete q;
			return;
		}
		p = p->next;
		q = q->next;
	}
	if (min == q->data)
	{
		p->next = q->next;
		t = p;
		delete q;
	}
}

void show_link(node* L)
{
	if (L == 0)
	{
		return;
	}
	node* p;
	p = L->next;
	while (p != L)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << endl;
}
int main()
{
	int n = 0;
	node* L = 0;
	cin >> n;
	L = tail_set_link(n);
	del_min(L);
	show_link(L);
	return 0;
}