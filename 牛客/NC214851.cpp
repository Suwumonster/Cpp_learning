//找最长非回文子串
//贪心
//判断整个字符串是否为回文字符串
//1.不是    str.size()
//2.是
//    a.所有字符相同             0
//    b.所有字符不相同    str.size() - 1
#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int left = 0;
    int right = str.size() - 1;
    char ch = str[left];
    bool isNotPal = false;
    bool isAllSame = true;
    while(left <= right)
    {
        if(str[left] != str[right])
        {
            isNotPal = true;
            break;
        }
        if(ch != str[left])
        {
            isAllSame = false;
        }
        left++;
        right--;
    }
    if(isNotPal)
    {
        cout << str.size() << endl;
    }
    else
    {
        if(isAllSame)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << str.size() - 1 << endl;    
        }
    }
    return 0;
}