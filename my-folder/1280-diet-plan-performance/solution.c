int dietPlanPerformance(int* calories, int caloriesSize, int k, int lower, int upper) {
    if (caloriesSize < k)
    {
        long long int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += calories[i]; 
        }
        if (sum < lower)
        {
            return 1;
        }
        else if (sum > upper)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    long long int sum = 0;
    int point = 0;
    for (int i = 0; i < k; i++)
    {
        sum += calories[i];
    }
    if (sum < lower)
    {
        point--;
    }
    else if (sum > upper)
    {
        point++;
    }
    for (int i = k; i < caloriesSize; i++)
    {
        sum += calories[i] - calories[i - k];
        if (sum < lower)
        {
            point--;
        }
        else if (sum > upper)
        {
            point++;
        }
    }
    return point;
}
