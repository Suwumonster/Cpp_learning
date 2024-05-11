#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum;
        sum.reserve(num1.size() > num2.size() ? num1.size() + 1 : num2.size() + 1);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = 0;
        int over = 0;
        while (i < num1.size() || i < num2.size()) {
            int val1 = i < num1.size() ? num1[i] - '0' : 0;
            int val2 = i < num2.size() ? num2[i] - '0' : 0;
            sum.insert(sum.size(), 1, (val1 + val2 + over) % 10 + '0');
            over = (val1 + val2 + over) / 10;
            i++;
        }
        if (over == 1)
        {
            sum.insert(sum.size(), 1, '1');
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};