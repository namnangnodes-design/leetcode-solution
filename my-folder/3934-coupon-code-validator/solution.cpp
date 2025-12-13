class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> ele;
        vector<string> gro;
        vector<string> pha;
        vector<string> res;
        vector<string> result;
        for (int i = 0; i < code.size(); i++)
        {
            string s = businessLine[i];
            string check = code[i];
            if (s == "electronics" && isActive[i])
            {
                bool valid = !check.empty();
                for (int j = 0; j < check.size(); j++)
                {
                    if (!((check[j] >= 'a' && check[j] <= 'z') || (check[j] >= 'A' && check[j] <= 'Z')|| (check[j] >= '0' && check[j] <= '9') || check[j] == '_'))
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid) ele.push_back(code[i]);
            }
            else if (s == "grocery" && isActive[i])
            {                
                bool valid = !check.empty();
                for (int j = 0; j < check.size(); j++)
                {
                    if (!((check[j] >= 'a' && check[j] <= 'z') || (check[j] >= 'A' && check[j] <= 'Z')|| (check[j] >= '0' && check[j] <= '9') || check[j] == '_'))
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid) gro.push_back(code[i]);
            }
            else if (s == "pharmacy" && isActive[i])
            {                
                bool valid = !check.empty();
                for (int j = 0; j < check.size(); j++)
                {
                    if (!((check[j] >= 'a' && check[j] <= 'z') || (check[j] >= 'A' && check[j] <= 'Z')|| (check[j] >= '0' && check[j] <= '9') || check[j] == '_'))
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid) pha.push_back(code[i]);
            }
            else if (s == "restaurant" && isActive[i])
            {                
                bool valid = !check.empty();
                for (int j = 0; j < check.size(); j++)
                {
                    if (!((check[j] >= 'a' && check[j] <= 'z') || (check[j] >= 'A' && check[j] <= 'Z')|| (check[j] >= '0' && check[j] <= '9') || check[j] == '_'))
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid) res.push_back(code[i]);
            }
        }
        sort(ele.begin(), ele.end());
        sort(gro.begin(), gro.end());
        sort(pha.begin(), pha.end());
        sort(res.begin(), res.end());

        if (!ele.empty()) result.insert(result.end(), ele.begin(), ele.end());
        if (!gro.empty()) result.insert(result.end(), gro.begin(), gro.end());
        if (!pha.empty()) result.insert(result.end(), pha.begin(), pha.end());
        if (!res.empty()) result.insert(result.end(), res.begin(), res.end());

        return result;
    }
};
