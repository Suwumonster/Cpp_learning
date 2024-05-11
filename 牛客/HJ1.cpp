#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    str.reserve(5000);
    getline(cin, str);
    int pos = str.rfind(' ');
    if (pos != -1)
    {
        cout << str.size() - pos - 1;
    }
    else
    {
        cout << str.size();
    }
    return 0;
}
