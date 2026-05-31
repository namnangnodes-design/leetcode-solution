class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long massL = mass;
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (massL < asteroids[i])
            {
                return false;
            }
            massL += asteroids[i];
        }
        return true;
    }
};
