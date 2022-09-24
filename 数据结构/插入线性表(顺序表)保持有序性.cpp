#define _CRT_SECURE_NO_WARNINGS 1

//1.��һ����������Ա��в���һ��Ԫ�أ���Ҫ�������Ա�������ԡ�
//
//��1�������Ա�洢������A[0..arrsize - 1]��ǰelenum����Ԫ�У��ҵ�������
// �Ա�дһ���㷨�������Ա��в���Ԫ��x���豣�����Ա�������ԣ����ҷ����㷨��ʱ�临�Ӷȡ�
//
//��2�����Ա�洢�ڵ�����L�У��Ҹõ�����Ľ���ǰ�ֵ�ǵݼ��������еģ�
// �Ա�дһ�㷨������L�в���ֵΪX�Ľ�㣬ʹ��L��Ȼ����


//��1����⣺
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
	qsort(pc->data, pc->arrsize, sizeof(int), int_cmp);//ʱ�临�Ӷȣ�O(logn)
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
	cout << "������˳����ȣ�";
	cin >> n;
	cout << "������˳���Ԫ�أ�" << endl;
	set_contact(&c, n);
	show_contact(&c);
	cout << "����������Ԫ�ش�С��";
	cin >> insert_num;
	insert_contact(&c, insert_num);
	show_contact(&c);
	return 0;
}