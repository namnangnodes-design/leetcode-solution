class Solution {
public:
    int findComplement(int n) {
        int temp = n;
        int bit = 1;
        while (temp != 0)
        {
            n ^= bit;
            bit <<= 1;
            temp >>= 1;
        }
        return n;
    }
};
