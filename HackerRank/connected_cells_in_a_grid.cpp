#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dfs(ll r, ll c, vector<vector<int>> & matrix, ll N, ll M){
    ll count = 1;
    matrix[r][c] = 0;
    ll X[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    ll Y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    for (ll i = 0; i < 8; i++)
    {
        if(0 <= r+Y[i] && r+Y[i] < N && 0 <= c+X[i] && c+X[i] < M && matrix[r+Y[i]][c+X[i]]){
            count += dfs(r+Y[i], c+X[i], matrix, N, M);
        }
    }
    return count;
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {

    ll ans = 0;
    ll N = matrix.size();
    ll M;
    if(N==0){
        return 0;
    } else {
        M = matrix[0].size();
    }

    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < M; j++)
        {
            if(matrix[i][j]){
                ans = max(ans, dfs(i, j, matrix, N, M));
            }
        }
    }

    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}

// int main()
// {
//     int n;
//     cin >> n;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     int m;
//     cin >> m;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     vector<vector<int>> matrix(n);
//     for (int i = 0; i < n; i++) {
//         matrix[i].resize(m);

//         for (int j = 0; j < m; j++) {
//             cin >> matrix[i][j];
//         }

//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }

//     int result = connectedCell(matrix);

//     cout << result << "\n";

//     return 0;
// }
