// Duplicate in array
// Send Feedback
// Given an array of integers of size n which contains numbers from 0 to n - 2. Each number is present at least once. That is, if n = 5, numbers from 0 to 3 is present in the given array at least once and one number is present twice. You need to find and return that duplicate number present in the array.
// Assume, duplicate number is always present in the array.
// Input format :
// Line 1 : Size of input array
// Line 2 : Array elements (separated by space)
// Output Format :
// Duplicate element
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 9
// 0 7 2 5 4 7 1 3 6
// Sample Output:
// 7



// arr - input array
// size - size of array
#include<set>

int MissingNumber(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    set<int> s;
    for(int i=0; i<size; i++){
        if(s.find(arr[i])==s.end()){
            s.insert(arr[i]);
        }else{
            return arr[i];
        }
    }
}
