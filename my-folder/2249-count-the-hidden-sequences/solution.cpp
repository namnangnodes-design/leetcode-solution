class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int maxVal = 0;
        int minVal = 0;
        int temp = 0;
        int maxDiff = 0;
        for (int i = 0; i < differences.size(); i++)
        {
            temp += differences[i];
            maxVal = max(maxVal, temp);
            minVal = min(minVal, temp);
            maxDiff = maxVal - minVal;
            if (maxDiff > upper - lower) return 0;
        }
        if (upper - lower - maxDiff + 1 <= 0) return 0;
        return upper - lower - maxDiff + 1;
    }
};
