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

void link(tree* r, tree*& head)
{
	if (r == 0)
	{
		return;
	}
	if (r->left == 0 && r->right == 0)
	{
		r->right = head;
		head = r;
		return;
	}
	link(r->right, head);
	link(r->left, head);
}

void print(tree* r)
{
	if (r == 0)
	{
		return;
	}
	cout << r->data << " ";
	print(r->right);
}
int main()
{
	tree* root = 0;
	root = set_tree();
	tree* head = 0;
	link(root, head);
	print(head);
	return 0;
}