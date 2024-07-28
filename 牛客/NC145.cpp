//01背包问题
//dp[i][j]表示求前i个能塞下j体积的最大物品价值
//dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]); 状态转移方程
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        vector<vector<int>> dp;
        dp.resize(n + 1, vector<int>(V+1, 0));
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < V + 1; j++)
            {
                if(j - vw[i - 1][0] >= 0)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vw[i - 1][0]] + vw[i - 1][1]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][V];
    }
};