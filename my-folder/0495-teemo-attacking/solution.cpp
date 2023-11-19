class Solution {
public:
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
        int last = timeSeries.at(0) + duration - 1;
        int time = 0;
        for (int i = 1; i < timeSeries.size(); i++) {
            if (last >= timeSeries.at(i)) {
                time += timeSeries.at(i) - timeSeries.at(i - 1);
            }
            else {
                time += duration;
            }
            last = timeSeries.at(i) + duration - 1;
        }
        return time + duration;
    }
};
