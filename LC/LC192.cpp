#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int myAtoi(string str)
    {
        int i = 0;
        long int sum = 0;
        int sign = 0;//0Ϊ������1Ϊ����
        bool isreceivedsign = false;//�Ƿ��Ѿ��յ���������
        bool isskip = true;//�Ƿ���Ҫ�����ո�
        long int over = pow(2, 31) - 1;//�������
        for (i = 0; i < str.size(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')//����
            {
                sum = sum * 10 + str[i] - '0';
                isskip = false;//�յ����־Ͳ���Ҫ�����ո���
                isreceivedsign = true;//Ĭ�Ͻ��ܵ���
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
                    isskip = false;//�յ������Ų���Ҫ�����ո�
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