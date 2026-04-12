class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> mins;
        vector<int> res;
        mins.push_back(obstacles[0]);
        res.push_back(1);
        for (int i = 1; i < n; i++)
        {
            int o = obstacles[i];
            if (mins.back() <= o)
            {
                mins.push_back(o);
                res.push_back(mins.size());
            }
            else
            {
                int index = upper_bound(mins.begin(), mins.end(), o) - mins.begin();
                mins[index] = o;
                res.push_back(index + 1);
            }
        }
        return res;
    }
};
