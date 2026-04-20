class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> res;
        int n = words.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j) continue;
                if (words[i].find(words[j]) != string::npos)
                {
                    res.insert(words[j]);
                }
                if (words[j].find(words[i]) != string::npos)
                {
                    res.insert(words[i]);
                }
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
