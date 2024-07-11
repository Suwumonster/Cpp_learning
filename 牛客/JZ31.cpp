class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        int pushIndex = 0;
        int popIndex = 0;
        stack<int> st;
        for (pushIndex = 0; pushIndex < pushV.size() &&
                popIndex < popV.size(); pushIndex++) {
            while (!st.empty() && st.top() == popV[popIndex]) {
                st.pop();
                popIndex++;
            }
            if (pushV[pushIndex] != popV[popIndex]) {
                st.push(pushV[pushIndex]);
            } else if (pushV[pushIndex] == popV[popIndex]) {
                popIndex++;
            }
        }
        while (!st.empty() && st.top() == popV[popIndex]) {
            st.pop();
            popIndex++;
        }
        if(st.empty())
        {
            return true;
        }
        else {
            return false;
        }
    }
};