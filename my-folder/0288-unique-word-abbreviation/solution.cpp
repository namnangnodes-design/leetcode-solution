class ValidWordAbbr {
public:
    unordered_map<string, unordered_set<string>> mMap;

    string abr(string s)
    {
        int n = s.size();
        if (n == 2) return s;
        string res;
        res.push_back(s[0]);
        res.append(to_string(n - 2));
        res.push_back(s[n - 1]);
        return res;
    }

    ValidWordAbbr(vector<string>& dictionary) {
        mMap.clear();
        for (string d: dictionary)
        {
            mMap[abr(d)].insert(d);
        }
    }
    
    bool isUnique(string word) {
        for (string w: mMap[abr(word)])
        {
            if (w.compare(word) != 0)
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
