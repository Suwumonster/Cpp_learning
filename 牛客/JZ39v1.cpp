class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {//O(n) O(n)
        // write code here
        map<int, int> mp;
        for(auto n: numbers)
        {
            mp[n]++;
        }
        int halfLen = numbers.size() / 2;
        int ret = 0;
        for(auto m: mp)
        {
            if(m.second > halfLen)
            {
                ret = m.first;
            }
        }
        return ret;
    }
};