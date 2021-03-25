#include <iostream>
using namespace std;

int check(char ** grid, int n, int m, int i, int j, string str, int index, int x, int y){
    if(index >= str.length()){
        return 1;
    }
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j] != str[index]){
        return 0;
    }
    return check(grid, n, m, i+x, j+y, str, index+1, x, y);
}

void solve(){
    int n, m;
    cin>>n>>m;
    char ** grid = new char*[n];
    for(int i = 0; i<n; i++){
        grid[i] = new char[m];
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    string str;
    int global_count = 0;
    cin>>str;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int dir1[8] = {0, 1, 1, 1, 0, -1, -1, -1};
            int dir2[8] = {1, 1, 0, -1, -1, -1, 0, 1};
            int cnt = 0;
            for(int k = 0; k<8; k++){
                cnt += check(grid, n, m, i, j, str, 0, dir1[k], dir2[k]);
            }
            if(cnt){
                cout<<i<<" "<<j<<", ";
                global_count++;
            }
        }
    }
    if(!global_count){
        cout<<-1;
    }
    cout<<endl;
}


int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}