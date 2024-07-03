//滑动窗口解法：(sliding window)
//适用情况：递增序列都适用
//[i, j) 滑动窗口区间 i < j
//i和j都只能向右移动，保证算法时间复杂度为O(n)
//滑动窗口区间的缩小和扩大
//缩小：左边界i往右移动
//扩大：右边界j往右移动
//此题实质上是求和，使得sum == target
//只需要不断调整滑动窗口区间就可以
class Solution {//优化v1, 增加可读性
public:
    size_t sum(int x, int y)//对于[x, y)正整数滑动窗口区间求和
    {
        size_t ret = 0;
        for(int i = x; i < y; i++)
        {
            ret += i;
        }
        return ret;
    }
    vector<vector<int>> fileCombination(int target) {
        vector<vector<int>> ret;
        int i = 1;
        int j = 2;
        while(i < j && j < target)
        {
            if(sum(i, j) < target)//扩大区间
            {
                j++;
            }
            else if(sum(i, j) > target)//缩小区间
            {
                i++;
            }
            else//找到符合target的序列
            {
                vector<int> tmp;
                for(int k = i; k < j; k++)
                {
                    tmp.push_back(k);
                }
                ret.push_back(tmp);
                i++;//找到之后，应该当继续往右遍历,直到i >= j (这种情况说明没有解了) 或者 j == target
            }
        }
        return ret;
    }
};