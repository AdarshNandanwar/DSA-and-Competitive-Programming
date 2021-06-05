// https://leetcode.com/problems/course-schedule-iii/

// Method 1 (Greedy, Prioirity Queue, O(nlogn)):

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int> & a, const vector<int> & b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        // pq contains the durations of the classes currently selected
        priority_queue<int, vector<int>> pq;
        int cur = 0, ans = 0;
        pq.push(cur);
        for(auto & i:courses){
            int top = pq.top();
            if(cur+i[0] <= i[1]){
                pq.push(i[0]);
                cur += i[0];
                ans++;
            } else if(top > i[0] and cur-top+i[0] <= i[1]){
                pq.pop();
                pq.push(i[0]);
                cur = cur-top+i[0];
            }
        }
        return ans;
    }
};

// Method 2 (DP, O(n2), TLE):

class Solution {
public:
    
    int helper(vector<vector<int>> & courses, int start, int index, vector<vector<int>> & dp){
        if(index == courses.size()) return 0;
        if(dp[start][index] != -1) return dp[start][index];
        int res = 0;
        if(start+courses[index][0] <= courses[index][1]) res = max(res, 1+helper(courses, start+courses[index][0], index+1, dp));
        res = max(res, helper(courses, start, index+1, dp));
        return dp[start][index] = res;
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        int max_deadline = 0;
        for(auto & i:courses) max_deadline = max(max_deadline, i[1]);
        sort(courses.begin(), courses.end(), [](const vector<int> & a, const vector<int> & b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        vector<vector<int>> dp(max_deadline+1, vector<int>(courses.size(), -1));
        return helper(courses, 0, 0, dp);
    }
};