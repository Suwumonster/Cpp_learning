/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	//算法思路：先写一个中序遍历，然后定义一个输出型参数prev，用于记录中序遍历的上一个节点
	//然后链接prev和当前中序遍历到的节点就行
	void InOrder(TreeNode* cur, TreeNode*& prev)
	{
		if(cur == nullptr)
		{
			return;
		}
		InOrder(cur->left, prev);
		if(prev) prev->right = cur;
		cur->left = prev;
		prev = cur;
		InOrder(cur->right, prev);
	}
    TreeNode* Convert(TreeNode* pRootOfTree) {
		if(pRootOfTree == nullptr)
		{
			return nullptr;
		}
        TreeNode* head = pRootOfTree;
		TreeNode* prev = nullptr;
		while(head->left)
		{
			head = head->left;
		}
		InOrder(pRootOfTree, prev);
		return head;
    }
};
