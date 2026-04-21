class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int m = sentence.size();
        int n = searchWord.size();
        int word = 0;
        for (int i = 0; i < m; i++)
        {
            if (i != 0 && sentence[i - 1] != ' ') continue;
            word++; 
            if (searchWord[0] == sentence[i])
            {
                string s1 = sentence.substr(i, m - i + 1);
                bool match = true;
                for (int j = 0; j < n; j++)
                {
                    if (s1[j] != searchWord[j])
                    {
                        match = false;
                        break;
                    }
                }
                if (match) return word;
            }
        }
        return -1;
    }
};
