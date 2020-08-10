// https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> res;
    // removing leading zeros
    for(auto itr = A.begin(); itr!=A.end(); itr++){
        if(*itr >= 1){
            res = vector<int>(itr, A.end());
            break;
        }
    }
    int n = res.size(), i;
    for(i = n-1; i>=0; i--){
        if(res[i] == 9) res[i] = 0;
        else {
            res[i]++;
            break;
        }
    }
    if(i == -1){
        if(res.size()){
            // all 9s
            res[0] = 1;
            res.push_back(0);
        } else {
            res.push_back(1);
        }
    }
    return res;
}
