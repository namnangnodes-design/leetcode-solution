class MapSum {
public:
    struct TrieNode
    {
        TrieNode* next[26];
        int valueI;
        char valueC;
        TrieNode(int i, char c)
        {
            valueI = i;
            valueC = c;
            for (int i = 0; i < 26; i++)
            {
                next[i] = nullptr;
            }
        }
    };

    TrieNode* root;
    unordered_map<string, int> sMap; 
    MapSum() {
        sMap.clear();
        root = new TrieNode(0, ' ');
    }
    
    void insert(string key, int val) {
        TrieNode* cur = root;
        if (sMap.find(key) != sMap.end())
        {
            int old = sMap[key];
            for (int i = 0; i < key.size(); i++)
            {
                cur = cur->next[key[i] - 'a'];
                cur->valueI += val - old; 
            }
        }
        else
        {
            for (int i = 0; i < key.size(); i++)
            {
                if (cur->next[key[i] - 'a'] == nullptr)
                {
                    cur->next[key[i] - 'a'] = new TrieNode(val, key[i]);
                }
                else
                {
                    cur->next[key[i] - 'a']->valueI += val;
                }
                cur = cur->next[key[i] - 'a'];
            }
        }
        sMap[key] = val;
    }
    
    int sum(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (cur->next[prefix[i] - 'a'] == nullptr)
            {
                return 0;
            }
            cur = cur->next[prefix[i] - 'a'];
        }
        return cur->valueI;
    }
};



/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
