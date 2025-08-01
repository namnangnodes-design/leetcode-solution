class Solution {
public:
    vector<vector<int>> pascalTriangle = { {1
        }, {1, 1} };
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (pascalTriangle.size() >= numRows)
        {
            for (int i = 0; i < numRows; i++)
            {
                result.push_back(pascalTriangle[i]);
            }
            return result;
        }
        for (int i = pascalTriangle.size() - 1; i < numRows - 1; i++)
        {
            vector<int> row = { 1 };
            for (int j = 1; j < pascalTriangle[i].size(); j++)
            {
                row.push_back(pascalTriangle[i][j] + pascalTriangle[i][j - 1]);
            }
            row.push_back(1);
            pascalTriangle.push_back(row);
        }
        return pascalTriangle;
    }
};
