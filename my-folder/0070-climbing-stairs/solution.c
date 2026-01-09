int step[46];

int climbStairs(int n) {
    step[0] = 0;
    step[1] = 1;
    step[2] = 2;
    if (step[n] != 0) return step[n];
    for (int i = 3; i <= n; i++)
    {
        step[i] = step[i - 1] + step[i - 2];
    }
    return step[n];
}
