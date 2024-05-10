#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            while (begin <= end && !(s[begin] >= 'A' && s[begin] <= 'Z' || s[begin] >= 'a' && s[begin] <= 'z'))
            {
                begin++;
            }
            while (begin <= end && !(s[end] >= 'A' && s[end] <= 'Z' || s[end] >= 'a' && s[end] <= 'z'))
            {
                end--;
            }
            if (begin < end)
            {
                swap(s[begin], s[end]);
            }
            begin++;
            end--;
        }
        return s;
    }
};