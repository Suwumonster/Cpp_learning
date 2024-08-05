/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//算法思路:逆序遍历postorder确定根节点,再去inorder数组找到根节点的值确定左子树和右子树的区间
class Solution {
public:
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& pindex, int inbegin, int inend)
    {
        if(pindex < 0 || inbegin > inend)
        {
            return nullptr;
        }
        TreeNode* cur = new TreeNode(postorder[pindex]);
        int rooti = inbegin;
        for(; rooti <= inend; rooti++)
        {
            if(postorder[pindex] == inorder[rooti])
            {
                break;
            }
        }
        pindex--;
        cur->right = _buildTree(inorder, postorder, pindex,  rooti + 1, inend);
        cur->left = _buildTree(inorder, postorder, pindex, inbegin, rooti - 1);

        return cur;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pindex = postorder.size() - 1;
        return _buildTree(inorder, postorder, pindex, 0, inorder.size() - 1);
    }
};