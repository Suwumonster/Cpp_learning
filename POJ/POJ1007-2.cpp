#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct node
{
	char str[51];
	int measure;
	struct node* next;
}node;
node* link(int n, int m);
int sortnum(node*p, int n);
void sort(node* h, int m);
void display(node* p);
int main()
{
	int n, m = 0;
	node* p = 0;
	scanf("%d%d", &n, &m);
	p = link(n, m);
	sort(p,m);
	display(p);
	return 0;
}
node* link(int n, int m)
{
	node* head = (node*)malloc(sizeof(node));
	scanf("%s", head->str);
	head->measure = sortnum(head, n);
	head->next = 0;
	node* tail;
	tail = head;
	m--;
	while (m--)
	{
		node* temp = (node*)malloc(sizeof(node));
		scanf("%s", temp->str);
		temp->measure = sortnum(temp, n);
		temp->next = 0;
		tail->next = temp;
		tail = temp;
	}
	return head;
}
int sortnum(node* p, int n)
{
	int i, j = 0;
	int sum = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (p->str[i] > p->str[j])
			{
				sum++;
			}
		}
	}
	return sum;
}
void sort(node* h, int m)
{
	node* p, * q;
	node* tail = 0;
	int i,x = 0;
	int isbreak = 1;
	char s[51] = { 0 };
	if (h == 0)
	{
		return ;
	}
	for (i = 0; i < m - 1; i++)
	{
		q = h;
		p = h->next;
		isbreak = 1;
		while (p != tail && p != 0)
		{
			if ((q->measure) > (p->measure))
			{
				x = q->measure;
				q->measure = p->measure;
				p->measure = x;
				strcpy(s, q->str);
				strcpy(q->str, p->str);
				strcpy(p->str, s);
				isbreak = 0;
			}
			p = p->next;
			q = q->next;
		}
		if (isbreak == 1)
		{
			return ;
		}
		tail = q;
	}
}
void display(node* p)
{
	int i = 0;
	node* temp = 0;
	temp = p;
	for (i = 0; temp != 0; i++)
	{
		printf("%s\n", temp->str);
		temp = temp->next;
	}
}