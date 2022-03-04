#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
typedef struct Link //结点结构
{
	int num;
	struct Link* next;
}link;
int icount = 0;//结点计数器，一共有几个结点，不算上头节点
link* setlink(); // 有头指针的link建立
void display(link* p);//输出整个链表的函数
void delLink(link* p);//删除整个链表的函数
int main()
{
	link* pp;
	pp = setlink();
	display(pp);
	delLink(pp);
	return 0;
}
link* setlink()//有头指针的link建立
{
	link* headp = (link*)malloc(sizeof(link));//头结点
	link* temp = headp;//指向当前结点的指针,初始化指向头结点
	int n;
	scanf("%d", &n);//要建立几个结点
	icount = n;
	while (n--)
	{
		link* newp = (link*)malloc(sizeof(link));
		scanf("%d", &newp->num);
		newp->next = NULL;//新指针 指向 空指针
		temp->next = newp;//当前结点 与 新结点 链接
		temp = newp;//当前指针 指向 新结点
	}
	return headp;
}



void display(link* p)//输出整个链表的函数
{
	link* temp;
	link* dis;
	temp = p->next;
	int i = 0;
	while (temp)
	{
		dis = temp;
		temp = temp->next;
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", dis->num);
	}
	printf("\n");
}

void delLink(link* p)//删除整个链表的函数
{
	link* temp;
	link* del;
	temp = p;
	while (temp)
	{
		del = temp;
		temp = temp->next;
		free(del);
	}
	icount = 0;
}



