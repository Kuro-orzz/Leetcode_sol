class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle_min = minutes * 6.0;
        double angle_hour = (hour % 12) * 30.0 + minutes / 2.0;
        return min(abs(angle_hour - angle_min), 360 - abs(angle_hour - angle_min));
    }
};