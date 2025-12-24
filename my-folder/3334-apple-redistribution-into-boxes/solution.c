int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int sum = 0;
    int bucket[51];
    int max = 0;
    for (int i = 0; i < appleSize; i++)
    {
        sum += apple[i];
    }
    for (int i = 0; i < capacitySize; i++)
    {
        bucket[capacity[i]]++;
    }
    int index = 0;
    for (int i = 50; i >= 1; i--)
    {
        while (bucket[i] > 0)
        {
            capacity[index] = i;
            index++;
            bucket[i]--;
        }
    }
    for (int i = 0; i < capacitySize; i++)
    {
        sum -= capacity[i];
        if (sum <= 0) return i + 1;
    }
    return 1;
}
