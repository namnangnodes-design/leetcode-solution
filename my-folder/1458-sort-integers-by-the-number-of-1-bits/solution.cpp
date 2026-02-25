class Solution {
public:
    static bool mCompare (int i, int j) { 
        if (__builtin_popcount(i) < __builtin_popcount(j))
        {
            return true;
        }
        else if (__builtin_popcount(i) > __builtin_popcount(j))
        {
            return false;
        }
        else
        {
            return i < j;
        }

    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), mCompare);
        return arr;
    }
};
