// https://leetcode.com/problems/longest-mountain-in-array/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int longestMountain(vector<int>& A) {
    int p1 = 0, p2 = 0, n = A.size();
    int max_len = 0;
    while(p1+2 < n){
        // Skip slope down
        while(p2+1<n && A[p2+1] <= A[p2]) p2++;
        p1 = p2;
        // Climb up the hill
        bool hill_up = false;
        while(p2+1<n && A[p2+1] > A[p2]){
            hill_up = true;
            p2++;
        }
        // Go down the hill
        bool hill_down = false;
        while(p2+1<n && A[p2+1] < A[p2]){
            hill_down = true;
            p2++;
        }
        if(hill_up && hill_down){
            max_len = max(max_len, p2-p1+1);
        }
        p1 = p2;
    }
    return max_len;
}

int main() {
    vector<int> v{2,1,4,7,3,2,5};
    cout<<longestMountain(v);
    return 0;
}