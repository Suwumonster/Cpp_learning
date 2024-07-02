//minCost记录已经遍历过的最少花费买入
//maxProfit记录最大利润
class Solution {//O(n) O(1)
public:
    int maxProfit(vector<int>& prices) {
        int minCost = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            minCost = min(minCost, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minCost);
        }
        return maxProfit;
    }
};