class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
       int s = nums.size();
       vector<int> blocks(s, 0);
       vector<bool> ans(queries.size(), false);
       int cur = 0;
       for (int i = 1; i < s; i++)
       {
            if (nums[i] - nums[i - 1] > maxDiff)
            {
                cur++;
            }
            blocks[i] = cur;
       } 

       for  (int i = 0; i < queries.size(); i++)
       {
            ans[i] = blocks[queries[i][0]] == blocks[queries[i][1]];
       }

       return ans;
    }
};
