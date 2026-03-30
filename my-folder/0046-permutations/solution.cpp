class Solution {
public:
    vector<int> temp;
    vector<bool> visited;
    vector<vector<int>> result;
    void backtrack(int n, vector<int>& nums)
    {
        if (n == nums.size())
        {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited.at(i))
            {
                visited.at(i) = true;
                temp.push_back(nums.at(i));
                backtrack(n + 1, nums);
                temp.pop_back();
                visited.at(i) = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            visited.push_back(false);
        }
        backtrack(0, nums);
        return result;
    }
};
