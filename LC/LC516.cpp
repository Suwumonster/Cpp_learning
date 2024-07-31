//O（n^2） O（n^2）
//动态规划 区间dp
//状态表示： dp[i][j] 表示 i - j 之间的最长回文子序列.
//状态转移方程: 
// i > j      dp[i][j] = 0
// i == j     dp[i][j] = 1
// i < j
//   a.  s[i] == s[j]   dp[i][j] = 2 + dp[i + 1][j - 1]
//   b.  s[i] != s[j]   dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp;
        dp.resize(s.size(), vector<int>(s.size(), 0));
        for(int i = s.size() - 1; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(i == j)
                {
                    dp[i][j] = 1;
                }
                else if(i < j)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                    else
                    {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};