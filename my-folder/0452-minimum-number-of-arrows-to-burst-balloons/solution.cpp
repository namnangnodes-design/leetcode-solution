
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int, int>> pairVec;
        for (int i = 0; i < points.size(); i++)
        {
            pair<int, int> temp = { points[i][1], points[i][0] };
            pairVec.push_back(temp);
        }
        sort(pairVec.begin(), pairVec.end());
        int lastEnd = pairVec[0].first;
        int result = 1;
        for (int i = 1; i < pairVec.size(); i++)
        {
            if (pairVec[i].second <= lastEnd)
            {
                continue;
            }
            result++;
            lastEnd = pairVec[i].first;
        }
        return result;
    }
};
