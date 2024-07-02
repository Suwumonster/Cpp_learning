//三步翻转法
//1.反转后k%size个
//2.反转前面未反转的元素
//3.反转整个vector

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        auto pos = nums.end() - k;
        reverse(pos, nums.end());
        reverse(nums.begin(), pos);
        reverse(nums.begin(), nums.end());
    }
};