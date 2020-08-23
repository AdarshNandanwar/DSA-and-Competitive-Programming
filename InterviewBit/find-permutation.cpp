// https://www.interviewbit.com/problems/find-permutation/

// Method 1

vector<int> Solution::findPerm(const string A, int B) {
    int minVal = 1, maxVal = B;
    vector<int> pos;
    for(auto c:A){
        if(c == 'I') pos.push_back(minVal++);
        else pos.push_back(B--);
    }
    pos.push_back(minVal);
    return pos;
}

// Method 2

vector<int> Solution::findPerm(const string A, int B) {
    int minVal = 0, maxVal = 0, cur = 0;
    vector<int> pos(B, 0);
    for(int i = 1; i<B; i++){
        if(A[i-1] == 'I'){
            maxVal++;
            pos[i] = maxVal;
        } else {
            minVal--;
            pos[i] = minVal;
        }
    }
    for(auto & i:pos) i -= (minVal-1);
    return pos;
}
