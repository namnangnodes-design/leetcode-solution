class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit = -1;
        while (n > 0)
        {
            int curBit = n % 2;
            if (curBit == prevBit) return false;
            prevBit = curBit;
            n /= 2;
        }
        return true;
    }
};
