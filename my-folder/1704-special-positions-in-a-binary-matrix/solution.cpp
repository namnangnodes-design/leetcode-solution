class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            bool rowHave1 = false;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1 && !rowHave1)
                {
                    rowHave1 = true;
                    bool valid = true;
                    for (int k = 0; k < m; k++)
                    {
                        if (k == i)
                        {
                            continue;
                        }
                        if (mat[k][j] == 1)
                        {
                            valid = false;
                            break;
                        }
                    }
                    for (int k = j + 1; k < n; k++)
                    {
                        if (mat[i][k] == 1)
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) 
                    {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
