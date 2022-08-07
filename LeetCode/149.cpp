// https://leetcode.com/problems/max-points-on-a-line/

// Method 1 (Hash Map, O(n2)):

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for(auto &base:points){
            int repeat = 0, maxValue = 0;
            unordered_map<string, int> freq;
            for(auto &point:points){
                int dx = base[0]-point[0];
                int dy = base[1]-point[1];
                if(dx==0 and dy==0){
                    repeat++;
                    continue;
                }
                bool sign = ((dx>=0) == (dy>=0));
                dx = abs(dx);
                dy = abs(dy);
                int hcf = __gcd(dx, dy);
                dx /= hcf;
                dy /= hcf;
                string key = to_string(sign)+"#"+to_string(dx)+"#"+to_string(dy);
                freq[key]++;
                maxValue = max(maxValue, freq[key]);
            }
            ans = max(ans, maxValue+repeat);            
        }
        return ans;
    }
};