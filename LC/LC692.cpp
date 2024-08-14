class Solution {
public:
    using compare = struct Compare
    {
        bool operator()(const pair<string, int> kv1, const pair<string, int> kv2) const
        {
            return kv1.second > kv2.second || (kv1.second == kv2.second && kv1.first < kv2.first);
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(auto s: words)
        {
            mp[s]++;
        }
        vector<pair<string, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), compare());
        vector<string> ret;
        for(int i = 0; i < k; i++)
        {
            ret.push_back(v[i].first);
        }
        return ret;
    }
};