class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed.at(i) == 1 || ((i != 0 && flowerbed.at(i - 1) == 1) || (i != flowerbed.size() - 1 && flowerbed.at(i + 1) == 1))) {
                continue;
            }
            flowerbed.at(i) = 1;
            if (--n == 0) {
                return true;
            }
        }
        return false;
    }
};
