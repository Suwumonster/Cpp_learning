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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        int level = 1;//记录同一层节点的个数
        queue<TreeNode*> qu;
        if(root != nullptr)
        {
            qu.push(root);
        }
        while(!qu.empty())
        {
            vector<int> v;
            while(level--)
            {
                TreeNode* cur = qu.front();
                qu.pop();
                v.push_back(cur->val);
                if(cur->left)
                {
                    qu.push(cur->left);
                }
                if(cur->right)
                {
                    qu.push(cur->right);
                }
            }
            vv.push_back(v);
            level = qu.size();
        }
        return vv;
    }
};