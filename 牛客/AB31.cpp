#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


//算法原理: 区间 + 贪心
int main() {
    int n = 0;
    cin >> n;
    vector<pair<int, int>> v;
    v.resize(n);
    for(auto&e :v)
    {
        cin >> e.first;
        cin >> e.second;
    }
    sort(v.begin(), v.end());
    int ret = 1;//结果
    int last = v[0].second;//选中最后一个区间的末尾

    for(int i = 1; i < n; i++)
    {
        if(last <= v[i].first)//没有重叠
        {
            ret++;
            last = v[i].second;
        }
        else {//有重叠,区间更新成为最短重叠区间的末尾
            last = min(last, v[i].second);
        }
    }
    cout << ret << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")