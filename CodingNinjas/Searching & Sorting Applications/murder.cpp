// Murder
// Send Feedback
// Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
// Answer may not fit in integer . You have to take long.
// Input
// First line gives T, number of test cases.

// 2T lines follow.

// First line gives you the number of stairs N

// Next line gives you N numbers written on the stairs.
// Output
// For each test case output one line giving the final sum for each test case.
// Constraints
// T<=10

// 1<=N<=10^5

// All numbers will be between 0 and 10^6.
// Sample Input:
// 1
// 5
// 1 5 3 6 4
// Sample Output:
// 15
// Explanation:
// For the first number, the contribution to the sum is 0.
// For the second number, the contribution to the sum is 1.
// For the third number, the contribution to the sum is 1.
// For the fourth number, the contribution to the sum is 9 (1+5+3).
// For the fifth number, the contribution to the sum is 4 (1+3).
// Hence the sum is 15 (0+1+1+9+4).



#include<bits/stdc++.h>
using namespace std;

long long merge(int *arr, int n1, int n2)
{
    int *l = new int[n1];
    int *r = new int[n2 - n1];
    long long sum=0;
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
            sum+=((n2-n1-j)*l[i]);
            arr[k]=l[i];
            i++;
            k++;
        }else{
            arr[k]=r[j];
            k++;
            j++;
        }
    }
    while(j<(n2-n1)){
        arr[k]=r[j];
        k++;
        j++;
    }
    while(i<n1){
        arr[k]=l[i];
        k++;
        i++;
    }
    
    delete[] l;
    delete[] r;
    return sum;
}

long long solve(int A[], int n)
{
    // Write your code here.
    if(n==1){
        return 0;
    }
    long long sum= solve(A, n/2)+solve(A+(n/2), (n-n/2));
    sum+=merge(A, n/2, n);
    return sum;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* arr=new int[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cout << solve(arr, n)<<endl;
        delete[] arr;
    }
    return 0;
}