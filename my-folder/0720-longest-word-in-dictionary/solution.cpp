class Solution {
public:
    struct TrieNode
    {
        TrieNode* next[26];
        bool isWord;

        TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                next[i] = nullptr;
            }
            isWord = false;
        }
    };

    TrieNode* root = nullptr;

    void insert(string s)
    {
        TrieNode* cur = root;
        for (int i = 0; i < s.size(); i++)        
        {
            if (cur->next[s[i] - 'a'] == nullptr)
            {
                cur->next[s[i] - 'a'] = new TrieNode();
            }
            cur = cur->next[s[i] - 'a'];
        }
        cur->isWord = true;
    }

    string longestWord(vector<string>& words) {
        int n = words.size();
        string res = "";
        if (n == 0) return res;
        root = new TrieNode();
        sort(words.begin(), words.end());
        for (int i = 0; i < n; i++)
        {
            insert(words[i]);
        }
        for (int i = 0; i < n; i++)
        {
            string s1 = words[i];
            bool created = true;
            TrieNode* cur = root;
            for (int j = 0; j < s1.size() - 1; j++)
            {
                cur = cur->next[s1[j] - 'a'];
                if (!cur->isWord)
                {
                    created = false;
                    break;
                }
            }
            if (created && s1.size() > res.size()) res = s1;
        }
        return res;
    }
};
