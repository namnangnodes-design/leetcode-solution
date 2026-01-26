class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> preDiff;
        int minDiff = arr[1] - arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            int temp = arr[i] - arr[i - 1];
            preDiff.push_back(temp);
            if (temp < minDiff) minDiff = temp;
        }
        vector<vector<int>> res;
        for (int i = 0; i < preDiff.size(); i++)
        {
            if (preDiff[i] == minDiff) res.push_back({arr[i], arr[i + 1]});
        }
        return res;
    }
};
