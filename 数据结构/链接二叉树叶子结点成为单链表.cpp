#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//编写一个将二叉树的所有叶子结点从左向右链接成单链表的算法。
//输入：扩充的二叉树前序遍历序列（整数值序列）， - 1表示空子树。
//输出：单链表从头到尾的输出结果。

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