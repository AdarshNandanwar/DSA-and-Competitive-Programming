// https://leetcode.com/problems/verifying-an-alien-dictionary/

// Method 1 (TSP, Last Case logic not clear, strategy of selecting max overlap path if the weight are equal passes the test case. but not sure why):

class Solution {
public:
    
    int get_overlap(string i, string j){
        if(i == j) return 0;
        int li = i.length(), lj = j.length(), res = 0;
        for(int k = 0; k<=min(li, lj); k++){
            if(i.substr(li-k, k) == j.substr(0, k)) res = k;
        }
        return res;
    }
    
    void get_subsets(int n, int start, vector<int> & cur, vector<vector<int>> & subsets){
        if(start == n) return;
        for(int i = start; i<n; i++){
            cur.push_back(i);
            subsets.push_back(cur);
            get_subsets(n, i+1, cur, subsets);
            cur.pop_back();
        }
    }
    
    string get_key(vector<int> via, int dest){
        string s = "";
        sort(via.begin(), via.end());
        for(auto & i:via){
            if(i == dest) continue;
            s += (to_string(i)+",");
        } 
        return s+"|"+to_string(dest);
    }
    
    string merge(vector<string> & v){
        string res = v[0];
        for(int i = 1; i<v.size(); i++){
            res += v[i].substr(get_overlap(v[i-1], v[i]));
        }
        return res;
    }
    
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        if(n == 1) return words[0];
        
        // construct graph
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                graph[i][j] = words[j].length()-get_overlap(words[i], words[j]);
            }
        }
        
        // create subsets
        vector<vector<int>> subsets = {{}};
        vector<int> cur;
        get_subsets(n, 1, cur, subsets);
        for(auto & i:subsets) sort(i.begin(), i.end());
        sort(subsets.begin(), subsets.end(), [](const vector<int> & a, const vector<int> & b){
            return a.size() == b.size() ? a<b : a.size()<b.size(); 
        });
        
        
        // Held Karp Algorithm, start = 0
        
        // {cost, parent}
        unordered_map<string, pair<int, int>> m;
        for(auto & subset:subsets){
            for(int i = 1; i<n; i++){
                if(find(subset.begin(), subset.end(), i) == subset.end()){
                    int cost = INT_MAX, parent = -1, overlap = 0;
                    if(subset.size() == 0){
                        cost = graph[0][i];
                        parent = 0;
                    }
                    for(auto & j:subset){
                        int cur_cost = graph[j][i]+m[get_key(subset, j)].first;
                        if(cur_cost < cost){
                            cost = cur_cost;
                            parent = j;
                        } else if(cur_cost == cost and get_overlap(words[j], words[i]) > overlap){
                            cost = cur_cost;
                            parent = j;
                            overlap = get_overlap(words[j], words[i]);
                        }
                    }
                    m[get_key(subset, i)] = {cost, parent};
                }
            }
        }
        
        // going back to 0 to make a cycle
        vector<int> subset = subsets.back();
        int cost = INT_MAX, parent, overlap = 0;
        for(auto & j:subset){
            int cur_cost = graph[j][0]+m[get_key(subset, j)].first;
            if(cur_cost < cost){
                cost = cur_cost;
                parent = j;
            } else if(cur_cost == cost and get_overlap(words[j], words[0]) > overlap){
                cost = cur_cost;
                parent = j;
                overlap = get_overlap(words[j], words[0]);
            }
        }
        m[get_key(subset, 0)] = {cost, parent};
        
        
        // constructing hamiltonian cycle
        vector<int> order;
        int cur_index = 0;
        for(int i = 0; i<n; i++){
            parent = m[get_key(subset, cur_index)].second;
            order.push_back(parent);
            subset.erase(remove(subset.begin(), subset.end(), parent), subset.end());
            cur_index = parent;
        }
        
        reverse(order.begin(), order.end());
        
        // breaking at the point of lowest overlap
        int start = -1;
        cost = INT_MAX;
        for(int i = 0; i<n; i++){
            if(cost > get_overlap(words[order[i]], words[order[(i+1)%n]])){
                cost = get_overlap(words[order[i]], words[order[(i+1)%n]]);
                start = (i+1)%n;
            }
        }
        
        vector<string> optimal;
        for(int i = 0; i<n; i++){
            optimal.push_back(words[order[(start+i)%n]]);
        }
        
        return merge(optimal);
    }
};