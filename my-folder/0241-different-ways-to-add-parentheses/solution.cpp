class Solution {
public:
    unordered_map <string, vector<int>> mMemo;
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;
        int n = exp.size();
        if (mMemo.count(exp)) return mMemo[exp];
        if (exp.empty()) return res;
        if (n < 3 && isdigit(exp[0]))
        {
            res.push_back(stoi(exp));
            return res;
        }
        for (int i = 0; i < n; i++)
        {
            if (isdigit(exp[i])) continue;
            vector<int> ls = diffWaysToCompute(exp.substr(0, i));
            vector<int> rs = diffWaysToCompute(exp.substr(i + 1));
            for (int l: ls)
            {
                for (int r: rs)
                {
                    if (exp[i] == '+')
                    {
                        res.push_back(l + r);
                    }
                    if (exp[i] == '-')
                    {
                        res.push_back(l - r);
                    }
                    if (exp[i] == '*')
                    {
                        res.push_back(l * r);
                    }
                }
            }
        }
        mMemo[exp] = res; 
        return res;
    }
};
