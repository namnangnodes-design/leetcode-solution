class StreamChecker {
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

    TrieNode* root;
    string suffix;

    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
        {
            insert(words[i]);
        }
    }
    
    void insert(string s)
    {
        int n = s.size();
        TrieNode* cur = root;
        for (int i = n - 1; i >= 0; i--)
        {
            if (cur->next[s[i] - 'a'] == nullptr)
            {
                cur->next[s[i] - 'a'] = new TrieNode();
            }
            cur = cur->next[s[i] - 'a'];
        }
        cur->isWord = true;
    }

    bool query(char letter) {
        suffix.push_back(letter);
        int n = suffix.size();
        if (n == 1) return false;
        TrieNode* cur = root;
        for (int i = n - 1; i >= 0; i--)
        {
            if (cur->next[suffix[i] - 'a'] == nullptr)
            {
                return false;
            }
            cur = cur->next[suffix[i] - 'a'];
            if (cur->isWord) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
