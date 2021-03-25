// https://www.interviewbit.com/problems/gray-code/

// Method 1:

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == 0) return {0};
    vector<int> h1 = grayCode(A-1), h2(h1.begin(), h1.end()), res;
    reverse(h2.begin(), h2.end());
    for(auto i:h1) res.push_back(i);
    for(auto i:h2) res.push_back((1<<(A-1))+i);
    return res;
}

// Method 2:

void helper(int A, int cur, bool firstOnes, vector<int> & ans){
    if(A == 0){
        ans.push_back(cur);
        return;
    }
    if(firstOnes){
        helper(A-1, cur+(1<<(A-1)), 0, ans);
        helper(A-1, cur, 1, ans);
    } else {
        helper(A-1, cur, 0, ans);
        helper(A-1, cur+(1<<(A-1)), 1, ans);
    }
}

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> ans;
    helper(A, 0, 0, ans);
    return ans;
}
