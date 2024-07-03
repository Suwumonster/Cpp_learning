class Solution {//familar with quick sort
public:
    vector<int> trainingPlan(vector<int>& actions) {
        int p = 0;//找偶数，从左往右找
        int q = actions.size() - 1;//找奇数，从右往左找。

        while(p < q)
        {
            while(p < q)
            {
                if(!(actions[p] & 0x1))
                {
                    break;
                }
                p++;
            }
            while(p < q)
            {
                if(actions[q] & 0x1)
                {
                    break;
                }
                q--;
            }
            if(p < q)
            {
                swap(actions[p], actions[q]);
                p++;
                q--;
            }
        }
        return actions;
    }
};