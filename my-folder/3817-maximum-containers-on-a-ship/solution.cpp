
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        return n * n * w >= maxWeight ? maxWeight / w : n * n;
    }
}; 
