//试探回溯 O（n） O（1） v2
class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        if(array.size() == 0)
        {
            return vector<int>();
        }
        //row的设定界限[rowstart, rowend]
        int rowstart = 0;
        int rowend = array.size() - 1;

        //col的设定界限[colstart, colend]
        int colstart = 0;
        int colend = array[0].size() - 1;

        //当前行列所在下标
        int currow = 0;
        int curcol = 0;

        vector<int> ret;//输出vector

        while(1)
        {
            //左上角
            for(currow = rowstart, curcol = colstart; curcol <= colend; curcol++)//left to right
            {
                ret.push_back(array[currow][curcol]);
            }
            rowstart++;
            if(rowstart > rowend)
            {
                break;
            }

            //右上角
            for(currow = rowstart, curcol = colend; currow <= rowend; currow++)//top to bottom
            {
                ret.push_back(array[currow][curcol]);
            }
            colend--; 
            if(colstart > colend)
            {
                break;
            }

            //右下角
            for(currow = rowend, curcol = colend; curcol >= colstart; curcol--)//right to left
            {
                ret.push_back(array[currow][curcol]);
            }
            rowend--;
            if(rowstart > rowend)
            {
                break;
            }

            //左下角
            for(currow = rowend, curcol = colstart; currow >= rowstart; currow--)//bottom to top
            {
                ret.push_back(array[currow][curcol]);
            }
            colstart++;
            if(colstart > colend)
            {
                break;
            }

        }
       
        return ret;//返回结果
    }
};