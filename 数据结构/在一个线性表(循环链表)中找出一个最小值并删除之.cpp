#define _CRT_SECURE_NO_WARNINGS 1

//1.��һ�����Ա����ҳ�һ����Сֵ��ɾ��֮��
//��1������˳��洢�ķ�����ʵ�֣�����ֱ�Ӳ�����������ɡ�
//��2������ѭ������ķ�����ʵ�֡�

//��2�����
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

	tail->next = h;
	return tail;
}

void bubble_sort(node* h, node* end)
{
	if (h == end)
	{
		return;
	}
	node* p, * q;
	p = h;
	q = h->next;
	while (q != end)
	{
		if (p->data > q->data)
		{
			int x = p->data;
			p->data = q->data;
			q->data = x;
		}
		p = q;
		q = q->next;
	}
	if (p->data > q->data)
	{
		int x = p->data;
		p->data = q->data;
		q->data = x;
	}
	end = p;
	bubble_sort(h, end);
}

void del_min(node* L)
{
	if (L == 0)
	{
		return;
	}
	node* p = L->next;
	L->next = p->next;
	free(p);
	p = 0;
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
	bubble_sort(L->next, L);
	show_link(L);
	del_min(L);
	show_link(L);
	return 0;
}