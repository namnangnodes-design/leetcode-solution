class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> nMap;
        int n = nums.size();
        if (n < 3) return -1;
        bool canHave = false;
        for (int i = 0; i < n; i++)
        {
            nMap[nums[i]].push_back(i);
            if (nMap[nums[i]].size() == 3)
            {
                canHave = true;
            }
        }
        if (!canHave) return -1;
        int res = 1000;
        for (auto p: nMap)
        {
            int s = p.second.size();
            if (s < 3) continue;
            for (int i = 2; i < s; i++)
            {
                res = min(res, abs(p.second[i] - p.second[i - 1]) + abs(p.second[i] - p.second[i - 2]) + abs(p.second[i - 2] - p.second[i - 1]));
            }
        }
        return res;
    }
};
