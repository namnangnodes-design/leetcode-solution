class Solution {
public:
bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
        {
            return false;
        }
        int word1map[26];
        int word2map[26];
        for (int i = 0; i < 26; i++)
        {
            word1map[i] = 0;
            word2map[i] = 0;
        }
        for (int i = 0; i < word1.length(); i++)
        {
            word1map[word1[i] - 'a']++;
            word2map[word2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if ((word1map[i] == 0 && word2map[i] != 0) || (word1map[i] != 0 && word2map[i] == 0))
            {
                return false;
            }
        }
        sort(word1map, word1map + 26);
        sort(word2map, word2map + 26);
        for (int i = 0; i < 26; i++)
        {
            if (word1map[i] != word2map[i])
            {
                return false;
            }
        }
        return true;
    }
};
