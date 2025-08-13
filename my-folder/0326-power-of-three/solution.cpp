class Solution {
public:
    bool isPowerOfThree(int n) {
        int e = log(pow(2, 31) - 1) / log(3);
        int N = pow(3, e);
        return n > 0 && (N % n == 0);
    }
};
