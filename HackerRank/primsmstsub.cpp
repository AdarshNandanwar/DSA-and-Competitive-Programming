#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<string> split_string(string);

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
    
    vector<pair<ll, ll>> e[n];
    for (ll i = 0; i < edges.size(); i++)
    {
        ll v1 = edges[i][0]-1 , v2 = edges[i][1]-1 , w = edges[i][2];
        e[v1].push_back(make_pair(v2, w));
        e[v2].push_back(make_pair(v1, w));
    }
    
    start--;
    ll cost = 0;
    vector<ll> v;
    bool * visited = new bool[n];
    for (ll i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    visited[start] = true;

    n--;
    v.push_back(start);
    while(n--){
        ll min_cost = 1000000, min_node = -1;
        vector<ll> ::iterator itr;
        for(itr = v.begin(); itr!= v.end(); itr++){
            vector<pair<ll, ll>>::iterator edge_itr;
            for(edge_itr = e[*itr].begin(); edge_itr!= e[*itr].end(); edge_itr++){
                if(visited[edge_itr->first]){
                    continue;
                } else {
                    if(min_cost > edge_itr->second){
                        min_cost = edge_itr->second;
                        min_node = edge_itr->first;
                    }
                }
            }
        }
        visited[min_node] = true;
        v.push_back(min_node);
        cost += min_cost;
    }
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
