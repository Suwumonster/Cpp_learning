#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param schedule int整型vector<vector<>> 
     * @return bool布尔型
     */
    using compare = struct Compare
    {
        bool operator()(vector<int>& v1, vector<int>& v2)
        {
            return v1[0] < v2[0];
        }
    };
//区间覆盖问题, 先按左/右端点排序，然后只需比较前一段区间的就OK
    bool hostschedule(vector<vector<int>>& schedule) {
        sort(schedule.begin(), schedule.end(), compare());
        for(int i = 1; i < schedule.size() ; i++)
        {
            if(schedule[i][0] < schedule[i - 1][1])
            {
                return false;
            }
        }
        return true;
    }
};