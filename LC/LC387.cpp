#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = { 0 };
        for (auto ch : s)
        {
            count[ch - 'a']++;
        }
        int i = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (count[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};