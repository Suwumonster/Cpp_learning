class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;
        for(auto t : nums)
        {
            if(t != nums[cur])
            {
                nums[++cur] = t;
            }
        }
        return cur + 1;
    }
};