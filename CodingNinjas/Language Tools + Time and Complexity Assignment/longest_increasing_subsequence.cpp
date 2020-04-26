// Longest Increasing Subsequence
// Send Feedback
// You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sub sequence of consecutive numbers using the numbers from given array.
// You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
// Best solution takes O(n) time.
// If two arrays are of equal length return the array whose index of smallest element comes first.
// Input Format :
// Line 1 : Integer n, Size of array
// Line 2 : Array elements (separated by space)
// Constraints :
// 1 <= n <= 10^5
// Sample Input 1 :
// 13
// 2 12 9 16 10 5 3 20 25 11 1 8 6 
// Sample Output 1 :
// 8 
// 9 
// 10 
// 11 
// 12
// Sample Input 2 :
// 7
// 15 13 23 21 19 11 16
// Sample Output 2 :
// 15 
// 16



#include<bits/stdc++.h>
using namespace std;

vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
    set<int> s;
    set<int>::iterator it;
    vector<int> v;
    for(int i=0; i<n; i++){
        if(s.find(arr[i])==s.end()){
            s.insert(arr[i]);
            v.push_back(arr[i]);
        }
    }
    int max_count=0, max_count_number;
    for (int i=0; i<v.size(); i++)
    {
        int count=0, num = v[i];
        while(s.find(num)!=s.end()){
            count++;
            num++;
        }
        if(count>max_count){
            max_count=count;
            max_count_number=v[i];
        }
    }
    
    vector<int> ans;

    for(int i=0; i<max_count; i++){
        ans.push_back(max_count_number+i);
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for( int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> v;
    v=longestSubsequence(arr, n);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
    delete[] arr;
    return 0;
}