class Solution {//p找奇数，q找偶数，两个都是从前往后找
public:
    vector<int> trainingPlan(vector<int>& actions) {
        auto p = actions.begin();
        auto q = actions.begin();

        while(p != actions.end() && q !=actions.end())
        {
            while(p != actions.end())
            {
                if(*p & 0x1)
                {
                    break;
                }
                p++;
            }
            while(q != actions.end())
            {
                if(!(*q & 0x1))
                {
                    break;
                }
                q++;
            }
            if(p > q && p != actions.end() && q != actions.end())
            {
                swap(*p, *q);
            }
            if(p < q)
            {
                p = q + 1;
            }
        }
        return actions;
    }
};