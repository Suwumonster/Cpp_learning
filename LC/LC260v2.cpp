//第一步：
//把所有的元素进行异或操作，最终得到一个异或值。因为是不同的两个数字，所以这个值必定不为 0；
//
//第二步：
//取异或值最后一个二进制位为 1 的数字作为 mask，如果是 1 则表示两个数字在这一位上不同。
//
//第三步：
//通过与这个 mask 进行与操作，如果为 0 的分为一个数组，为 1 的分为另一个数组。
//这样就把问题降低成了：“有一个数组每个数字都出现两次，有一个数字只出现了一次，求出该数字”。
//对这两个子问题分别进行全异或就可以得到两个解。也就是最终的数组了。
//
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> v;
        unsigned int ret = 0;
        for(auto n: nums)
        {
            ret ^= n;
        }
        int mask = ret & (-ret);
        int ret1 = 0;
        int ret2 = 0;
        for(auto n: nums)
        {
            if(n&mask)
            {
                ret1 ^= n;
            }
            else
            {
                ret2 ^= n;
            }
        }
        v.push_back(ret1);
        v.push_back(ret2);
        return v;
    }
};