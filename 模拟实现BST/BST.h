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
		BST() = default;
		BST(const BST<K>& t)
		{
			_root = _Copy(t._root);
		}
		~BST()
		{
			_destory(_root);
		}
		BST<K>& operator=(BST<K> t)
		{
			std::swap(_root, t._root);
			return *this;
		}
		//常规循环版本 插入删除查找 实际开发中推荐此版本
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
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
			Node* parent = nullptr;
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
					//delNode 左右子树为空 or delNode 左子树为空 右子树不为空
					//两种情况可以统一处理 直接删除法
					if (DelNode->_left == nullptr)
					{
						if (parent != nullptr)//删除结点不是根结点
						{
							if (parent->_left == DelNode)
							{
								parent->_left = DelNode->_right;
							}
							else
							{
								parent->_right = DelNode->_right;
							}
						}
						else//删除结点是根节点
						{
							_root = _root->_right;
						}
						delete DelNode;
					}
					else if (DelNode->_right == nullptr)//delNode 右子树为空 左子树不为空 直接删除法
					{
						if (parent != nullptr)//删除结点不是根结点
						{
							if (parent->_left == DelNode)
							{
								parent->_left = DelNode->_left;
							}
							else
							{
								parent->_right = DelNode->_left;
							}
						}
						else//删除结点是根结点
						{
							_root = _root->_left;
						}
						delete DelNode;
					}
					else//delNode 左右子树都不为空 间接删除法 通过找到 maxLeft 或者 minRight 
						//与删除节点进行KEY替换 删除节点 删除
					{
						//左子树最大结点 or 右子树最小结点 可以替代 delnode
						//默认 是 右子树最小结点 即 右子树的最左结点
						Node* minRight = DelNode->_right;
						Node* PminRight = DelNode;
						while (minRight->_left)
						{
							PminRight = minRight;
							minRight = minRight->_left;
						}

						DelNode->_key = minRight->_key;
						
						//minright肯定没有左节点；
						//右节点可能有，可能没有。
						//处理minright的右节点
						if (PminRight->_left == minRight)
						{
							PminRight->_left = minRight->_right;
						}
						else
						{
							PminRight->_right = minRight->_right;
						}

						//删除minright结点
						delete minRight;
					}
					return true;
				}
			}
			return false;
		}
		//递归版本 插入删除查找

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		Node* FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool EarseR(const K& key)
		{
			return _EarseR(_root, key);
		}
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

	protected:
		
		Node* _Copy(Node* root)//拷贝构造用
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			Node* NewRoot = new Node(root->_key);
			NewRoot->_left = _Copy(root->_left);
			NewRoot->_right = _Copy(root->_right);
			return NewRoot;
		}
		void _destory(Node*& root)//析构函数用
		{
			if (root == nullptr)
			{
				return;
			}
			_destory(root->_left);
			_destory(root->_right);
			delete root;
			root = nullptr;
		}
		void _InOrder(Node* root)//中序遍历用
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}
			if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else
			{
				return false;
			}
		}
		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else
			{
				return root;
			}
		}
		bool _EarseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if (root->_key > key)
			{
				return _EarseR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _EarseR(root->_right, key);
			}
			else
			{
				Node* del = root;
				if (del->_left == nullptr)
				{
					root = del->_right;
				}
				else if (del->_right == nullptr)
				{
					root = del->_left;
				}
				else
				{
					Node* maxLeft = del->_left;
					while (maxLeft->_right)
					{
						maxLeft = maxLeft->_right;
					}

					root->_key = maxLeft->_key;

					return _EarseR(root->_left, root->_key);
				}
				delete del;
				return true;
			}
		}

	private:
		Node* _root = nullptr;
	};
}
