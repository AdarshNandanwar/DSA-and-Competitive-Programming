// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// Method 1 (Sorting, NeetCode, O(nlogn)):

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // https://www.youtube.com/watch?v=lPmkKnvNPrw
        int n = points.size();

        sort(points.begin(), points.end());

        int arrows = 0;
        vector<int> prev = points[0];
        for(int i=1; i<n; i++){
            vector<int> cur = points[i];
            if(prev[1] >= cur[0]){
                // Overlap. Update the common interval.
                prev[0] = cur[0];
                prev[1] = min(cur[1], prev[1]);
            } else {
                // No overlap. Shoot the previous common interval.
                prev = cur;
                arrows++;
            }
        }

        // Shoot the last common interval.
        arrows++;

        return arrows;
    }
};

// Method 2 (Sorting, Complicated, O(nlogn)):

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> sortStart, sortEnd;
        for(int i=0; i<n; i++){
            sortStart.push_back({points[i][0], points[i][1], i});
            sortEnd.push_back({points[i][0], points[i][1], i});
        }
        sort(sortStart.begin(), sortStart.end(), [](const vector<int> & a, const vector<int> & b){
            return a[0] < b[0];
        });
        sort(sortEnd.begin(), sortEnd.end(), [](const vector<int> & a, const vector<int> & b){
            return a[1] < b[1];
        });
        vector<int> popped(n, false);
        int indexEnd = 0;
        int indexStart = 0;
        int arrows = 0;
        while(indexEnd < n){
            if(popped[sortEnd[indexEnd][2]]){
                indexEnd++;
                continue;
            }
            popped[sortEnd[indexEnd][2]] = true;
            int xEnd = sortEnd[indexEnd][1];
            while(indexStart < n and sortStart[indexStart][0] <= xEnd){
                popped[sortStart[indexStart][2]] = true;
                indexStart++;
            }
            arrows++;
            indexEnd++;
        }
        return arrows;
    }
};
