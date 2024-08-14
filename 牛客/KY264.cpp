#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>//tolower
using namespace std;
using compare = struct Compare
{
    bool operator()(const pair<string, int> kv1, const pair<string, int> kv2) const
    {
        return kv1.second > kv2.second || (kv1.second == kv2.second && kv1.first < kv2.first);
    }
};

int main() {
    string str;
    map<string, int> mp;
    while(cin >> str)
    {
        string tmp;
        for(auto ch: str)
        {
            if(ch != ',' && ch != '.')
                tmp.push_back(tolower(ch));
        }
        mp[tmp]++;
    }
    vector<pair<string, int>> ret(mp.begin(), mp.end());
    sort(ret.begin(), ret.end(), compare());
    for(auto kv: ret)
    {
        cout << kv.first << ":" << kv.second << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")