// Activity Selection
// Send Feedback
// You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
// Input
// The first line of input contains one integer denoting N.
// Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

// Output
// Output one integer, the maximum number of activities that can be performed
// Constraints
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di ≤ 10^9
// Sample Input
// 6
// 1 2
// 3 4
// 0 6
// 5 7
// 8 9
// 5 9
// Sample Output
// 4

#include<bits/stdc++.h>
using namespace std;

struct interval{
    int start, end;
};

bool compare(interval a, interval b){
    return a.end<b.end;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Write your code here
    int n;
    cin>>n;
    interval* arr = new interval[n];
    for(int i=0; i<n; i++){
        cin>>arr[i].start>>arr[i].end;
    }
    sort(arr, arr+n, compare);
    // for(int i=0; i<n; i++){
    //     cout<<arr[i].start<<" "<<arr[i].end<<endl;
    // }
    int count=0, end=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i].start>=end){
            end=arr[i].end;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}