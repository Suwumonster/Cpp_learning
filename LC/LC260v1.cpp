class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> v;
        map<int, int> mp;
        for(auto n: nums)
        {
            mp[n] = 0;
        }
        for(auto n: nums)
        {
            mp[n]++;
        }
        for(auto m: mp)
        {
            if(m.second == 1)
            {
                v.push_back(m.first);
            }
        }
        return v;
    }
};