#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[100001];
ll n;

int main(){
    ll t, total = 0, max_cost; 
    cin>>t;
    while(t--){
        ll cost;
        max_cost = INT_MIN;
        cin>>n;
        ll ** arr = new ll*[4];
        for (ll i = 0; i < 4; i++)
        {
            arr[i] = new ll[4]();
        }
        
        for (ll i = 0; i < n; i++)
        {
            char mov;
            ll time, m_id;
            cin>>mov>>time;
            if(mov == 'A'){
                m_id = 0;
            } else if (mov == 'B'){
                m_id = 1;
            } else if (mov == 'C'){
                m_id = 2;
            } else if (mov == 'D'){
                m_id = 3;
            }
            if(time == 12){
                time = 0;
            } else if(time == 3){
                time = 1;
            } else if(time == 6){
                time = 2;
            } else if(time == 9){
                time = 3;
            }
            arr[m_id][time]++;
        }       
        
        
        ll * show = new ll[4];
        cost = 0;
        show[0] = arr[0][0];
        show[1] = arr[1][1];
        show[2] = arr[2][2];
        show[3] = arr[3][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[0][0];
        show[1] = arr[1][1];
        show[2] = arr[3][2];
        show[3] = arr[2][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[0][0];
        show[1] = arr[2][1];
        show[2] = arr[1][2];
        show[3] = arr[3][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[0][0];
        show[1] = arr[2][1];
        show[2] = arr[3][2];
        show[3] = arr[1][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[0][0];
        show[1] = arr[3][1];
        show[2] = arr[1][2];
        show[3] = arr[2][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[0][0];
        show[1] = arr[3][1];
        show[2] = arr[2][2];
        show[3] = arr[1][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[1][0];
        show[1] = arr[0][1];
        show[2] = arr[2][2];
        show[3] = arr[3][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[1][0];
        show[1] = arr[0][1];
        show[2] = arr[3][2];
        show[3] = arr[2][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[1][0];
        show[1] = arr[2][1];
        show[2] = arr[0][2];
        show[3] = arr[3][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[1][0];
        show[1] = arr[2][1];
        show[2] = arr[3][2];
        show[3] = arr[0][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[1][0];
        show[1] = arr[3][1];
        show[2] = arr[0][2];
        show[3] = arr[2][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[1][0];
        show[1] = arr[3][1];
        show[2] = arr[2][2];
        show[3] = arr[0][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[2][0];
        show[1] = arr[0][1];
        show[2] = arr[1][2];
        show[3] = arr[3][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[2][0];
        show[1] = arr[0][1];
        show[2] = arr[3][2];
        show[3] = arr[1][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[2][0];
        show[1] = arr[1][1];
        show[2] = arr[0][2];
        show[3] = arr[3][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[2][0];
        show[1] = arr[1][1];
        show[2] = arr[3][2];
        show[3] = arr[0][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[2][0];
        show[1] = arr[3][1];
        show[2] = arr[0][2];
        show[3] = arr[1][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[2][0];
        show[1] = arr[3][1];
        show[2] = arr[1][2];
        show[3] = arr[0][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[3][0];
        show[1] = arr[0][1];
        show[2] = arr[1][2];
        show[3] = arr[2][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[3][0];
        show[1] = arr[0][1];
        show[2] = arr[2][2];
        show[3] = arr[1][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[3][0];
        show[1] = arr[1][1];
        show[2] = arr[0][2];
        show[3] = arr[2][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[3][0];
        show[1] = arr[1][1];
        show[2] = arr[2][2];
        show[3] = arr[0][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[3][0];
        show[1] = arr[2][1];
        show[2] = arr[0][2];
        show[3] = arr[1][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        
        
        
        cost = 0;
        show[0] = arr[3][0];
        show[1] = arr[2][1];
        show[2] = arr[1][2];
        show[3] = arr[0][3];
        sort(show, show+4);
        for (ll i = 0; i < 4; i++)
        {
            if(show[i] == 0){
                cost -= 100;
            } else {
                cost += (25*(i+1)*show[i]);
            }
        }
        max_cost = max(max_cost, cost);
        cout<<max_cost<<endl;
        total += max_cost;
    }
    cout<<total<<endl;
    return 0;
}