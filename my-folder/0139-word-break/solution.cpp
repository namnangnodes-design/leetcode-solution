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

bool dp(int start)
{
    if (start == mL)
    {
        return true;
    }
    if (memo[start] != -1)
    {
        return memo[start];
    }
    
    Trie* cur = root;
    for (int i = start; i < mL; i++)
    {
        if (cur->next[mS[i] - 'a'] == nullptr)
        {
            break;
        }
        
        cur = cur->next[mS[i] - 'a'];
        
        if (cur->isWord)
        {
            if (dp(i + 1)) 
            {
                return memo[start] = 1;
            }
        }
    }
    
    return memo[start] = 0;
}

    bool wordBreak(string s, vector<string>& wordDict) {
        root = new Trie();
        mS = s;
        mL = s.size();
        for (string w: wordDict)
        {
            add(w);
        }
        memo = vector<int>(mL, -1);
        return dp(0);
    }
};
