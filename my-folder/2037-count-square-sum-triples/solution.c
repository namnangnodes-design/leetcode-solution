int countTriples(int n) {
    float count = 0.0;
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a < i; a++)
        {
            for (int b = 1; b < i; b++)
            {
                if (a * a + b * b == i * i)
                {
                    count += a == b ? 0.5 : 1.0;
                }
            }
        }
    }
    return (int) count;
}
