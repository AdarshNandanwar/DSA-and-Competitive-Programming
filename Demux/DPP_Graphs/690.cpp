// https://leetcode.com/problems/employee-importance/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        unordered_map<int, bool> visited;
        for(auto e:employees) m[e->id] = e;
        int imp = 0;
        queue<Employee*> q;
        q.push(m[id]);
        visited[id] = true;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            imp += cur->importance;
            for(auto sub:cur->subordinates){
                if(!visited[sub]){
                    visited[sub] = true;
                    q.push(m[sub]);
                }
            }
        }
        return imp;
    }
};