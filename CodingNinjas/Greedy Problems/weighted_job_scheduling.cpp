// Weighted Job Scheduling
// Send Feedback
// You are given N jobs where every job is represented as:
// 1.Start Time
// 2.Finish Time
// 3.Profit Associated
// Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
// Input
// The first line of input contains one integer denoting N.
// Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
// Output
// Output one integer, the maximum profit that can be achieved.
// Constraints
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di, p ≤ 10^6
// Sample Input
// 4
// 3 10 20
// 1 2 50
// 6 19 100
// 2 100 200
// Sample Output
// 250


#include<bits/stdc++.h>
using namespace std;

struct jobs{
    int start, end, profit, max_profit_till_now;
};

bool compare(jobs a, jobs b){
    return a.end<b.end;
}

int search(jobs* arr, int start, int end, int search_term){
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(arr[mid].end<=search_term){
            start=++mid;
        }else{
            end=--mid;
        }
    }
    return end;
}

int main()
{
    //Write your code here
    int n;
    cin>>n;
    jobs* arr = new jobs[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i].start>>arr[i].end>>arr[i].profit;
    }
    sort(arr, arr+n, compare);

    arr[0].max_profit_till_now=arr[0].profit;
    for (int i = 1; i < n; i++)
    {
        int prev_index=search(arr, 0, i-1, arr[i].start);
        if(prev_index>=0){
            arr[i].profit+=arr[prev_index].max_profit_till_now;
            arr[i].max_profit_till_now=max(arr[i-1].max_profit_till_now, arr[i].profit);
        }else{
            arr[i].max_profit_till_now=max(arr[i-1].max_profit_till_now, arr[i].profit);
        }
    }
    cout<<arr[n-1].max_profit_till_now<<endl;
    delete[] arr;
    return 0;
}