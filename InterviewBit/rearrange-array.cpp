// https://www.interviewbit.com/problems/rearrange-array/

// Method 1 (Altering the array, O(n) time, O(1) space):

void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();

    for(int i = 0; i<n; i++){
        if(A[i]/n) continue;
        int cur = i, next = A[i];
        while(A[next]/n == 0){      // checking if done
            swap(A[cur], A[next]);
            int temp = next;
            next = A[cur];
            A[cur] += n;            // marking as done
            cur = temp;
        }
    }
    for(auto & i:A) i = i%n;        // getting the original array back
}
