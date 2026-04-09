class Solution {
public:
    vector<long long> prefix;
    int mN;
    Solution(vector<int>& w) {
        prefix.clear();
        mN = w.size();
        prefix.push_back(w[0]);
        for (int i = 1; i < mN; i++)
        {
            prefix.push_back(prefix.back() + w[i]);
        }
    }
    
    int pickIndex() {
        long long random = rand() % prefix.back() + 1;
        return lower_bound(prefix.begin(), prefix.end(), random) - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
