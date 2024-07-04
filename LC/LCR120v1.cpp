class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {//O(n) O(n)
        unordered_map<int, int> mp;
        for(auto e: documents)
        {
            mp[e]++;
        }
        for(auto e: mp)
        {
            if(e.second > 1)
            {
                return e.first;
            }
        }
        return -1;
    }
};