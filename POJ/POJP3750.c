#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	char name[16];
	int check;
	struct node* next;
}node;
node* link(int);
void display(node * p, int n);
int main()
{
	int n = 0;
	scanf("%d", &n);
	node* p;
	p = link(n);
	display(p, n);
	return 0;
}
node* link(int n)
{
	node* headp = (node*)malloc(sizeof(node));
	node* tail;
	tail = headp;
	scanf("%s", tail->name);
	tail->next = 0;
	tail->check = 0;
	while (--n)
	{
		node* newp = (node*)malloc(sizeof(node));
		scanf("%s", newp->name);
		newp->check = 0;
		tail->next = newp;
		newp->next = 0;
		tail = newp;
	}
	tail->next = headp;
	return headp;
}

void display(node* p, int n)
{
	node* temp = 0;
	temp = p;
	int count = 0;
	int i = 0;
	int w, s = 0;
	scanf("%d,%d", &w, &s);
	for (i = 1; i < w; i++)
	{
		temp = temp->next;
	}
	for (i = 1;count < n;)
	{
		if (i % s == 0 && temp->check == 0)
		{
			printf("%s\n", temp->name);
			temp->check = 1;
			count++;
			i++;
		}
		else if (temp->check == 0)
		{
			i++;
		}
		temp = temp->next;
	}
}

