class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;
        double mDeg = 360.f / 60.f * minutes;
        double hDeg = 360.f / 12.f * hour;
        hDeg += 30.f / 60.f * minutes;
        return min(abs(hDeg - mDeg), 360.f - abs(hDeg - mDeg));
    }
};
