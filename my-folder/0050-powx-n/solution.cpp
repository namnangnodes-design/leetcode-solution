class Solution {
public:
    double calPow(double base, int exponent, double result)
    {
        if (exponent == 1)
        {
            return result;
        }
        if (exponent % 2 == 0)
        {
            return calPow(base * base, exponent / 2, result * base);
        }
        else
        {
            return calPow(base * base, exponent / 2, result * base * base);
        }
    }

    double myPow(double x, int n) {
        if (x == 0.0) return 0.0;
        if (x == 1.0) return x;
        if (n < 0)
        {
            x = 1.0 / x;
            if (n == -2147483648)
            {
                return calPow(x * x, n / -2, x * x);
            }
            else
            {
                n = -n;
            }
        }
        else if (n == 0)
        {
            return 1.0;
        }
        return calPow(x, n, x);
    }
};
