#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

class Sum
{
public:
    Sum()
    {
        _i++;
        _sum += _i;
    }
    static int sums()
    {
        return _sum;
    }
private:
    static int _i;
    static int _sum;
};
int Sum::_i = 0;
int Sum::_sum = 0;
class Solution {
public:
    int Sum_Solution(int n) {
        Sum a[n];
        return Sum::sums();
    }
};