class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vv.resize(numRows, vector<int>());
        for(int i = 0; i < numRows; i++)
        {
            vv[i].resize(i + 1, 0);
        }

        for(int i = 0; i < numRows; i++)
        {
            vv[i][0] = vv[i][vv[i].size() - 1] = 1;
            for(int j = 0; j < vv[i].size(); j++)
            {
                if(vv[i][j] == 0)
                {
                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
                }
            }
        }
        return vv;
    }
};