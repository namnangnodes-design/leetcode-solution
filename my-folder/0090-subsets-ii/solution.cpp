class Solution {
public:
    vector<int> mNums;
    vector<vector<int>> res;
    vector<int> temp;
    int n;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        mNums = nums;
        n = nums.size();
        res.clear();
        temp.clear();
        backtracking(0);
        return res;
    }

    void backtracking(int s)
    {
        if (s == n)
        {
            res.push_back(temp);
            return;
        }
        temp.push_back(mNums[s]);
        backtracking(s + 1);
        temp.pop_back();
        while (s + 1 < mNums.size() && mNums[s] == mNums[s + 1]) {
            s++;
        }
        backtracking(s + 1);
    }
};
