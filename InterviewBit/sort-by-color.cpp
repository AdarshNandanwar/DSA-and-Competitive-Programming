// https://www.interviewbit.com/problems/sort-by-color/

// Method 1 (2 Pointers, O(n)):

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size(), i = 0, j = n-1, k = 0;
    while(k<=j){
        if(A[k] == 0){
            swap(A[i++], A[k++]);
        } else if(A[k] == 2){
            swap(A[j--], A[k]);
        } else {
            k++;
        }
    }
}

// Method 2 (Count Sort, O(n)):

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> freq(3, 0);
    for(auto i:A) freq[i]++;
    int color = 0;
    for(auto & i:A){
        while(!freq[color]) color++;
        i = color;
        freq[color]--;
    } 
}
