class Solution {//O(n^2) O(N)
public:
    int maxProfit(vector<int>& prices) {//dp? yep,dp!
        vector<int> dp(prices.size(), 0);//sell in i day,dp[i] means maxProfit sell in i day
        for(int i = 1; i < prices.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(prices[j] < prices[i] && (prices[i] - prices[j]) > dp[i])
                {
                    dp[i] = prices[i] - prices[j];
                }
            }
        }

        int maxProfit = dp[0];
        for(int i = 1; i < dp.size(); i++)
        {
            if(maxProfit < dp[i])
            {
                maxProfit = dp[i];
            }
        }
        return maxProfit;
    }
};