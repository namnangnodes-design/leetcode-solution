class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        int n = heights.size();
        
        while (volume--) {
            int best = k;
            
            for (int i = k - 1; i >= 0; i--) {
                if (heights[i] < heights[best]) {
                    best = i;
                } else if (heights[i] > heights[best]) {
                    break; 
                }

            }
            
            if (best == k) {
                for (int i = k + 1; i < n; i++) {
                    if (heights[i] < heights[best]) {
                        best = i;
                    } else if (heights[i] > heights[best]) {
                        break; 
                    }
                }
            }
            
            heights[best]++;
        }
        
        return heights;
    }
};
