class Solution {
public:
    string raddStrings(string num1, string num2) {
        string sum;
        sum.reserve(num1.size() > num2.size() ? num1.size() + 1
            : num2.size() + 1);
        int i = 0;
        int over = 0;
        while (i < num1.size() || i < num2.size()) {
            int val1 = i < num1.size() ? num1[i] - '0' : 0;
            int val2 = i < num2.size() ? num2[i] - '0' : 0;
            sum.insert(sum.size(), 1, (val1 + val2 + over) % 10 + '0');
            over = (val1 + val2 + over) / 10;
            i++;
        }
        if (over == 1) {
            sum.insert(sum.size(), 1, '1');
        }
        return sum;
    }
    string multiply(string num1, string num2) {
        string ret;
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        ret.reserve(num1.size() + num2.size());
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int over = 0;
        int i = 0;
        int j = 0;
        string tmp;
        tmp.reserve(ret.size());
        for (i = 0; i < num1.size(); i++) {
            tmp = "";
            over = 0;
            for (j = 0; j < num2.size(); j++) {
                int val1 = num1[i] - '0';
                int val2 = num2[j] - '0';
                tmp.insert(tmp.size(), 1, (val1 * val2 + over) % 10 + '0');
                over = (val1 * val2 + over) / 10;
            }
            if (over > 0) {
                tmp.insert(tmp.size(), 1, over + '0');
            }
            tmp.insert(0, i, '0');
            ret = raddStrings(ret, tmp);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};