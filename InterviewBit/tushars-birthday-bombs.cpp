// https://www.interviewbit.com/problems/tushars-birthday-bombs/

// Method 1 (Greedy, O(n)):

vector<int> Solution::solve(int A, vector<int> &B) {
    int n = B.size();
    int minEle = *min_element(B.begin(), B.end());
    int remaining = A/minEle;
    vector<int> ans;
    for(int i = 0; i<n and remaining; i++){
        while(remaining and (remaining-1)*minEle <= A-B[i]){
            ans.push_back(i);
            remaining--;
            A -= B[i];
        }
    }
    return ans;
}
