//有点类似滑动窗口的解法，但是可读性有点差
bool comp(const vector<int> a, const vector<int> b)
{
    return a[0] < b[0];
}
class Solution {
public:

    vector<vector<int>> fileCombination(int target) {
        vector<vector<int>> ret;
        size_t sum = 0;
        for (size_t i = 2; i < target; i++)//i 文件数量 即 累加个数
        {
            sum = 0;
            for (size_t j = 1; sum < target; j++)//j 从 j 开始往后累加
            {
                sum = 0;
                for (size_t k = 0; k < i; k++)
                {
                    sum += j + k;
                }
                if (sum == target)
                {
                    vector<int> tmp;
                    for (size_t k = 0; k < i; k++)
                    {
                        tmp.push_back(j + k);
                    }
                    ret.push_back(tmp);
                }
            }
        }
        sort(ret.begin(), ret.end(), comp);
        return ret;
    }
};