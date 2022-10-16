#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
//一棵具有n个结点的完全二叉树存放在二叉树的顺序存储结构中，
//试编写非递归算法对该树进行中序遍历。
//输入：n个整数结点值
//输出：中序遍历结果

typedef struct BinTree
{
	int data;
	int left;
	int right;
}tree;

void setbintree(int n, tree arr[])
{
	if (n == 0)
	{
		arr[0].data = -1;//无结点
		return;
	}
	arr[0].data = 1;//有结点
	queue <int> qu;
	int mark;
	qu.push(1);
	while (!qu.empty())
	{
		mark = qu.front();
		qu.pop();
		cin >> arr[mark].data;
		if (2 * mark <= n)
		{
			arr[mark].left = 2 * mark;
			qu.push(2 * mark);
		}
		else
		{
			arr[mark].left = 0;
		}
		if ((2 * mark + 1) <= n)
		{
			arr[mark].right = 2 * mark + 1;
			qu.push(2 * mark + 1);
		}
		else
		{
			arr[mark].right = 0;
		}
	}
}

void visit(tree* r)
{
	cout << r->data << " ";
}

void midorder(tree arr[])
{
	stack <tree*> st;
	if (arr[0].data == -1)
	{
		return;
	}
	tree* r = arr + 1;
	do
	{
		while (r != arr)
		{
			st.push(r);
			r = &arr[r->left];
		}
		if (!st.empty())
		{
			r = st.top();
			st.pop();
			visit(r);
			r = &arr[r->right];
		}
	} while (r != arr || !st.empty());
}

int main()
{
	int n = 0;
	tree* root = 0;
	cin >> n;
	root = new tree[n + 1];
	setbintree(n, root);
	midorder(root);
	return 0;
}