class Solution {
public:
    struct Trie
    {
        Trie* next[26];
        bool isWord;
        Trie()
        {
            isWord = false;
            for (int i = 0; i < 26; i++)
            {
                next[i] = nullptr;
            }
        }

        void addWord(string s)
        {
            Trie* cur = this;
            for (int i = 0; i < s.size(); i++)
            {
                if (cur->next[s[i] - 'a'] == nullptr)
                {
                    cur->next[s[i] - 'a'] = new Trie();
                }
                cur = cur->next[s[i] - 'a'];
            }
            cur->isWord = true;
        }

        bool search(string s)
        {
            Trie* cur = this;
            for (int i = 0; i < s.size(); i++)
            {
                if (cur->next[s[i] - 'a'] == nullptr)
                {
                    return false;
                }
                cur = cur->next[s[i] - 'a'];
            }
            return cur->isWord;
        }
    };

    string longestWord(vector<string>& words) {
        string res;
        Trie* root = new Trie();
        for (int i = 0; i < words.size(); i++)
        {
            root->addWord(words[i]);
        }
        for (int i = 0; i < words.size(); i++)
        {
            bool valid = true;
            for (int j = words[i].size()- 1; j > 0; j--)
            {
                if (!root->search(words[i].substr(0, j)))
                {
                    valid = false;
                    break;
                }
            }
            if (valid && (words[i].size() > res.size() || (words[i].size() == res.size() && words[i].compare(res) < 0)))
            {
                res = words[i];
            }
        }
        return res;
    }
};
