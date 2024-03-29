// Rotate array
// Send Feedback
// Given a random integer array of size n, write a function that rotates the given array by d elements (towards left)
// Change in the input array itself. You don't need to return or print elements.
// Input format :
// Line 1 : Integer n (Array Size)
// Line 2 : Array elements (separated by space)
// Line 3 : Integer d
// Output Format :
// Updated array elements (separated by space)
// Constraints :
// 1 <= N <= 1000
// 1 <= d <= N
// Sample Input :
// 7
// 1 2 3 4 5 6 7
// 2
// Sample Output :
// 3 4 5 6 7 1 2




// arr - input array
// size - size of array
// d - array to be rotated by d elements
#include<vector>
using namespace std;

void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
    vector<int> v;
    for(int i=d; i<size;i++){
        v.push_back(arr[i]);
    }
    for(int i=0; i<d; i++){
        v.push_back(arr[i]);
    }
    for(int i=0; i<size; i++){
        arr[i]=v[i];
    }
}	
