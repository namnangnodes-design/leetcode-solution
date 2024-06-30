class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
   stack<int> suvive;
    suvive.push(asteroids[0]);
    for (int i = 1; i < asteroids.size(); i++)
    {
        int b = asteroids[i];
        if (suvive.empty())
        {
            suvive.push(b);
            continue;
        }
        int a = suvive.top();
        if (a <= 0 || b >= 0)
        {
            suvive.push(b);
            continue;
        }
        if (abs(a) == abs(b))
        {
            suvive.pop();
            continue;
        }
        else if (abs(a) > abs(b))
        {
            continue;
        }
        else
        {
            suvive.pop();
            if (suvive.empty() || suvive.top() <= 0)
            {
                suvive.push(b);
            }
            while (suvive.top() > 0)
            {
                if (abs(suvive.top()) == abs(b))
                {
                    suvive.pop();
                    break;
                }
                else if (abs(suvive.top()) > abs(b))
                {
                    break;
                }
                else
                {
                    suvive.pop();
                    if (suvive.empty() || suvive.top() <= 0)
                    {
                        suvive.push(b);
                    }
                }
            }
        }
    }
    vector<int> result;
    while (!suvive.empty())
    {
        result.push_back(suvive.top());
        suvive.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
};
