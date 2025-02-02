class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long total = 0;
            
            for (int i = 0; i < piles.size(); i++) {
                total += (piles[i] + mid - 1) / mid;  // Simplified hours calculation
            }
            
            if (total > h) {
                left = mid + 1;
            } else {
                result = mid;
                right = mid - 1;
            }
        }
        
        return result;
    }
};

