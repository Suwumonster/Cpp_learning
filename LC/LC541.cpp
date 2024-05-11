#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    void reverserange(string& s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    string reverseStr(string s, int k) {
        int prev = 0;
        int cur = 2 * k - 1;
        while (cur < s.size())
        {
            reverserange(s, prev, cur - k);
            prev += 2 * k;
            cur += 2 * k;
        }
        if (s.size() - 1 > prev && s.size() - 1 - prev + 1 < k)
        {
            reverserange(s, prev, s.size() - 1);
        }
        else if (s.size() - 1 > prev && s.size() - 1 - prev + 1 >= k && s.size() - 1 - prev + 1 < 2 * k)
        {
            reverserange(s, prev, prev + k - 1);
        }
        return s;
    }
};