class Solution {
public:
    static bool mCompare(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mCompare);
        vector<vector<int>> res;
        int iStart = intervals[0][0];
        int iEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (iEnd >= intervals[i][0])
            {
                iEnd = max(iEnd, intervals[i][1]);
                iStart = min(iStart, intervals[i][0]);
            }
            else
            {
                res.push_back({iStart, iEnd});
                iStart = intervals[i][0];
                iEnd = intervals[i][1];
            }
        }  
        res.push_back({iStart, iEnd});
        return res; 
    }
};
