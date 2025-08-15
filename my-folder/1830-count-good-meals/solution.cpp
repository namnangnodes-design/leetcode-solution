class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        if (deliciousness.size() == 1) return 0;
        vector<int> sums = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152};
        unordered_map<long long int, long long int> mMap;
        vector<int> d;
        for (int i = 0; i < deliciousness.size(); i++)
        {
            mMap[deliciousness[i]]++;
            if (mMap[deliciousness[i]] == 1)
            {
                d.push_back(deliciousness[i]);
            }
        }
        sort(d.begin(), d.end());
        // cout << "d: ";
        // for (int i = 0; i < d.size(); i++)
        // {
        //     cout << d[i] << " ";
        // }
        // cout << endl << "mMap: " << endl;
        // for (auto i: mMap)
        // {
        //     cout << i.first << " " << i.second << endl;
        // }
        long long int result = 0;
        if (d.size() == 1)
        {
            for (int i = 0; i < 22; i++)
            {
                if (d[0] * 2 == sums[i]) {
                    result += mMap[d[0]] * (mMap[d[0]] - 1) / 2 % 1000000007;
                    return result;
                }
            }
            return 0;
        }
        // cout << "result: " << endl;
        for (int i = 0; i < 22; i++)
        {
            int sum = sums[i];
            if (d[d.size() - 1] * 2 < sum) break;
            for (auto j: mMap)
            {
                //cout << "sum: " << sum << " j: " << j.first << endl;
                if (j.first * 2 == sum) 
                {
                    result += j.second * (j.second - 1) / 2 % 1000000007;
                } 
            }
            int left = 0;
            int right = d.size() - 1;
            while (left < right)
            {
                if (d[left] + d[right] == sum)
                {
                    //cout << "sum: " << sum << " left: " << d[left] << " right: "<< d[right] << endl;
                    result += mMap[d[left]] * mMap[d[right]] % 1000000007;
                    left++;
                    right--; 
                }
                else if (d[left] + d[right] < sum)
                {
                    left++;
                }
                else
                {
                    right--;
                } 
            }
            //cout << sums[i] << " " << result << endl;
        }
        return result;
    }
};
