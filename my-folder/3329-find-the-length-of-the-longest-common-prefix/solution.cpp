class Solution {
public:
    struct Trie
    {
        Trie *next[10];
        Trie()
        {
            for (int i = 0; i < 10; i++)
            {
                next[i] = 0;
            }
        }

        void add(int i)
        {
            string s = to_string(i);
            Trie* cur = this;
            for (int i = 0; i < s.size(); i++)
            {
                if (cur->next[s[i] - '0'] == nullptr)
                {
                    cur->next[s[i] - '0'] = new Trie();                    
                }
                cur = cur->next[s[i] - '0'];
            } 
        }

        int check(int i)
        {
            string s = to_string(i);
            Trie* cur = this;
            for (int i = 0; i < s.size(); i++)
            {
                if (cur->next[s[i] - '0'] == nullptr)
                {
                    return i;                  
                }
                cur = cur->next[s[i] - '0'];
            }
            return s.size(); 
        }
    };

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* root = new Trie();
        for (int i = 0; i < arr1.size(); i++)
        {
            root->add(arr1[i]);
        }
        int res = 0;
        for (int i = 0; i < arr2.size(); i++)
        {
            res = max(res, root->check(arr2[i]));
        }
        return res;
    }
};
