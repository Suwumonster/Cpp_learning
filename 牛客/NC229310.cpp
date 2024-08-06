//算法思路：排序+滑动窗口

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int n = 0;
    int p = 0;
    cin >> n >> p;
    vector<int> v;
    v.resize(n);
    for(auto&e : v)
    {
        cin >> e;
    }
    sort(v.begin(), v.end());
    int left = 0;
    int right = 0;
    int num = 0;
    while(right < n)
    {
        if(v[right] - v[left] <= 2*p)
        {
            num = max(num, right - left + 1);
            right++;
        }
        else{
            left++;
        }
    }
    
    cout << num << endl;
    return 0;
}