double angleClock(int hour, int minutes) {
    double ans = fabs((hour % 12) * 30.0 + minutes / 2.0 - minutes * 6.0);
    return ans > 180 ? 360.0 - ans : ans;
}
