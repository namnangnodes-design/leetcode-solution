class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mMap;
        int n = nums.size();
        int q = queries.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++)
        {
            mMap[nums[i]].push_back(i);
        }
        for (auto i: mMap)
        {
            int s = i.second.size();
            if (s == 1)
            {
                continue;
            }
            for (int j = 0; j < s; j++)
            {
                if (j == 0) 
                {
                    res[i.second[j]] = min(i.second[0] + n - i.second[s - 1], i.second[1] - i.second[0]); 
                }
                else if (j == s - 1)
                {
                    res[i.second[j]] = min(i.second[0] + n - i.second[s - 1], i.second[s - 1] - i.second[s - 2]);
                }
                else
                {
                    res[i.second[j]] = min(i.second[j + 1] - i.second[j], i.second[j] - i.second[j - 1]);
                }
            }    
        }
        vector<int> solve;
        for (int i = 0; i < q; i++)
        {
            solve.push_back(res[queries[i]]);
        }
        return solve;
    }
};
