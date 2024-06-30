class Solution {
public:
    int singleNumber(vector<int>& nums) {//O(N) O(1)
        int ret = 0;
        int total = 0;
        for(int i = 0; i < 32; i++)
        {
            total = 0;
            for(auto n: nums)
            {
                total += (n >> i) & 1;
            }
            if(total % 3)
            {
                ret |= 1 << i;
            }
        }
        return ret;
    }
};