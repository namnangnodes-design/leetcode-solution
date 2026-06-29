class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (int i = 0; i < patterns.size(); i++)
        {
            if (word.find(patterns[i]) != std::string::npos)
            {
                res++;
            }
        }
        return res;
    }
};
