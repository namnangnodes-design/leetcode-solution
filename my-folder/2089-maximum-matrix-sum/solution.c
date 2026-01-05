long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    int negativeCount = 0;
    int minAbs = INT_MAX;
    long long res = 0;
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            int temp = matrix[i][j];
            res += abs(temp);
            if (temp < 0) negativeCount++;
            minAbs = minAbs < abs(temp) ? minAbs : abs(temp);
        }
    }
    if (negativeCount % 2 == 1)
    {
        res -= minAbs * 2;
    }
    return res;
}
