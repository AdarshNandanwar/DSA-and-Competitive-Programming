// https://leetcode.com/problems/find-all-people-with-secret/

// Method 1 (Union Find with Path Compression, O(nlogn)):

class Solution {
    int getRoot(int r, vector<int>& root){
        if(root[r] == r){
            return r;
        }
        return root[r] = getRoot(root[r], root);
    }

    void merge(int r1, int r2, vector<int>& root){
        r1 = getRoot(r1, root);
        r2 = getRoot(r2, root);
        if(r1 != r2){
            root[r1] = r2;
        }
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });
        
        vector<int> root(n);
        for(int i=0; i<n; i++){
            root[i] = i;
        }

        int m = meetings.size();
        int curTime = meetings[0][2];
        int curTimeFirstIndex = 0;
        merge(0, firstPerson, root);
        for(int i=0; i<m; i++){
            int time = meetings[i][2];
            if(time != curTime){
                for(int j=curTimeFirstIndex; j<i; j++){
                    int p1 = meetings[j][0];
                    int p2 = meetings[j][1];
                    if(getRoot(p1, root) != getRoot(0, root)){
                        root[p1] = p1;
                    }
                    if(getRoot(p2, root) != getRoot(0, root)){
                        root[p2] = p2;
                    }
                }
                curTime = time;
                curTimeFirstIndex = i;
            }
            int p1 = meetings[i][0];
            int p2 = meetings[i][1];
            merge(p1, p2, root);
        }

        for(int j=curTimeFirstIndex; j<m; j++){
            int p1 = meetings[j][0];
            int p2 = meetings[j][1];
            if(getRoot(p1, root) != getRoot(0, root)){
                root[p1] = p1;
            }
            if(getRoot(p2, root) != getRoot(0, root)){
                root[p2] = p2;
            }
        }


        vector<int> res;
        for(int i=0; i<n; i++){
            if(getRoot(i, root) == getRoot(0, root)){
                res.push_back(i);
            }
        }
        return res;
    }
};