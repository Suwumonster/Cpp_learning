/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//算法思路:找公共祖先, 把根节点到找寻节点的路径（即祖先节点包括找寻节点自己）存储到stack中
//先令两个stack个数相等，即令两个stack top出来的 祖先节点 在同一层，比较stack top出来的祖先节点是否相等
//最先相等的祖先节点就是最近的公共祖先节点
class Solution {
public:
    bool FindPath(TreeNode* root, stack<TreeNode*>& path, TreeNode* dst)//找寻路径
    {
        if(root == nullptr)
        {
            return false;
        }
        if(root == dst)
        {
            path.push(root);
            return true;
        }

        path.push(root);
        bool flag = FindPath(root->left, path, dst);
        if(flag)
        {
            return true;
        }
        flag |= FindPath(root->right, path, dst);
        if(flag)
        {
            return true;
        }
        else
        {
            path.pop();
            return false;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> Ppath;
        stack<TreeNode*> Qpath;
        FindPath(root, Ppath, p);
        FindPath(root, Qpath, q);
        while(Ppath.size() != Qpath.size())
        {
            if(Ppath.size() > Qpath.size())
            {
                Ppath.pop();
            }
            else{
                Qpath.pop();
            }
        }
        while(!Ppath.empty() && Ppath.top() != Qpath.top())
        {
            Ppath.pop();
            Qpath.pop();
        }
        return Ppath.top();
    }
};