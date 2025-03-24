class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i <= numRows; i++)
        {
            if (i == 0)
            {
                result.push_back({ 1 });
            }
            else if (i == 1)
            {
                result.push_back({ 1, 1 });
            }
            else
            {
                vector<int> temp;
                temp.push_back(1);
                for (int j = 1; j < result[i - 1].size(); j++)
                {
                    temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
                }
                temp.push_back(1);
                result.push_back(temp);
            }
        }
        return result[numRows];
    }
};
