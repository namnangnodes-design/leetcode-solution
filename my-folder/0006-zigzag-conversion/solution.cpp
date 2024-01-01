class ComparePair {
public:
    bool operator()(pair<int, int> o1, pair<int, int> o2)
    {
        if (o1.first > o2.first) {
            return true;
        }
        else if (o1.first == o2.first
            && o1.second > o2.second) {
            return true;
        }

        return false;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
        {
            return s;
        }
        string result;
        char transform[1001][1001];
        int zigzag = 0;
        int index = -1;
        int zigzagNum = s.length() / (2 * numRows - 2);
        priority_queue < pair<int, int>, vector<pair<int, int>>,ComparePair> getQueue;
        while (zigzag < zigzagNum)
        {
            for (int j = 0; j < numRows; j++)
            {
                transform[j][zigzag * (numRows - 1)] = s[++index];
                getQueue.push({ j, zigzag * (numRows - 1)});
            }
            for (int j = numRows - 2, k = 1; j > 0; j--, k++)
            {
                transform[j][zigzag * (numRows - 1) + k] = s[++index];
                getQueue.push({ j, zigzag * (numRows - 1) + k});
            }
            zigzag++;
        }
        for (int j = 0; j < numRows; j++)
        {
            if (index == s.length() - 1)
            {
                break;
            }
            transform[j][zigzag * (numRows - 1)] = s[++index];
            getQueue.push({ j, zigzag * (numRows - 1)});
        }
        for (int j = numRows - 2, k = 1; j > 0; j--, k++)
        {
            if (index == s.length() - 1)
            {
                break;
            }
            transform[j][zigzag * (numRows - 1) + k] = s[++index];
            getQueue.push({ j, zigzag * (numRows - 1) + k});
        }
        while (!getQueue.empty())
        {
            result.push_back(transform[getQueue.top().first][getQueue.top().second]);
            getQueue.pop();
        }
        return result;
    }
};

