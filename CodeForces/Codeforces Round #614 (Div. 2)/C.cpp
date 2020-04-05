#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n, q, blocks = 0;
    cin>>n>>q;

    bool ** maze = new bool*[2];
    for (ll i = 0; i < 2; i++)
    {
        maze[i] = new bool[n]();
    }
    bool * blockList = new bool[n+1]();
    

    for (ll i = 0; i < q; i++)
    {
        ll r, c;
        cin>>r>>c;
        r--; c--;


        maze[r][c] ^= 1;
        if(c != 0){
            if((maze[r][c] == false && maze[r][c-1] == false) || (maze[r^1][c] == false && maze[r^1][c-1] == false)){
                if(blockList[c-1]){
                    blocks--;
                }
                blockList[c-1] = false;
            } else {
                if(!blockList[c-1]){
                    blocks++;
                }
                blockList[c-1] = true;
            }
        }
        if(c != n-1){
            if((maze[r][c] == false && maze[r][c+1] == false) || (maze[r^1][c] == false && maze[r^1][c+1] == false)){
                if(blockList[c]){
                    blocks--;
                }
                blockList[c] = false;
            } else {
                if(!blockList[c]){
                    blocks++;
                }
                blockList[c] = true;
            }
        }

        // for (ll i = 0; i < n-1; i++)
        // {
        //     cout<<blockList[i]<<" ";
        // }cout<<endl;
        // cout<<blocks<<endl;

        if(blocks){
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
        }



    }
    
    for (ll i = 0; i < 2; i++)
    {
        delete [] maze[i];
    }
    
    delete [] maze;
    delete [] blockList;


    return 0;
}