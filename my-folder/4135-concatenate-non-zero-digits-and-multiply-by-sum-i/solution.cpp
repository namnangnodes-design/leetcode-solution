class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long sum = 0;
        long long x = 0;
        int cur = 0;
        for (int i = s.size() - 1; i > -1; i--)
        {
            if (s[i] != '0')
            {
                sum += s[i] - '0';
                x += (s[i] - '0') * pow(10, cur); 
                cur++;
            }
        }
        return x * sum;
    }
};
