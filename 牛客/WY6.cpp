#include <iostream>
#include <utility>
#include <vector>
using namespace std;
//状态表示：dp[i][j].first 从1-i中选j个数, i 必选, 最大乘积
//         dp[i][j].second 从1-i中选j个数, i 必选, 最小乘积

//状态转移方程：dp[i][j].first = max(dp[i][j].first, max(dp[prev][j - 1].first * v[i - 1], dp[prev][j - 1].second * v[i - 1]));
//             dp[i][j].second = min(dp[i][j].second, min(dp[prev][j - 1].first * v[i - 1], dp[prev][j - 1].second * v[i - 1]));

int main() {
    int n, k, d;
    vector<int> v;
    cin >> n;
    v.resize(n);
    for(auto&e : v)
    {
        cin >> e;
    }
    cin >> k >> d;
    vector<vector<pair<long long, long long>>> dp;
    //初始化
    dp.resize(n + 1, vector<pair<long long, long long>>(k + 1, pair<int, int>(-0x3f3f3f3f3f3f3f3f, 0x3f3f3f3f3f3f3f3f)));
    for(int i = 1; i <= n; i++)
    {
        dp[i][1].first = v[i - 1];
        dp[i][1].second = v[i - 1];
    }
    //填表
    for(int i = 1; i <= n; i++)//表示从1-i中挑人 i必挑
    {
        for(int j = 2; j <= min(i, k); j++)//j表示挑几个人
        {
            for(int prev = max(i-d, j - 1); prev < i; prev++)//prev表示之前挑好的人
            {
                dp[i][j].first = max(dp[i][j].first, max(dp[prev][j - 1].first * v[i - 1], dp[prev][j - 1].second * v[i - 1]));
                dp[i][j].second = min(dp[i][j].second, min(dp[prev][j - 1].first * v[i - 1], dp[prev][j - 1].second * v[i - 1]));
            }
        }
    }
    //找最大值
    long long MAX = -0x3f3f3f3f3f3f3f3f;
    for(int i = 1; i <= n; i++)
    {
        MAX = max(MAX, dp[i][k].first);
    }
    cout << MAX << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")