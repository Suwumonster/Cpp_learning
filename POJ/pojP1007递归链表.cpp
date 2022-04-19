#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;
typedef struct NODE
{
	char c[51];
	int measure;
	struct NODE * next;
}node;
node* link(int m)
{
	node * h;
	h = new node;
	if (m == 0)
	{
		return 0;
	}
	cin >> h->c;
	h->next = link(m-1);
	return h;
}
void measure(node *h, int n)
{
	node * temp;
	temp = h;
	while (temp != 0)
	{
		int sum = 0;
		for (int i = 0; i < n - 1 ; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (temp->c[i] > temp->c[j])
				{
					sum++;
				}
			}
		}
		temp->measure = sum;
		temp = temp->next;
	}
}
void sort(node * h, int m, node* &p, node* &q)
{
	if (m == 0)
	{
		return ;
	}
	node *temp;
	temp = h;
	for (int i = 0; i < m - 1; i++)
	{
		if (temp->next != 0)
		{
			p = temp->next;
			q = temp;
			temp = temp->next;
			if (q->measure > p->measure)
			{
				char cc[51];
				int x;
				strcpy(cc, q->c);
				x = q->measure;
				strcpy(q->c, p->c);
				q->measure = p->measure;
				strcpy(p->c, cc);
				p->measure = x;
			}
		}
	}
	sort(h, m - 1, p, q);
}
void display(int m,node *h)
{
	if (m == 0)
	{
		return ;
	}
	cout << h->c << endl;
	display(m - 1,h->next);
}
int main()
{
	int n = 0;//length of str
	int m = 0;//number of str
	cin >> n >> m;
	node *h = 0;
	node *p = 0;
	node *q = 0;
	h = link(m);
	measure(h, n);
	sort(h, m, p, q);
	display(m, h);
	return 0;
}
