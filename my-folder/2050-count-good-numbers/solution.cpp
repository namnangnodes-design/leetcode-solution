class Solution {
public:
    long long pow107(long long base, long long exponent)
    {
        long long ans = 1;
        while (exponent >= 1)
        {
            if (exponent % 2 == 0)
            {
                base = base * base % 1000000007;
                exponent /= 2;
            }
            else
            {
                ans = ans * base % 1000000007;
                exponent--;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long result = 0;
        if (n % 2)
        {
            result = pow107(5, n / 2 + 1) * pow107(4, n / 2);
        }
        else
        {
            result = pow107(5, n / 2) * pow107(4, n / 2);
        }
        return result % 1000000007;
    }
};
