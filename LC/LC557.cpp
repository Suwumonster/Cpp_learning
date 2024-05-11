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
    string reverseWords(string s) {
        int pos = s.find(' ');
        int prevpos = 0;
        while (pos != string::npos)
        {
            reverserange(s, prevpos, pos - 1);
            prevpos = pos + 1;
            pos = s.find(' ', pos + 1);
        }
        reverserange(s, prevpos, s.size() - 1);
        return s;
    }
};