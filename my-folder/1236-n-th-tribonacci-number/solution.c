int arr[38];

int tribonacci(int n) {
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    if (arr[n] != 0) return arr[n];
    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[n];
}
