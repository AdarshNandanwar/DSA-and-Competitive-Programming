// https://www.interviewbit.com/problems/word-ladder-ii/

bool is_nbr(const string & a, const string & b){
    if(a.length() != b.length()) return 0;
    int count = 0;
    for(int i = 0; i<a.length(); i++){
        if(a[i]!=b[i]) count++;
        if(count > 1) return 0;
    }
    return count == 1;
}

void generate(int x, unordered_map<int, unordered_set<int>> & prev, vector<vector<string>> & ans, vector<string> & cur, vector<string> & sv){
    if(x == -1){
        ans.push_back(cur);
        return;
    }
    cur.push_back(sv[x]);
    for(auto &i:prev[x]){
        generate(i, prev, ans, cur, sv);
    }
    cur.pop_back();
}

vector<vector<string>> Solution::findLadders(string start, string end, vector<string> &dict) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_set<string> s(dict.begin(), dict.end());
    s.insert(start);
    s.insert(end);
    dict.clear();
    for(auto &i:s) dict.push_back(i);
    int n = dict.size(), st_index = 0, end_index = 0;
    vector<vector<int>> adj(n, vector<int>(0));
    vector<bool> visited(n, 0);
    for(int i = 0; i<n; i++){
        if(dict[i] == start) st_index = i;
        if(dict[i] == end) end_index = i;
        for(int j = 0; j<n; j++){
            if(i!=j and is_nbr(dict[i], dict[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    unordered_map<int, unordered_set<int>> prev;
    vector<vector<string>> ans;
    queue<int> q;
    q.push(st_index);
    visited[st_index] = 1;
    prev[st_index] = {-1};
    while(1){
        bool found = 0;
        unordered_set<int> to_remove;
        if(q.empty()) return {};
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            if(cur == end_index){
                found = 1;
                break;
            } 
            for(auto &nbr:adj[cur]){
                if(!visited[nbr]){
                    to_remove.insert(nbr);
                    prev[nbr].insert(cur);
                }
            }
        }
        if(found) break;
        for(auto &d:to_remove){
            q.push(d);
            visited[d] = 1;
        }
    }
    // generate ans
    vector<string> temp = {};
    generate(end_index, prev, ans, temp, dict);
    for(auto &i:ans) reverse(i.begin(), i.end());
    return ans;
}
