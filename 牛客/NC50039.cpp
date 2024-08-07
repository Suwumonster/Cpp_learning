#include <iostream>
using namespace std;
//每次相乘都需要取模!!!!!草
int main()
{
    int n,m;
    cin >> n >> m;
    int ret = n;
    while(--m)
    {
        ret *= (n - 1);
        ret %= 109;
    }
    cout << ret << endl;
    return 0;
}