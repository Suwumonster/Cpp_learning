#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
using namespace std;

//���һ������ʵ�������α����������ɶ�����������ʽ�ṹ���������������������ö�������
//���룺��α������е�n������ֵ�� - 1��ʾ��������
//���������������

typedef struct BinTree
{
	int data;
	struct BinTree* left;
	struct BinTree* right;
}tree;

tree* settree()
{
	int x = 0;
	cin >> x;
	if (x == -1)
	{
		return 0;
	}
	queue <tree*> qu;
	tree* root = 0;
	tree* tmp = 0;
	root = new tree;
	root->data = x;
	qu.push(root);
	while (!qu.empty())
	{
		tmp = qu.front();
		qu.pop();
		cin >> x;
		if (x == -1)
		{
			tmp->left = 0;
		}
		else
		{
			tmp->left = new tree;
			tmp->left->data = x;
			qu.push(tmp->left);
		}
		cin >> x;
		if (x == -1)
		{
			tmp->right = 0;
		}
		else
		{
			tmp->right = new tree;
			tmp->right->data = x;
			qu.push(tmp->right);
		}
	}
	return root;
}

void print(tree* r)
{
	if (r == 0)
	{
		return;
	}
	print(r->left);
	cout << r->data << " ";
	print(r->right);
}

int main()
{
	tree* root = 0;
	root = settree();
	print(root);
	return 0;
}