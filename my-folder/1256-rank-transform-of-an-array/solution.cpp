class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortArr = arr;
        sort(sortArr.begin(), sortArr.end());
        int cur = 1;
        unordered_map<int, int> rankMap;
        for (int a: sortArr)
        {
            if (rankMap.find(a) == rankMap.end())
            {
                rankMap[a] = cur;
                cur++;
            }
        }
        for (int& a: arr)
        {
            a = rankMap[a];
        }
        return arr;
    }
};
