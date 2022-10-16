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

void link_print(tree* r, tree*& tail)
{
	if (r == 0)
	{
		return;
	}
	link_print(r->left, tail);
	if (r->left == 0 && r->right == 0)
	{
		if (tail != 0)
		{
			tail->right = r;
		}
		cout << r->data << " ";
		tail = r;
		return;
	}
	link_print(r->right, tail);
}
int main()
{
	tree* root = 0;
	root = set_tree();

	tree* leftleave = 0;
	link_print(root, leftleave);
	return 0;
}