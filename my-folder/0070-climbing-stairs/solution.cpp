class Solution {
public:
int result[46];
int climbStairs(int n) {
    result[1] = 1;
    result[2] = 2;
    for (int i = 3; i <= n; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }
    return result[n];
}
};
