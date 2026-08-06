class Solution {
public:
    int toNumber(char c)
    {
        switch(c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {
        
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && toNumber(s[i]) < toNumber(s[i + 1]))
            {
                res -= toNumber(s[i]);
            }
            else
            {
                res += toNumber(s[i]);
            }
        }
        return res;
    }
};
