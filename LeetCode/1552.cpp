// https://leetcode.com/problems/magnetic-force-between-two-balls/

// Method 1 (Binary Search, O(nlogn + nlog(range/m))):

class Solution {
    bool predicate(const vector<int> & position, const int m, int interval){
        int placed = 0, next = 0;
        for(const int pos:position){
            if(pos >= next){
                placed++;
                next = pos + interval;
                if(placed == m){
                    return true;
                }
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();

        sort(position.begin(), position.end());
        int maxPos = position[n-1];
        int minPos = position[0];

        // Binary Search
        // TF last T
        int lo = 1, hi = (maxPos-minPos+1)/(m-1);
        while(lo < hi){
            int mid = lo + (hi-lo+1)/2;
            if(predicate(position, m, mid)){
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        return lo;
    }
};
