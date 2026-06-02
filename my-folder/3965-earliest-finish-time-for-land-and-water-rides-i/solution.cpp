class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int res = 10000;
        int n1 = landStartTime.size();
        int n2 = waterStartTime.size();
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (landStartTime[i] + landDuration[i] <= waterStartTime[j])
                {
                    res = min(res, waterStartTime[j] + waterDuration[j]);
                }
                else if (waterStartTime[j] + waterDuration[j] <= landStartTime[i])
                {
                    res = min(res, landStartTime[i] + landDuration[i]);
                }
                else
                {
                    res = min(res, min(waterStartTime[j] + waterDuration[j] + landDuration[i], landStartTime[i] + landDuration[i] + waterDuration[j]));
                }
            }
        }
        return res;
    }
};
