class Solution {//一维转二维计算
public:
    vector<int> statisticalResult(vector<int>& arrayA) {//O(n) O(1) 
        int sz = arrayA.size();
        vector<int> ret(sz, 1);
        int upperTriangularProduct = 1;
        int underTriangularProduct = 1;

        for(int i = 1; i < sz; i++)//计算下三角
        {
            ret[i] = underTriangularProduct * arrayA[i - 1];
            underTriangularProduct = ret[i];
        }
        for(int i = sz - 2; i >= 0; i--)//计算上三角
        {
            upperTriangularProduct *= arrayA[i + 1];
            ret[i] *= upperTriangularProduct;
        }
        return ret;
    }
};