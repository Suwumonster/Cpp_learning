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
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == nullptr)
        {
            return "";
        }
        string str = to_string(root->val);
        //1.左子树为空 右子树为空 两棵子树都不加括号
        //2.左子树为空 右子树不为空 都加括号
        //3.左子树不为空 右子树为空 左子树加 右不加
        //4.左子树不为空 右子树不为空 都加
        //总结:左子树加括号的情况: 2、3、4  root->left || root->right
        //     右子树加括号的情况：2、4  root->right

        if(root->left || root->right)
        {
            str += "(";
            str += tree2str(root->left);
            str += ")";
        }
        
        if(root->right)
        {
            str += "(";
            str += tree2str(root->right);
            str += ")";
        }
        return str;
    }
};