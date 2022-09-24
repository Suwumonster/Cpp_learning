#define _CRT_SECURE_NO_WARNINGS 1

//1.��һ����������Ա��в���һ��Ԫ�أ���Ҫ�������Ա�������ԡ�
//
//��1�������Ա�洢������A[0..arrsize - 1]��ǰelenum����Ԫ�У��ҵ�������
// �Ա�дһ���㷨�������Ա��в���Ԫ��x���豣�����Ա�������ԣ����ҷ����㷨��ʱ�临�Ӷȡ�
//
//��2�����Ա�洢�ڵ�����L�У��Ҹõ�����Ľ���ǰ�ֵ�ǵݼ��������еģ�
// �Ա�дһ�㷨������L�в���ֵΪX�Ľ�㣬ʹ��L��Ȼ����

//��2�����
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
	//ʱ�临�Ӷȣ�O��n��
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