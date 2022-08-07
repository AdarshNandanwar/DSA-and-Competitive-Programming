// https://leetcode.com/problems/course-schedule/

// Method 1 (Topological SOrt, O(V+E)):

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Topological Sort
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int>> graph;
        for(auto &prereq:prerequisites){
            inDegree[prereq[1]]++;
            graph[prereq[0]].push_back(prereq[1]);
        }
        queue<int> courses;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0){
                courses.push(i);
            }
        }
        int coursesDone = 0;
        while(!courses.empty()){
            auto course = courses.front();
            courses.pop();
            coursesDone++;
            for(auto &nbr:graph[course]){
                inDegree[nbr]--;
                if(inDegree[nbr] == 0){
                    courses.push(nbr);
                }
            }
        }
        return coursesDone == numCourses;
    }
};