// https://leetcode.com/problems/3sum-with-multiplicity/

#define MOD 1000000007
typedef long long ll;

class Solution {
public:
    
    ll nC2(int n){
        ll t = (ll) n;
        return (t*(t-1)/2)%MOD;
    }
    
    ll nC3(int n){
        ll t = nC2(n);
        return (t*((ll)n-2)/3)%MOD;
    }
    
    int threeSumMulti(vector<int>& arr, int target) {
        
        vector<int> uarr;
        unordered_map<int, int> freq;
        
        for(auto i:arr){
            if(freq[i] == 0) uarr.push_back(i);
            freq[i]++;
        }
        
        sort(uarr.begin(), uarr.end());
        
        // uarr[i] is the last element of the sorted tuple 
        int ans = 0, temp, p1, p2;
        for(int i = 0; i<uarr.size(); i++){
            // cout<<"i: "<<uarr[i]<<" "<<ans<<endl;
            p1 = 0; p2 = i-1;
            // all unique
            while(p1<p2){
                if(uarr[p1]+uarr[p2] == target-uarr[i]){
                    ans = (ans+((freq[uarr[p1]]*freq[uarr[p2]])%MOD*freq[uarr[i]])%MOD)%MOD;
                    // cout<<uarr[p1]<<" "<<uarr[p2]<<" "<<uarr[i]<<" "<<(freq[uarr[p1]]*freq[uarr[p2]])%MOD<<endl;
                    p1++;
                } else if (uarr[p1]+uarr[p2] < target-uarr[i]){
                    p1++;
                } else {
                    p2--;
                }
            }
            
            // first and second element same
            temp = (target-uarr[i])/2;
            if((target-uarr[i])%2 == 0 and freq[temp]>1 and temp<uarr[i]){
                ans = (ans+(nC2(freq[temp])*freq[uarr[i]])%MOD)%MOD;
                // cout<<temp<<" "<<temp<<" "<<uarr[i]<<" "<<freq[temp]*nC2(freq[uarr[i]])<<endl;
            }            
            
            // uarr[i] repeated 2 times
            temp = target-2*uarr[i];
            if(freq[temp] > 0 and freq[uarr[i]] > 1 and temp >= 0 and temp<uarr[i]){
                ans = (ans+(freq[temp]*nC2(freq[uarr[i]]))%MOD)%MOD;
                // cout<<temp<<" "<<uarr[i]<<" "<<uarr[i]<<" "<<freq[temp]*nC2(freq[uarr[i]])<<endl;
            }
            
            // uarr[i] repeated 3 times
            if(3*uarr[i] == target){
                ans = (ans+nC3(freq[uarr[i]]))%MOD;
                // cout<<uarr[i]<<" "<<uarr[i]<<" "<<uarr[i]<<" "<<nC3(freq[uarr[i]])<<" "<<uarr[i]<<endl;
            }
        }
        return ans;
    }
};