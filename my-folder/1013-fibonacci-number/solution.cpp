class Solution {
public:
    int mA[31]; 
    int fib(int n) {
        if (n == 0)
        {
            mA[0] = 0;
            return mA[0];
        }
        else if (n == 1)
        {
            mA[1] = 1;
            return mA[1];
        }
        else if (mA[n] != 0)
        {
            return mA[n];
        }
        mA[n] = fib(n - 1) + fib(n - 2);
        return mA[n];
    }
};
