class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum = "";
        int flag = 0;
        auto rit1 = num1.rbegin();
        auto rit2 = num2.rbegin();
        while (rit1 != num1.rend() && rit2 != num2.rend()) {
            if (*rit1 - '0' + *rit2 - '0' + flag > 9) {
                sum.insert(sum.begin(),
                    (*rit1 - '0' + *rit2 - '0' + flag - 10 + '0'));
                flag = 1;
            }
            else {
                sum.insert(sum.begin(), *rit1 - '0' + *rit2 - '0' + flag + '0');
                flag = 0;
            }
            rit1++;
            rit2++;
        }
        while (rit1 != num1.rend()) {
            if (*rit1 - '0' + flag > 9) {
                sum.insert(sum.begin(), *rit1 - '0' + flag - 10 + '0');
                flag = 1;
            }
            else {
                sum.insert(sum.begin(), *rit1 - '0' + flag + '0');
                flag = 0;
            }
            rit1++;
        }
        while (rit2 != num2.rend()) {
            if (*rit2 - '0' + flag > 9) {
                sum.insert(sum.begin(), *rit2 - '0' + flag - 10 + '0');
                flag = 1;
            }
            else {
                sum.insert(sum.begin(), *rit2 - '0' + flag + '0');
                flag = 0;
            }
            rit2++;
        }
        if (flag == 1)
        {
            sum.insert(sum.begin(), flag + '0');
        }
        return sum;
    }
};