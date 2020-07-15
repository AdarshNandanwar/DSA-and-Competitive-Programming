// https://leetcode.com/problems/angle-between-hands-of-a-clock/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12) hour = 0;
        double minuteAngle = 6*minutes, hourAngle = 30*hour+minutes/2.0;
        return min(abs(minuteAngle-hourAngle), 360-abs(minuteAngle-hourAngle));
    }
};