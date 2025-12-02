class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MODULO = 1000000007;
        long long res = 0;
        unordered_map<int, int> ys;

        // Count the frequency of each y-coordinate
        for (const auto& point : points) {
            int y = point[1];
            ys[y]++;
        }

        long long sumOfLines = 0;
        unordered_map<int, long long> lineCounts;

        // Calculate the number of lines for each y-coordinate and total sum
        for (const auto& entry : ys) {
            long long count = entry.second;
            lineCounts[entry.first] = (count * (count - 1) / 2) % MODULO;
            sumOfLines = (sumOfLines + lineCounts[entry.first]) % MODULO;
        }

        // Calculate the total number of trapezoids
        for (const auto& entry : lineCounts) {
            long long count = entry.second;
            res = (res + count * ((sumOfLines - count + MODULO) % MODULO)) % MODULO;
        }

        // Since each trapezoid is counted twice, divide by 2
        return (res * modInverse(2, MODULO)) % MODULO;
    }

private:
    // Function to calculate modular inverse using Fermat's Little Theorem
    long long modInverse(long long a, long long m) {
        return pow(a, m - 2, m);
    }

    // Fast exponentiation function
    long long pow(long long base, long long exp, long long mod) {
        long long result = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            exp = exp >> 1;
            base = (base * base) % mod;
        }
        return result;
    }
};
