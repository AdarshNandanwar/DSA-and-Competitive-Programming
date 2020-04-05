#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {


    vector<int> e[1001];
    for (int i = 0; i < edges.size(); i++)
    {
        e[edges[i][0]].push_back(edges[i][1]);
        e[edges[i][1]].push_back(edges[i][0]);
    }

    bool visited[1001];
    for (int i = 0; i < 1001; i++)
    {
        visited[i] = false;
    }
    int level[1001];
    for (int i = 0; i < 1001; i++)
    {
        level[i] = -1;
    }

    queue<int> q;
    level[s] = 0;
    visited[s] = true;
    q.push(s);
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (int i = 0; i < e[curr].size(); i++)
        {
            if(!visited[e[curr][i]]){
                level[e[curr][i]] = level[curr] + 6;
                visited[e[curr][i]] = true;
                q.push(e[curr][i]);
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if(i != s) ans.push_back(level[i]);
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
