// Find the Unique Element
// Send Feedback
// Given an integer array of size 2N + 1. In this given array, N numbers are present twice and one number is present only once in the array.
// You need to find and return that number which is unique in the array.
// Note : Given array will always contain odd number of elements.
// Input format :
// Line 1 : Array size i.e. 2N+1
// Line 2 : Array elements (separated by space)
// Output Format :
// Unique element present in the array
// Constraints :
// 1 <= N <= 10^6
// Sample Input :
// 7
// 2 3 1 6 3 6 2
// Sample Output :
// 1



// arr - input array
// size - size of array
#include<map>
using namespace std;

int FindUnique(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    map<int,int> m;
    map<int,int>::iterator it;
    for(int i=0; i<size; i++){
        m[arr[i]]++;
    }
    for(it=m.begin(); it!=m.end(); it++){
        if(it->second==1)
            return it->first;
    }
}