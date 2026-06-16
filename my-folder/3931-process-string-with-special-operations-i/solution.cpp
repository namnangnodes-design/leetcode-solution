class Solution {
public:
    string processStr(string s) {
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            switch(c)
            {
                case '*':
                    if (res.size() > 0) res.pop_back();
                    break;
                case '#':
                    res.append(res);
                    break;
                case '%':
                    reverse(res.begin(), res.end());
                    break;
                default:
                    res.push_back(c);
            }
        }
        return res;
    }
};
