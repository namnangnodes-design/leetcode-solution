class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mMap;
        for (int i = 0; i < arr.size(); i++)
        {
            mMap[arr[i]].push_back(i);
        }
        int step = 0;
        queue<int> road;
        vector<bool> visited(arr.size(), false);
        road.push(0);
        visited[0] = true;
        while (!road.empty())
        {
            int size = road.size();
            while (size--)
            {
                int cur = road.front();
                if (cur == n - 1) {
                    return step;
                }
                road.pop();
                if (cur - 1 > -1 && !visited[cur - 1])
                {
                    road.push(cur - 1);
                    visited[cur - 1] = true;
                }
                if (cur + 1 < n && !visited[cur + 1])
                {
                    road.push(cur + 1);
                    visited[cur + 1] = true;
                }
                if (mMap.count(arr[cur])) {
                    for (int idx : mMap[arr[cur]]) {
                        if (!visited[idx]) {
                            visited[idx] = true;
                            road.push(idx);
                        }
                    }
                    mMap.erase(arr[cur]);
                }
            }
            step++;
        }
        return step;
    }
};
