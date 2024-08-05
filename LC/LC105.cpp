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

//算法思路：先遍历preorder确定根节点，再去inorder中找到根节点的值，确定左子树区间和右子树区间
class Solution {
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& pindex, int inbegin, int inend)
    {
        if(pindex >= preorder.size() || inbegin > inend)
        {
            return nullptr;
        }
        TreeNode* cur = new TreeNode(preorder[pindex]);
        int rooti = inbegin;
        for(; rooti <= inend; rooti++)
        {
            if(preorder[pindex] == inorder[rooti])
            {
                break;
            }
        }
        pindex++;
        cur->left = _buildTree(preorder, inorder, pindex, inbegin, rooti - 1);
        cur->right = _buildTree(preorder, inorder, pindex,  rooti + 1, inend);

        return cur;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pindex = 0;
        return _buildTree(preorder, inorder, pindex, 0, inorder.size() - 1);
    }
};