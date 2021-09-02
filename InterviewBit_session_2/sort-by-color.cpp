// https://www.interviewbit.com/problems/sort-by-color/

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> v(3, 0);
    for(auto &i:A) v[i]++;
    int i = 0;
    while(v[0]--) A[i++] = 0;
    while(v[1]--) A[i++] = 1;
    while(v[2]--) A[i++] = 2;
}
