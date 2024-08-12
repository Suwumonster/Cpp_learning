#include <iostream>
using namespace std;
int main()
{
    long long T = 0;
    cin >> T;
    while(T--)
    {
        long long n, a, b;
        cin >> n >> a >> b;
        long long ret = 0;
        if(n <= 2)//小于2单独考虑
        {
            ret = a < b?a : b;
        }
        else if(3*a < 2*b)//优先选择双人船
        {
            ret = (n / 2)*a;
            n %= 2;
            if(n != 0)
            {
                ret += min(a, b-a);//边界分类考虑
            }
        }
        else//优先选择三人船
        {
            ret = (n / 3)*b;
            n %= 3;
            if(n == 1)
            {
                ret += min(a, min(b, 2*a-b));//边界分类考虑
            }
            else if(n == 2)
            {
                ret += min(min(3*a-b, a), b);//边界分类考虑
            }
        }
        cout << ret << endl;
    }
    return 0;
}