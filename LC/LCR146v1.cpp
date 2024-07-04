//试探回溯 O（n） O（1）
//设置了额外两个函数 isOverLimit turn
//isOverLimit用来测试 当前行 或者 当前列 有没有超出 设定的界限
//turn用来移动当前行或当前列 相当于 走一步，走一步进行试探
class Solution {
public:
    bool isOverLimit(int start, int end, int x)//检测x是否超出设定的界限[start, end]
    {
        if(start <= x && x <= end)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void turn(int& row, int& col)//移动 走一步
    {
        if(type == 0)//右
        {
            col++;
        }
        else if(type == 1)//下
        {
            row++;
        }
        else if(type == 2)//左
        {
            col--;
        }
        else if(type == 3)//上
        {
            row--;
        }
    }
    vector<int> spiralArray(vector<vector<int>>& array) {

        //row的设定界限[rowstart, rowend] 会因为 type 的改变而改变
        //走到最右边（colend） 只能 往下走了 那么 可以遍历的最上面一行(rowstart)就不能再进行遍历 rowstart++
        //走到最左边（colstart） 只能 往上走了 那么 可以遍历的最下面一行(rowend)就不能再进行遍历 rowend--
        int rowstart = 0;
        int rowend = array.size() - 1;

        if(rowend == -1)//array空 返回空vector就行
        {
            return vector<int>();
        }

        //col的设定界限[colstart, colend] 会因为 type 的改变而改变
        //走到最下边（rowend） 只能 往左走了 那么 可以遍历的最右边一行(colend)就不能再进行遍历 colend--
        //走到最上边（rowstart） 只能 往右走了 那么 可以遍历的最左边一行(colstart)就不能再进行遍历 colstart++
        int colstart = 0;
        int colend = array[0].size() - 1;

        //当前行列所在下标
        int currow = 0;
        int curcol = 0;

        //用于保存 turn之后 当前行列 是否超出设定界限的结果 
        bool rowOver = false;
        bool colOver = false;

        vector<int> ret;//输出vector

        while(rowstart <= rowend && colstart <= colend)
        {
            ret.push_back(array[currow][curcol]);//push  array[currow][curcol] 到 输出vector
            turn(currow, curcol);//试探 走一步
            bool rowOver = isOverLimit(rowstart, rowend, currow);
            bool colOver = isOverLimit(colstart, colend, curcol);
            if(rowOver)//currow越界了
            {
                if(type == 1)//currow 越界原因 上一次是往下走导致越界
                {
                    currow--;//回溯
                    type = 2;//改变试探朝向
                    colend--;//改变边界
                }
                else if(type == 3)//currow 越界原因
                {
                    currow++;//回溯
                    type = 0;//改变试探朝向
                    colstart++;//改变边界
                }
                turn(currow, curcol);//回溯后根据type走一步
            }
            else if(colOver)//curcol越界了
            {
                if(type == 0)//curcol 越界原因
                {
                    curcol--;//回溯
                    type = 1;//改变试探朝向
                    rowstart++;//改变边界
                }
                else if(type == 2)//curcol 越界原因
                {
                    curcol++;//回溯
                    type = 3;//改变试探朝向
                    rowend--;//改变边界
                }
                turn(currow, curcol);//回溯后根据type走一步
            }
        }

        return ret;//返回结果
    }
    int type = 0;//试探朝向 用来确定移动的方式 右、下、左、上
};