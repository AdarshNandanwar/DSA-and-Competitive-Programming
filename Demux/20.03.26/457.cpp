#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;


bool circularArrayLoop(vector<int>& nums) {
    int slow, fast;
    int n = nums.size();
    if(!n){
        return false;
    }
    bool * visited = new bool[n]();
    for(int i = 0; i < n; i++){
        if(visited[i])
            continue;
        int slow = i, fast = i;
        if(nums[i] > 0){
            do{
                int old_slow = slow;
                slow = ((slow+nums[slow])%n);
                fast = ((fast+nums[fast])%n);
                fast = ((fast+nums[fast])%n);
                visited[slow] = true;
                visited[fast] = true;
                if(nums[slow] <= 0 || nums[fast] <= 0 || slow == old_slow){
                    return false;
                }
            }while(slow != fast);
            return true;
        } else if(nums[i] < 0){
            do{
                int old_slow = slow;
                slow = ((slow+nums[slow]+n)%n);     //Imp to do +n, else out of bounds
                fast = ((fast+nums[fast]+n)%n);     //Imp to do +n, else out of bounds
                fast = ((fast+nums[fast]+n)%n);     //Imp to do +n, else out of bounds
                visited[slow] = true;
                visited[fast] = true;
                if(nums[slow] >= 0 || nums[fast] >= 0 || slow == old_slow){
                    return false;
                }
            }while(slow != fast);
            return true;
        } else {
            return false;
        }
    }
    delete [] visited;
    return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v = {1,-2};
    cout<<circularArrayLoop(v)<<endl;
    return 0;
}