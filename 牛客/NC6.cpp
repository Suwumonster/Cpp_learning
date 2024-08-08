/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

//算法思路:递归 + 树形dp
//树形dp：后序遍历
//返回值：最大单链和
//ret 记载最大路径和
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型
     */
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = max(0, dfs(root->left));
        int r = max(0, dfs(root->right));
        ret = max(root->val + l + r, ret);
        return max(l,r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ret;
    }
    int ret = -1010;
};