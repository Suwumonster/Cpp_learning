class Solution {
public:
    bool isPalindrome(string s) {
        for (auto& ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                ch += 32;
            }
        }
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            start = s.find_first_of("abcdefghijklmnopqrstuvwxyz1234567890", start);
            end = s.find_last_of("abcdefghijklmnopqrstuvwxyz1234567890", end);
            if (start != string::npos && end != string::npos && s[start] != s[end]) {
                return false;
            }
            start = start + 1;
            end = end - 1;
        }
        return true;
    }
};