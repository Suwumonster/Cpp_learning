#define _CRT_SECURE_NO_WARNINGS 1

//1.在一个有序的线性表中插入一个元素，但要保持线性表的有序性。
//
//（1）设线性表存储在数组A[0..arrsize - 1]的前elenum个单元中，且递增有序。
// 试编写一个算法：在线性表中插入元素x，需保持线性表的有序性，并且分析算法的时间复杂度。
//
//（2）线性表存储在单链表L中，且该单链表的结点是按值非递减有序排列的，
// 试编写一算法在链表L中插入值为X的结点，使得L仍然有序。


//（1）题解：
#include <iostream>
#include <stdlib.h>
using namespace std;
#define maxsize 100

typedef struct contact
{
	int data[maxsize];
	int arrsize;
}contact;

int int_cmp(const void* a, const void* b)
{
	return *((int*)a) - *((int*)b);
}
void set_contact(contact * pc,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cin >> pc->data[i];
	}
	pc->arrsize = n;
	qsort(pc->data, n, sizeof(int), int_cmp);
}

void insert_contact(contact* pc, int x)
{
	int i = 0;
	if (pc->arrsize == maxsize)
	{
		return;
	}
	pc->data[pc->arrsize] = x;
	(pc->arrsize)++;
	qsort(pc->data, pc->arrsize, sizeof(int), int_cmp);//时间复杂度：O(logn)
}

void show_contact(contact* pc)
{
	int i = 0;
	for (i = 0; i < pc->arrsize; i++)
	{
		cout << pc->data[i] << " ";
	}
	cout << endl;
}
int main()
{
	contact c;
	int n = 0;
	int insert_num = 0;
	cout << "请输入顺序表长度：";
	cin >> n;
	cout << "请输入顺序表元素：" << endl;
	set_contact(&c, n);
	show_contact(&c);
	cout << "请输入插入的元素大小：";
	cin >> insert_num;
	insert_contact(&c, insert_num);
	show_contact(&c);
	return 0;
}