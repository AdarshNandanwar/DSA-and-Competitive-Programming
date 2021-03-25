// https://www.interviewbit.com/problems/order-of-people-heights/



// Method 1 (Sorting, O(n2)):

#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<pair<int, int>> v;
    for(int i = 0; i<n; i++) v.push_back({A[i], B[i]});
    // idea: the next shortest person's inFront is its position in the remaning spaces vector
    // e.g. pos of 4 (inFront = 2) in [3,-1,2,1,-1,-1] its inFront'th empty position,
    //      that is index = 5
    sort(v.begin(), v.end(), [](const pair<int, int> & a, const pair<int, int> & b){
        return a.first < b.first;
    });
    vector<int> res(n, -1);
    for(auto & i:v){
        // finding the actual index i.second in the unoccupied positions
        int index = -1, j;
        for(j = 0; j<n; j++){
            if(res[j] == -1) index++;
            if(index == i.second) break;
        }
        res[j] = i.first;
    }
    return res;
}
