#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//��дһ����������������Ҷ�ӽ������������ӳɵ�������㷨��
//���룺����Ķ�����ǰ��������У�����ֵ���У��� - 1��ʾ��������
//������������ͷ��β����������

typedef struct BinTree
{
	int data;
	struct BinTree* left;
	struct BinTree* right;
}tree;

typedef struct NODE
{
	int data;
	struct NODE* next;
}node;

tree* set_tree()
{
	int x = 0;
	cin >> x;
	tree* t = new tree;
	if (x == -1)
	{
		return 0;
	}
	t->data = x;
	t->left = set_tree();
	t->right = set_tree();
	return t;
}

void link(tree* r, node*& tail, node*& head)
{
	if (r == 0)
	{
		return;
	}
	link(r->left, tail, head);
	if (r->left == 0 && r->right == 0)
	{
		if (head == 0)
		{
			head = new node;
			head->data = r->data;
			tail = head;
		}
		else
		{
			tail->next = new node;
			tail->next->data = r->data;
			tail = tail->next;
		}
		tail->next = 0;
		return;
	}
	link(r->right, tail, head);
}

void print(node* h)
{
	if (h == 0)
	{
		return ;
	}
	cout << h->data << " ";
	print(h->next);
}
int main()
{
	tree* root = 0;
	node* head = 0;
	node* tail = 0;
	root = set_tree();

	link(root, tail, head);
	print(head);
	return 0;
}