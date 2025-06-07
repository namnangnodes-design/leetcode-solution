class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> mMap;
        for (int i = 0; i < x.size(); i++)
        {
            mMap[x[i]] = max(mMap[x[i]], y[i]);
        }
        if (mMap.size() < 3)
        {
            return -1;
        }
        int first = -1000001;
        int second = -1000001;
        int third = -1000001;
        int firstIndex = -1;
        int secondIndex = -1;
        int thirdIndex = -1;
        for (pair<int, int> i: mMap)
        {
            if (i.second > first)
            {
                first = i.second;
                firstIndex = i.first;
            }
        }
        for (pair<int, int> i : mMap)
        {
            if (i.second > second && i.first != firstIndex)
            {
                second = i.second;
                secondIndex = i.first;
            }
        }
        for (pair<int, int> i : mMap)
        {
            if (i.second > third && i.first != firstIndex && i.first != secondIndex)
            {
                third = i.second;
                thirdIndex = i.first;
            }
        }
        return first + second + third;
    }
}; 
