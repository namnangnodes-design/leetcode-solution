class Solution {
public:
    struct Trie
    {
        Trie* next[26];
        bool isWord;

        Trie()
        {
            for (int i = 0; i < 26; i++)
            {
                next[i] = nullptr;
            }
            isWord = false;
        }
    };

    Trie* root;
    vector<int> memo;
    int mL;
    string mS;
    vector<string> mRes;

    void add(string s)
    {
        int n = s.size();
        Trie* cur = root;
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

    void dp(int start, string s)
    {
        if (start == mL)
        {
            mRes.push_back(s);
            return;
        }
        
        Trie* cur = root;
        if (start != 0) s.push_back(' ');
        for (int i = start; i < mL; i++)
        {
            if (cur->next[mS[i] - 'a'] == nullptr)
            {
                break;
            }
            s.push_back(mS[i]);
            cur = cur->next[mS[i] - 'a'];
            
            if (cur->isWord)
            {
                dp(i + 1, s);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = new Trie();
        mS = s;
        mL = s.size();
        mRes.clear();
        for (string w: wordDict)
        {
            add(w);
        }
        memo = vector<int>(mL, -1);
        dp(0, "");
        return mRes;
    }
};
