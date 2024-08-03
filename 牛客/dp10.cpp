#include <iostream>
#include <vector>
using namespace std;
//1. 枚举所有子矩阵
//确定子矩阵左上角(x1,y1) 右下角(x2,y2)
//四层for循环遍历 二维数组
//
//2.二维前缀和 二维dp表
//dp[i][j] 表示 左上角(1,1) 至 右下角(i, j)的矩阵和
//状态转移方程 dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] 
//                          + grid[i - 1][j - 1]

//子矩阵和(x1, y1)(x2, y2) 等于
//dp[x2][y2] - (dp[x1 - 1][y2] + dp[x2][y1 - 1] - dp[x1 - 1][y1 - 1])
//画图!!!!
int main() {
    vector<vector<int>> grid;
    vector<vector<int>> dp;

    int n = 0;
    cin >> n;
    grid.resize(n, vector<int>(n));
    dp.resize(n + 1, vector<int>(n + 1));

    for(auto&v :grid)
    {
        for(auto&num :v)
        {
            cin >> num;
        }
    }
    //求二维前缀和
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < n + 1;j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] 
                        + grid[i - 1][j - 1];
        }
    }
    //枚举子矩阵求矩阵大小
    int MaxSum = dp[1][1];
    for(int x1 = 1; x1 < n + 1; x1++)
    {
        for(int y1 = 1; y1 < n + 1; y1++)
        {
            for(int x2 = x1; x2 < n + 1; x2++)
            {
                for(int y2 = y1; y2 < n + 1; y2++)
                {
                    MaxSum = max(MaxSum, 
                        dp[x2][y2] - (dp[x1 - 1][y2] + dp[x2][y1 - 1] - dp[x1 - 1][y1 - 1]));
                }
            }
        }
    }
    cout << MaxSum << endl;
}
// 64 位输出请用 printf("%lld")