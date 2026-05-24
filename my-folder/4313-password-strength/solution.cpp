class Solution {
public:
    int passwordStrength(string password) {
        int res = 0;
        unordered_map<char, int> cMap;
        for (int i = 0; i < password.size(); i++)
        {
            char c = password[i];
            cMap[c]++;
            if (cMap[c] > 1)
            {
                continue;
            }
            if (c >= 'a' && c <= 'z')
            {
                res++;                
            }
            else if (c >= 'A' && c <= 'Z')
            {
                res += 2;
            }
            else if (c >= '0' && c <= '9')
            {
                res += 3;
            }
            else if (c == '!' || c == '@' || c == '#' || c == '$')
            {
                res += 5;
            }
        }
        return res;
    }
};
