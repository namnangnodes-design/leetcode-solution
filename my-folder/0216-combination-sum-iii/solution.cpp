class Solution {
public:
    vector<bool> visited;
    vector<int> temp;
    vector<vector<int>> result;
    int mN, mK, mCount;
    void backtrack(int total, int count, int cur)
    {
        if ((count == mK && total < mN) || total > mN)
        {
            return;
        }
        else if (count == mK && total == mN)
        {
            result.push_back(temp);
        }
        for (int i = cur + 1; i <= 9; i++)
        {
            temp.push_back(i);
            backtrack(total + i, count + 1, i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        mN = n;
        mK = k;
        backtrack(0, 0, 0);
        return result;
    }
};
