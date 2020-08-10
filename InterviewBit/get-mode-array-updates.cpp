// https://www.interviewbit.com/problems/get-mode-array-updates/?test_id=11866

// Method 1 (LFU Cache with set, O(qlogn)):
// Can be made O(1) using linked lists

vector<int> Solution::getMode(vector<int> &A, vector<vector<int> > &B) {
    unordered_map<int, int> freq;
    unordered_map<int, set<int>> revFreq;
    int maxFreq = 0;
    for(auto i:A) maxFreq = max(maxFreq, ++freq[i]);
    for(auto [i,f]:freq) revFreq[f].insert(i);
    vector<int> res;
    int n = B.size();
    for(int i = 0; i<n; i++){
        int index = B[i][0]-1;
        int newVal = B[i][1];
        if(A[index] != newVal){
            revFreq[freq[A[index]]].erase(A[index]);
            freq[A[index]]--;
            revFreq[freq[A[index]]].insert(A[index]);
            if(revFreq[maxFreq].empty()) maxFreq--;
            
            A[index] = newVal;
            
            revFreq[freq[A[index]]].erase(A[index]);
            freq[A[index]]++;
            revFreq[freq[A[index]]].insert(A[index]);
            maxFreq = max(maxFreq, freq[A[index]]);
        }
        res.push_back(*revFreq[maxFreq].begin());
    }
    return res;
}
