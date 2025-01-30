class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        vector<bool> visited;
        candidates = min(static_cast<int>(costs.size()), candidates);
        k = min(static_cast<int>(costs.size()), k);
        for (int i = 0; i < costs.size(); i++)
        {
            visited.push_back(false);
        }
        //printf("qua bool \n");
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > left;
        for (int i = 0; i < candidates; i++)
        {
            left.emplace(costs.at(i), i);
        }
        //printf("qua left \n");
        int curLeft = candidates - 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > right;
        for (int i = costs.size() - 1; i >= static_cast<int>(costs.size()) - candidates; i--)
        {
            right.emplace(costs.at(i), i);
        }
        //printf("qua right \n");

        int curRight = costs.size() - candidates;
        long long total = 0;
        for (int i = 0; i < k; i++)
        {
            pair<int, int> lTop = left.top();
            pair<int, int> rTop = right.top();
            if (lTop.first == rTop.first && lTop.second == rTop.second)
            {
                total += lTop.first;
                visited.at(lTop.second) = true;
                left.pop();
                while (curLeft < costs.size() - 1)
                {
                    curLeft++;
                    if (!visited.at(curLeft))
                    {
                        left.emplace(costs.at(curLeft), curLeft);
                        break;
                    }
                }
                right.pop();
                while (curRight > 0)
                {
                    curRight--;
                    if (!visited.at(curRight))
                    {
                        right.emplace(costs.at(curRight), curRight);
                        break;
                    }
                }
                 //printf("value %d index %d ", lTop.first, lTop.second);
                // printf("left queue: %d %d", left.top().first, left.top().second);
                // printf("right queue: %d %d \n", right.top().first, right.top().second);

            }
            else if (lTop.first < rTop.first || (lTop.first == rTop.first && lTop.second < rTop.second))
            {
                total += lTop.first;
                visited.at(lTop.second) = true;
                left.pop();
                while (curLeft < costs.size() - 1)
                {
                    curLeft++;
                    if (!visited.at(curLeft))
                    {
                        left.emplace(costs.at(curLeft), curLeft);
                        break;
                    }
                }
                //printf("value %d index %d \n", lTop.first, lTop.second);
                // printf("left queue: %d %d", left.top().first, left.top().second);
                // printf("right queue: %d %d \n", right.top().first, right.top().second);
            }
            else
            {
                total += rTop.first;
                visited.at(rTop.second) = true;
                right.pop();
                while (curRight > 0)
                {
                    curRight--;
                    if (!visited.at(curRight))
                    {
                        right.emplace(costs.at(curRight), curRight);
                        break;
                    }
                }
                 //printf("value %d index %d \n", rTop.first, rTop.second);
                // printf("left queue: %d %d", left.top().first, left.top().second);
                // printf("right queue: %d %d \n", right.top().first, right.top().second);
            }
        }
        return total;
    }
};
