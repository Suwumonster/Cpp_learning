class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param param string字符串
     * @return string字符串
     */
    string compressString(string param) {
        string ret = "";
        int left = 0;
        int right = 0;
        while (right < param.size()) {

            //找到不同的字符
            while (right < param.size() && param[left] == param[right]) {
                right++;
            }
            
            ret += param[left];//处理字符

            int num = right - left;//处理数字
            if (num != 1) {
                string tmpNum = "";
                while (num > 0) {
                    tmpNum += num % 10 + '0';
                    num /= 10;
                }
                reverse(tmpNum.begin(), tmpNum.end());
                ret += tmpNum;
            }

            left = right;
        }

        return ret;
    }
};