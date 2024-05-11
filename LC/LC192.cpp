#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int myAtoi(string str)
    {
        int i = 0;
        long int sum = 0;
        int sign = 0;//0为正数，1为负数
        bool isreceivedsign = false;//是否已经收到了正负号
        bool isskip = true;//是否需要跳过空格
        long int over = pow(2, 31) - 1;//溢出上限
        for (i = 0; i < str.size(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')//数字
            {
                sum = sum * 10 + str[i] - '0';
                isskip = false;//收到数字就不需要跳过空格了
                isreceivedsign = true;//默认接受到＋
                if (sign == 0 && sum > over)
                {
                    sum = over;
                    break;
                }
                if (sign == 1 && sum > (over + 1))
                {
                    sum = over + 1;
                }
            }
            else
            {
                if (isskip == true && str[i] == ' ')
                {
                    continue;
                }
                else if (str[i] == '-' || str[i] == '+')
                {
                    isskip = false;//收到正负号不需要跳过空格
                    if (isreceivedsign == false && str[i] == '-')
                    {
                        sign = 1;
                        isreceivedsign = true;
                    }
                    else if (isreceivedsign == false && str[i] == '+')
                    {
                        isreceivedsign = true;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        if (sign == 1)
        {
            sum = -sum;
        }
        return sum;
    }
};