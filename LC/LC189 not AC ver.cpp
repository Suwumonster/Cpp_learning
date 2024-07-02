class Solution {
public:
    void rotateOnce(vector<int>& nums)
    {
        int tmp = *(nums.end() - 1);
        auto movePtr = nums.end() - 1;
        while(movePtr != nums.begin())
        {
            *movePtr = *(movePtr - 1);
            movePtr--;
        }
        nums[0] = tmp;
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        for(int i = 0; i < k; i++)
        {
            rotateOnce(nums);
        }
    }
};