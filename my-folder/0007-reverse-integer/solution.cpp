class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648)
        {
            return 0;
        }
        if (x == 0)
        {
            return 0;
        }
        bool minusSign = false;
        if (x < 0)
        {
            x *= -1;
            minusSign = true;
        }
        while (x % 10 == 0)
        {
            x /= 10;
        }
        string s = to_string(x);
        for (int i = 0, j = s.length() - 1; i < j; i++, j--)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        long long result = minusSign ? atol(s.c_str()) * -1 : atol(s.c_str());
        int minMax = pow(2, 31) - 1;
        if (result <= minMax * -1 || result >= minMax)
        {
            return 0;
        }
        else
        {
            return result;
        }
    }
};
