// Inversion Count
// Send Feedback
// Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
// Input format :
// Line 1 : n, array size
// Line 2 : Array elements (separated by space).
// Output format :
// Count of inversions
// Constraints :
// 1 <= n <= 10^5
// 1 <= A[i] <= 10^9
// Sample Input 1 :
// 3
// 3 2 1
// Sample Output 1 :
// 3
// Sample Input 2 :
// 5
// 2 5 1 3 4
// Sample Output 1 :
// 4


#include <bits/stdc++.h>
using namespace std;

long long merge(int *arr, int n1, int n2)
{
    int *l = new int[n1];
    int *r = new int[n2 - n1];
    long long inv=0;
    int index = 0;

    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[index];
        index++;
    }
    for (int i = 0; i < n2-n1; i++)
    {
        r[i] = arr[index];
        index++;
    }

    int i=0, j=0, k=0;
    while(i!=n1 && j!=(n2-n1)){
        if(l[i]<r[j]){
            arr[k]=l[i];
            i++;
            k++;
        }else if(l[i]>r[j]){
            arr[k]=r[j];
            inv+=(n1-i);
            k++;
            j++;
        }else{
            arr[k]=l[i];
            arr[k+1]=r[j];
            inv+=(n1-i-1);
            k+=2;
            i++;
            j++;
        }
    }
    if(i==n1){
        while(j!=(n2-n1)){
            arr[k]=r[j];
            k++;
            j++;
        }
    }else{
        while(i!=n1){
            arr[k]=l[i];
            k++;
            i++;
        }
    }
    delete[] l;
    delete[] r;
    return inv;
}

long long solve(int A[], int n)
{
    // Write your code here.
    if(n==1){
        return 0;
    }
    long long inv= solve(A, n/2)+solve(A+(n/2), (n-n/2));
    inv+=merge(A, n/2, n);
    return inv;
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr, n);
    delete[] arr;
    return 0;
}