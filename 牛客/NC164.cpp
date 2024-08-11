class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 该数组最长严格上升子序列的长度
     * @param a int整型vector 给定的数组
     * @return int整型
     */
    //1. 不关心序列长什么样，只关心长度为x的末尾是什么！
    //2. 长度为 x 的序列 只需要存储 最小的末尾数
    //3. 优化：二分查找
    int LIS(vector<int>& a) {
        vector<int> last;//长度为下标 + 1的最小末尾数
        for (auto num : a) {
            if(last.size() == 0 || num > last[last.size() - 1])
            {
                last.push_back(num);
            }
            else {
                //二分查找
                int l = 0;
                int r = last.size() - 1;
                while (l < r) {
                    int mid = (l + r)/2;
                    if(last[mid] >= num)
                    {
                        r = mid;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                last[l] = num;
            }
        }
        return last.size();
    }
};