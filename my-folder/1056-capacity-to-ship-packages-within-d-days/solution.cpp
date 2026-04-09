class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        int left = *std::max_element(weights.begin(), weights.end());
        int right = std::accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool canShip(const std::vector<int>& weights, int days, int capacity) {
        int currentLoad = 0;
        int requiredDays = 1;

        for (int weight : weights) {
            if (currentLoad + weight <= capacity) {
                currentLoad += weight;
            } else {
                requiredDays++;
                currentLoad = weight;
            }
        }

        return requiredDays <= days;
    }
};

