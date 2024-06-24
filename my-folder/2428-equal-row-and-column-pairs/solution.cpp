class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
               vector<string> rowVec;
    vector<string> colVec;
    for (int i = 0; i < grid.size(); i++)
    {
        string rowStr = "";
        string colStr = "";
        for (int j = 0; j < grid.size(); j++)
        {
            rowStr.append(to_string(grid[i][j]) + ",");
            colStr.append(to_string(grid[j][i]) + ",");
        }
        rowVec.push_back(rowStr);
        colVec.push_back(colStr);
    }
    int result = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            if (rowVec[i] == colVec[j])
            {
                result++;
            }
        }
    }
    return result;
    }
};
