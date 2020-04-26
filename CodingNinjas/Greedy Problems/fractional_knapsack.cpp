// Fractional Knapsack
// Send Feedback
// You want to paint your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start painting the house immediately, covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and can also hire or fire him at any later point of time. However, no more than 1 worker can be painting the house at a given time.
// Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.
// Note: You can hire a previously hired worker without paying him again.
// Input
// The first line of input contains two integers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker, and contains three integers "Ti Xi Yi", described in the statement.
// Output
// Output one integer, the minimum cost that you can spend in order to get your house painted at the earliest.
// Constraints
// 1 ≤ N, T, X, Y ≤ 10^5
// 1 ≤ D ≤ 10^11
// Sample Input
// 3 3
// 1 1 1
// 2 2 2
// 3 1 5
// Sample Output
// 3

#include<bits/stdc++.h>
using namespace std;

struct worker{
    int t, x, y;
};

bool compare(worker a, worker b){
    if(a.t == b.t){
        if(a.y == b.y){
            return a.x>b.x;
        }else{
            return a.y<b.y;
        }
    }else{
        return a.t<b.t;
    }
}

bool compare_workers(worker a, worker b){
    if(a.y == b.y){
        return a.x>b.x;
    }else{
        return a.y<b.y;
    }
}

int main()
{
    //Write your code here
    int n;
    long long d;
    cin>>n>>d;
    worker* arr = new worker[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i].t>>arr[i].x>>arr[i].y;;
    }
    cout<<"=================================="<<endl;
    sort(arr, arr+n, compare);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i].t<<" "<<arr[i].x<<" "<<arr[i].y<<endl;
    }
    cout<<"=================================="<<endl;

    long long painted=0, cost=0;
    int current_worker=0;
    for (int i = 0; i < n-1; i++)
    {
        if(painted>=d){
            cout<<cost<<endl;
            delete[] arr;
            return 0;
        }
        if(arr[i+1].t>arr[i].t){
            if(compare_workers(arr[current_worker], arr[i])){
                current_worker=i;
                cost+=arr[current_worker].x;
            }
            if(d-painted >= (arr[i+1].t-arr[i].t)*arr[current_worker].y){
                painted+=(arr[i+1].t-arr[i].t)*arr[current_worker].y;
            }else{

            }
        }
    }
    //once more for i == n-1
    
    delete[] arr;
    return 0;
}