class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        queue<int> road;
        road.push(start);
        visited[start] = true;
        while (!road.empty())
        {
            int cur = road.front();
            road.pop();
            if (arr[cur] == 0) return true;
            if (cur - arr[cur] >= 0 && !visited[cur - arr[cur]])
            {
                road.push(cur - arr[cur]);
                visited[cur - arr[cur]] = true;
            }
            if (cur + arr[cur] < arr.size() && !visited[cur + arr[cur]])
            {
                road.push(cur + arr[cur]);
                visited[cur + arr[cur]] = true;
            }
        } 
        return false;
    }
};
