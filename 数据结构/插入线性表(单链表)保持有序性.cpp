#define _CRT_SECURE_NO_WARNINGS 1

//1.在一个有序的线性表中插入一个元素，但要保持线性表的有序性。
//
//（1）设线性表存储在数组A[0..arrsize - 1]的前elenum个单元中，且递增有序。
// 试编写一个算法：在线性表中插入元素x，需保持线性表的有序性，并且分析算法的时间复杂度。
//
//（2）线性表存储在单链表L中，且该单链表的结点是按值非递减有序排列的，
// 试编写一算法在链表L中插入值为X的结点，使得L仍然有序。

//（2）题解
#include <iostream>
using namespace std;

typedef struct Link
{
	int data;
	struct Link* next;
}Link;

Link* head_set_link(int n)
{
	Link* h = 0;
	int i = 0;
	Link* a;
	while (n--)
	{
		a = new Link;
		cin >> a->data;
		a->next = h;
		h = a;
	}
	return h;
}

void bubble_sort(Link* h, Link* end)
{
	Link* p, * q;
	p = h;
	q = h->next;
	if (q == end)
	{
		return;
	}
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
	end = p;
	bubble_sort(h, end);
}

Link* insert_link(Link *L, int x)
{
	Link* p, *q;
	p = L;
	q = L->next;
	if (p == 0)
	{
		return L;
	}
	while (q != 0 && x > q->data)
	{
		p = p->next;
		q = q->next;
	}
	Link* a = new Link;
	a->data = x;
	if (p == L && p->data > x)
	{
		a->next = L;
		L = a;
	}
	else
	{
		p->next = a;
		a->next = q;
	}
	//时间复杂度：O（n）
	return L;
}

void show_link(Link* L)
{
	Link* temp;
	temp = L;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << " ";
}
int main()
{
	Link *L = 0;
	int n = 0;
	int x = 0;
	cin >> n;
	L = head_set_link(n);
	bubble_sort(L, 0);
	show_link(L);
	cin >> x;
	L = insert_link(L, x);
	show_link(L);
	return 0;
}