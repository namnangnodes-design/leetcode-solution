class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_set<string> res, seen;
        if (n < 11) return {};
        for (size_t i = 0; i <= n - 10; i++)
        {
            string s1 = s.substr(i, 10);
            if (seen.find(s1) != res.end()) res.insert(s1);
            seen.insert(s1);
        }
        
        return vector<string>(res.begin(), res.end());
    }
};
