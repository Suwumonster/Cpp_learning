#pragma once
#include <iostream>
using namespace std;
namespace my_stl
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode* _left;
		BSTreeNode* _right;
		K _key;
		BSTreeNode(K key) : _key(key), _left(nullptr), _right(nullptr) {}
	};

	template<class K>
	class BST
	{
		typedef BSTreeNode<K> Node;
	public:
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
			}
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}
			if (parent->_key > key)
			{
				parent->_left = new Node(key);
			}
			else
			{
				parent->_right = new Node(key);
			}
			return true;
		}
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			Node* DelNode = _root;
			Node* parent = _root;
			while (DelNode)
			{
				if (DelNode->_key < key)
				{
					parent = DelNode;
					DelNode = DelNode->_right;
				}
				else if (DelNode->_key > key)
				{
					parent = DelNode;
					DelNode = DelNode->_left;
				}
				else
				{
					//delNode 左右子树为空
					if (DelNode->_left == nullptr && DelNode->_right == nullptr)
					{
						if (parent != DelNode)//删除结点不是最后一个结点
						{
							if (parent->_left && parent->_left->_key == DelNode->_key)
							{
								parent->_left = nullptr;
							}
							else
							{
								parent->_right = nullptr;
							}
						}
						else
						{
							_root = nullptr;
						}
						delete DelNode;
					}
					else if (DelNode->_left == nullptr)//delNode 左子树为空 右子树不为空
					{
						if (parent != DelNode)//删除结点时 n > 2
						{
							if (parent->_left && parent->_left->_key == DelNode->_key)
							{
								parent->_left = DelNode->_right;
							}
							else
							{
								parent->_right = DelNode->_right;
							}
						}
						else//删除结点时 n <= 2
						{
							_root = _root->_right;
						}
						delete DelNode;
					}
					else if (DelNode->_right == nullptr)//delNode 右子树为空 左子树不为空
					{
						if (parent != DelNode)//删除结点时 n > 2
						{
							if (parent->_left && parent->_left->_key == DelNode->_key)
							{
								parent->_left = DelNode->_left;
							}
							else
							{
								parent->_right = DelNode->_left;
							}
						}
						else//删除结点时 n <= 2
						{
							_root = _root->_left;
						}
						delete DelNode;
					}
					else//delNode 左右子树都不为空
					{
						//左子树最大结点 or 右子树最小结点 可以替代 delnode
						//默认 是 右子树最小结点
						Node* minRight = DelNode->_right;
						Node* PminRight = DelNode;
						while (minRight->_left)
						{
							PminRight = minRight;
							minRight = minRight->_left;
						}

						DelNode->_key = minRight->_key;
						//删除minright，但是minright有可能有右子树

						//处理minright的右子树
						if (minRight->_right)
						{
							Node* minRight_right = minRight->_right;
							if (PminRight->_left && PminRight->_left->_key == minRight->_key)
							{
								PminRight->_left = minRight_right;
							}
							else
							{
								PminRight->_right = minRight_right;
							}
							
						}
						else
						{
							//将minRight置空
							if (PminRight->_left && PminRight->_left->_key == minRight->_key)
							{
								PminRight->_left = nullptr;
							}
							else
							{
								PminRight->_right = nullptr;
							}
						}

						//删除minright结点
						delete minRight;
					}
					return true;
				}
			}
			return false;
		}
		
		~BST()
		{
			while (_root)
			{
				Erase(_root->_key);
			}
		}
	private:
		Node* _root = nullptr;
	};
}
