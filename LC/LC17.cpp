class Solution {
    string _numToStr[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    void Combinations(size_t index, string digits, string combStr,vector<string>& totalCombStr)
    {
        if(index >= digits.size())
        {
            totalCombStr.push_back(combStr);
            return;
        }
        int num = digits[index] - '0';
        for(int i = 0; i < _numToStr[num].size(); i++)
        {
            Combinations(index + 1, digits, combStr + _numToStr[num][i], totalCombStr);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> totalCombStr;
        if(digits.size() == 0)
        {
            return totalCombStr;
        }
        Combinations(0, digits, "", totalCombStr);
        return totalCombStr;
    }
};