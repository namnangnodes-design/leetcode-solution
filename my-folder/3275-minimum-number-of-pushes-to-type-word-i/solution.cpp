class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cMap(26, 0);
        for (int i = 0; i < word.size(); i++)
        {
            cMap[word[i] - 'a']++;
        }
        sort(cMap.begin(), cMap.end(), greater<int>());
        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            res += (1 + i / 8) * cMap[i];
        }
        return res;
    }
};
