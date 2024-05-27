class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        for(auto t : nums)
        {
            if(t != val)
            {
                nums[cur++] = t;
            }
        }
        return cur;
    }
};