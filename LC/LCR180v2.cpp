//�������ڽⷨ��(sliding window)
//����������������ж�����
//[i, j) ������������ i < j
//i��j��ֻ�������ƶ�����֤�㷨ʱ�临�Ӷ�ΪO(n)
//���������������С������
//��С����߽�i�����ƶ�
//�����ұ߽�j�����ƶ�
//����ʵ��������ͣ�ʹ��sum == target
//ֻ��Ҫ���ϵ���������������Ϳ���
class Solution {//�Ż�v1, ���ӿɶ���
public:
    size_t sum(int x, int y)//����[x, y)���������������������
    {
        size_t ret = 0;
        for(int i = x; i < y; i++)
        {
            ret += i;
        }
        return ret;
    }
    vector<vector<int>> fileCombination(int target) {
        vector<vector<int>> ret;
        int i = 1;
        int j = 2;
        while(i < j && j < target)
        {
            if(sum(i, j) < target)//��������
            {
                j++;
            }
            else if(sum(i, j) > target)//��С����
            {
                i++;
            }
            else//�ҵ�����target������
            {
                vector<int> tmp;
                for(int k = i; k < j; k++)
                {
                    tmp.push_back(k);
                }
                ret.push_back(tmp);
                i++;//�ҵ�֮��Ӧ�õ��������ұ���,ֱ��i >= j (�������˵��û�н���) ���� j == target
            }
        }
        return ret;
    }
};