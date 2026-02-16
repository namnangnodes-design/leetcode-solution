class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        size_t maxSize = words.size();
        for (int i = 0; i < words.size(); i++)
        {
            maxSize = max(words[i].size(), maxSize);
        }
        while (words.size() < maxSize) words.push_back({" "});
        for (int i = 1; i < words.size(); i++)
        {
            while (words[i].size() < words[0].size()) words[i].push_back(' ');
        }
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};
