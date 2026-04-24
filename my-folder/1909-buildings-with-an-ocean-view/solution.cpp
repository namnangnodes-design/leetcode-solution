class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            while (!res.empty())
            {
                if (heights[i] >= heights[res.back()])
                {
                    res.pop_back();
                }
                else
                {
                    break;
                }
            }
            res.push_back(i);
        }
        return res;
    }
};
