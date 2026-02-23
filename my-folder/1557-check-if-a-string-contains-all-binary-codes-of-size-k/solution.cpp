class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = s.size();
        if (len < k) return false;
        unordered_set<string> sSet;
        for (int i = 0; i <= len - k; i++)
        {
            sSet.insert(s.substr(i, k));
        }
        return sSet.size() >= (1 << k);
    }
};
