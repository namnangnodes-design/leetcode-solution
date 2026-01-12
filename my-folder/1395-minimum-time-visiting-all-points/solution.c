int max(int a, int b)
{
    return a > b ? a : b;
}

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int res = 0;
    for (int i = 1; i < pointsSize; i++)
    {
        int moveStraight = abs(abs(points[i][0] - points[i - 1][0]) - abs(points[i][1] - points[i - 1][1]));
        int moveDiagonally  = max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1])) - moveStraight;
        res += moveStraight + moveDiagonally;
    }
    return res;
}
