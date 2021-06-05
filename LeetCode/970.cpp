// https://leetcode.com/problems/powerful-integers/

// Method 1 (Brute Force):

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for(int i = 1; i<bound; i*=x){
            for(int j = 1; i+j<=bound; j*=y){
                s.insert(i+j);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        return vector<int>(s.begin(), s.end());
    }
};

// Method 1 (Brute Force, Alternate):

class Solution {
public:
    bool is_powerful(int x, int y, int num){
        for(int i = 1; i<num; i*=x){
            for(int j = 1; j<=num-i; j*=y){
                if(num-i == j) return 1;
            }
        }
        return 0;
    }
    
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(bound < 2) return {};
        vector<int> ans;
        if(x == 1 and y ==1) ans.push_back(2);
        else if (x == 1) for(int i = 1; i<= bound; i*=y) ans.push_back(1+i);
        else if (y == 1) for(int i = 1; i<= bound; i*=x) ans.push_back(1+i);
        else for(int i = 2; i<=bound; i++) if(is_powerful(x, y, i)) ans.push_back(i);
        return ans;
    }
};

// Method 2 (Ugly number modification, TLE):
// 2
// 2
// 400000

class Solution {
public:
    long long get_pow(int x, int y, int wx, int wy){
        return pow(x,wx)+pow(y, wy);
    }
    
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(bound < 2) return {};
        if(x == 1 and y == 1) return {2};
        if(x == 1){
            vector<int> ans;
            for(int i = 1; i<= bound; i*=y) ans.push_back(1+i);
            return ans;
        }
        if(y == 1){
            vector<int> ans;
            for(int i = 1; i<= bound; i*=x) ans.push_back(1+i);
            return ans;
        }
        // {power of x, power of y}
        vector<pair<int, int>> v(1, {0,0});
        unordered_set<int> ans = {2};
        int px = 0, py = 0, last = 0;
        while(max(px, py) < v.size()){
            // for(auto i:v) cout<<get_pow(x, y, i.first, i.second)<<" "; cout<<endl;
            int h1 = get_pow(x, y, v[px].first+1, v[px].second);
            int h2 = get_pow(x, y, v[py].first, v[py].second+1);
            // cout<<px<<" "<<get_pow(x, y, v[px].first, v[px].second)<<" ("<<v[px].first<<" "<<v[px].second<<"), "<<py<<" "<<get_pow(x, y, v[py].first, v[py].second)<<" ("<<v[py].first<<" "<<v[py].second<<")";
            pair<int, int> next;
            if(h1 < h2){
                next = {v[px].first+1, v[px].second};
                px++;
            } else {
                next = {v[py].first, v[py].second+1};
                py++;
            }
            if(min(h1, h2) > bound){
                // cout<<endl; 
                continue;
            }
            // cout<<", add "<<next.first<<" "<<next.second<<" "<<get_pow(x, y, next.first, next.second)<<endl;
            v.push_back(next);
            ans.insert(get_pow(x, y, next.first, next.second));
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
