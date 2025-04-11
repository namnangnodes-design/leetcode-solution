
class Solution {
public:
    bool memo[10001] = {0};
    int countSymmetricIntegers(int low, int high) {
        createMemo();
        int count = 0;
        for (int i = low; i <= high; i++)
        {
            if (memo[i]) count++;
        }
        return count;
    }

    void createMemo()
    {
        if (memo[11])
        {
            return;
        }
        memo[11] = true;
        memo[22] = true;
        memo[33] = true;
        memo[44] = true;
        memo[55] = true;
        memo[66] = true;
        memo[77] = true;
        memo[88] = true;
        memo[99] = true;
        for (int i = 1001; i < 10000; i++)
        {
            int a = i / 1000;
            int b = i % 1000 / 100;
            int c = (i / 10) % 10;
            int d = i % 10;
            if (a + b == c + d) memo[i] = true;
        }
    }
};
