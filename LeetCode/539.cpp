// https://leetcode.com/problems/minimum-time-difference/

// Method 1 (Hash Set, O(n)):

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        unordered_set<string> s;
        for(string timePoint:timePoints){
            if(s.count(timePoint)){
                return 0;
            }
            s.insert(timePoint);
        }
        
        int index = 0;
        int prev = -1;
        int minDiff = INT_MAX;
        for(int h=0; h<48; h++){
            for(int m=0; m<60; m++){
                string hour = to_string(h % 24);    // Important as we are looping twice
                if(hour.length() == 1){
                    hour = "0" + hour;
                }
                string minute = to_string(m);
                if(minute.length() == 1){
                    minute = "0" + minute;
                }
                string time = hour + ":" + minute;

                if(s.count(time)){
                    if(prev != -1){
                        minDiff = min(minDiff, index - prev);
                    }
                    prev = index;
                }

                index++;
            }
        }

        return minDiff;
    }
};
