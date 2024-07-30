//动态规划————经典线性dp问题
//状态表示：dp[i]表示以i下标结尾的最大连续子数组和
//状态转移方程：dp[i] = max(dp[i], dp[i - 1] + nums[i])
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.resize(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            dp[i] = nums[i];
        }
        int max = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(dp[i] < dp[i - 1] + nums[i])
            {
                dp[i] = dp[i - 1] + nums[i];
            }
            if(max < dp[i])
            {
                max = dp[i];
            }
        }
        return max;
    }
};