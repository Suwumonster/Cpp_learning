/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
//二叉树的非递归遍历思路：
//把所有节点分为 左路节点（根和左节点） 和 左路节点的右子树
//把节点存入栈stack中，根据前序和中序和后序的需求依次输出和操作
//后序需要定义一个变量，表示一个节点是否遍历了右子树
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            v.push_back(cur->val);
            cur = cur->right;
        }
        return v;
    }
};