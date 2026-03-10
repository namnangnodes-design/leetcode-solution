class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> sM;
        for (int i = 0; i < n; i++)
        {
            sM[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            sM[t[i]]--;
            if (sM[t[i]] < 0)
            {
                return "";
            }
        }
        int mL = n;
        int l = 0;
        int r = n - 1;
        string res = s;
        while (r > 0)
        {
            sM[s[r]]--;
            if (sM[s[r]] >= 0)
            {
                res.pop_back();
                mL = min(r - l, mL);
                r--;
            }
            else
            {
                sM[s[r]]++;
                break;
            }
        }
        string cur = res;
        while (r - l + 1 >= t.size() && r < n)
        {
            sM[s[l]]--;
            cur.erase(0, 1);
            l++;
            if (sM[s[l - 1]] >= 0)
            {
                if (mL > r - l + 1)
                {
                    mL = r - l + 1;
                    res = cur;
                }
            }
            else
            {
                while (r < n)
                {
                    r++;
                    if (r == n) break;
                    sM[s[r]]++;
                    cur.push_back(s[r]);
                    if (s[r] == s[l - 1]) 
                    {
                        if (mL > r - l + 1)
                        {
                            mL = r - l + 1;
                            res = cur;
                        }                        
                        break;
                    }
                }
            }
        }
        return res;
    }
};
