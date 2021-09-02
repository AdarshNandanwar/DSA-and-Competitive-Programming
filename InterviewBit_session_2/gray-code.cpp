// https://www.interviewbit.com/problems/gray-code/

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == 0) return {0};
    auto res = grayCode(A-1);
    int n = res.size(), a = 1<<(A-1);
    for(int i = n-1; i>=0; i--){
        res.push_back(a+res[i]);
    }
    return res;
}
