class Solution {//除法
public:
    vector<int> statisticalResult(vector<int>& arrayA) {//O(n) O(1)
        int total = 1;
        int zeroCount = 0;
        for(auto e : arrayA)
        {
            if(e != 0)
            {
                total *= e;
            }
            else
            {
                zeroCount++;
            }
        }
        vector<int> ret;
        for(auto e : arrayA)
        {
            if(zeroCount > 1)
            {
                ret.push_back(0);
            }
            else if(zeroCount == 1)
            {
                if(e == 0)
                {
                    ret.push_back(total);
                }
                else
                {
                    ret.push_back(0);
                }
            }
            else
            {
                ret.push_back(total/e);
            }
        }
        return ret;
    }
};