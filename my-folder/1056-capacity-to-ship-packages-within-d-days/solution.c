
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int left = 0;
    int right = 0;
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > left) left = weights[i];
        right += weights[i];
    }

    while (left < right) {
        int mid = left + (right - left) / 2;
        int requiredDays = 1;
        int currentLoad = 0;

        for (int i = 0; i < weightsSize; i++) {
            if (currentLoad + weights[i] <= mid) {
                currentLoad += weights[i];
            } else {
                requiredDays++;
                currentLoad = weights[i];
            }
        }

        if (requiredDays <= days) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}
