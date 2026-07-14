#include <vector>
#include <cstring>

using namespace std;

// Đặt mảng memo ở ngoài class để tránh cấp phát lại nhiều lần
int memo[201][201][201];

class Solution {
private:
    int MOD = 1000000007;
    int n;

    // Tự viết GCD tối giản bằng thuật toán Euclid giúp chạy siêu nhanh
    inline int mGcd(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    // Truyền nums bằng tham chiếu hằng (&) để tránh copy bộ nhớ
    int dp(int i, int gcd1, int gcd2, const vector<int>& nums) {
        if (i == n) {
            return (gcd1 == gcd2 && gcd1 > 0) ? 1 : 0;
        }

        if (memo[i][gcd1][gcd2] != -1) {
            return memo[i][gcd1][gcd2];
        }

        // Lựa chọn 1: Bỏ qua
        long long res = dp(i + 1, gcd1, gcd2, nums);
        
        // Lựa chọn 2: Vào nhóm 1
        res = (res + dp(i + 1, mGcd(gcd1, nums[i]), gcd2, nums)) % MOD;
        
        // Lựa chọn 3: Vào nhóm 2
        res = (res + dp(i + 1, gcd1, mGcd(gcd2, nums[i]), nums)) % MOD;

        return memo[i][gcd1][gcd2] = res;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        // Chỉ reset lại mảng memo về -1 (memset cực kỳ nhanh)
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, 0, nums);
    }
};
