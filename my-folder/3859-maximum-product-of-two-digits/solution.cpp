class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        char maxC = max(s[0], s[1]);
        char secondC = min(s[0], s[1]);
        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] > maxC)
            {
                secondC = maxC;
                maxC = s[i];
            }
            else if (s[i] > secondC)
            {
                secondC = s[i];
            }
        }
        return (maxC - '0') * (secondC - '0');
        
    }
};
