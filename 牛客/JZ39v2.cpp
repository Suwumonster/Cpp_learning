// Boyer-Moore 投票算法——数字消消乐（bushi）
// O(N) O(1)
// 想象一下，如果把这些数字当做人种，一个数字和另外一个数字打了起来，同归于尽。
// 最后剩下的是不是人数最多的那种人。
// 这里要满足一个条件：某类人的数目一定要大于总人数的一半。
// 
// 算法步骤：我们选择输入数组中第一个元素作为候选元素candidate，
// 并设置其出现次数为count=1。
// 随后遍历数组。当遇到与candidate相同的元素，count+1;不同的元素，count-1。
// 当count为0的时候，选择下一个元素为候选元素，并且置count=1。
// 遍历到数组的最后，剩下的candidate就是要求的结果。

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        int candidate = numbers[0];
        int count = 1;
        for(int i = 1; i < numbers.size(); i++)
        {
            if(candidate == numbers[i])
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count == 0)
            {
                candidate = numbers[i + 1];
                count = 1;
            }
        }
        return candidate;
    }
};