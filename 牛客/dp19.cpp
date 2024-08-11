#include <iostream>
#include <string>
#include <vector>
using namespace std;

//dp[i][j] 表示0-i,0-j最长公共子序列的长度
//dp[i][j] = dp[i- 1][j-1] + 1, s1[i] == s2[j]
//dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]), s1[i] != s2[j]
int main() {
    string s1;
    string s2;
    int n, m;
    cin >> n >> m;
    cin >> s1 >> s2;
    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")