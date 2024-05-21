// https://leetcode.com/problems/minimum-area-rectangle/

// Method 1 (Hash Map, O(n*n)):

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        // y coordinates for a given x
        unordered_map<int, unordered_set<int>> yCoordinates;
        for(const auto & point:points){
            yCoordinates[point[0]].insert(point[1]);
        }
        int minArea = INT_MAX;
        // point1 and point2 are 2 diagonally opposite vertices of the rectange.
        for(const auto & point1:points){
            int x1 = point1[0];
            int y1 = point1[1];
            for(const auto & point2:points){
                int x2 = point2[0];
                int y2 = point2[1];
                if(x1 == x2 or y1 == y2){
                    continue;
                }
                if(yCoordinates[x1].count(y2) and yCoordinates[x2].count(y1)){
                    minArea = min(minArea, abs(x2-x1)*abs(y2-y1));
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};

// Method 2 (Hash Map, O(n*n*n*logn)):

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        // y coordinates for a given x
        unordered_map<int, unordered_set<int>> yCoordinates;
        for(const auto & point:points){
            yCoordinates[point[0]].insert(point[1]);            
        }
        int minArea = INT_MAX;
        for(const auto & yCoordinates1:yCoordinates){
            int x1 = yCoordinates1.first;            
            for(const auto & yCoordinates2:yCoordinates){
                int x2 = yCoordinates2.first;
                if(x1 == x2){
                    continue;
                }
                vector<int> commonY;
                for(const int y:yCoordinates1.second){
                    if(yCoordinates2.second.count(y)){
                        commonY.push_back(y);
                    }
                }
                if(commonY.size() <= 1){
                    continue;
                }
                sort(commonY.begin(), commonY.end());
                int minSideLength = commonY[1]-commonY[0];
                for(int i=2; i<commonY.size(); i++){
                    minSideLength = min(minSideLength, commonY[i]-commonY[i-1]);
                }
                minArea = min(minArea, abs(x2-x1)*minSideLength);
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};
