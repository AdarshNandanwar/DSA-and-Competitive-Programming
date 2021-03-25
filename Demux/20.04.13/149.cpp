// https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), x, y;
        if(n == 0){
            return 0;
        }
        int ans = 1, dx, dy;
        for(int i = 0; i<n; i++){
            unordered_map<string, int> m;
            string slope;
            int dup = 0, local_ans = 1;
            for(int j = i+1; j<n; j++){
                dx = points[j][0]-points[i][0];
                dy = points[j][1]-points[i][1];
                
                int gcd = __gcd(dx, dy);
                if(dx == 0 && dy == 0){
                    dup++;
                    continue;
                } else {
                    dx /= gcd;
                    dy /= gcd;
                }
                
                slope = to_string(dy)+"/"+to_string(dx);
                
                if(m.find(slope) != m.end()){
                    m[slope]++;
                } else {
                    m[slope] = 2;
                }
                local_ans = max(local_ans, m[slope]);
            }
            ans = max(ans, local_ans+dup);
        }
        return ans;
    }
};