/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void findArticulationPoints(vector<vector<int>> adjList, int cur, int curLevel, vector<int> & level, vector<int> & low, int parent, vector<int> & articulationPoints){

	int independentChildren = 0;
	level[cur] = low[cur] = curLevel;	// level acts as visited
	bool mayBeAtriculationPoint = 0;

	for(auto nbr:adjList[cur]){
		if(nbr == parent) continue;
		if(level[nbr] == INT_MAX){		// not visited
			independentChildren++;
			findArticulationPoints(adjList, nbr, curLevel+1, level, low, cur, articulationPoints);
			if(level[cur] <= low[nbr]){
				mayBeAtriculationPoint = 1;
			}
		}
		low[cur] = min(low[cur], low[nbr]);
	}

	if(mayBeAtriculationPoint){
		if(parent == -1){
			if(independentChildren >= 2) articulationPoints.push_back(cur);
		} else {
			articulationPoints.push_back(cur);
		}
	}
}

void findBridges(vector<vector<int>> & adjList, int cur, int curLevel, vector<int> & level, vector<int> & low, int parent, vector<vector<int>> & bridges){
    
    level[cur] = low[cur] = curLevel;     // visited is also set here
    for(auto nbr:adjList[cur]){
        if(parent == nbr) continue;
        if(level[nbr] == INT_MAX){       // not visited
            findBridges(adjList, nbr, curLevel+1, level, low, cur, bridges);
            if(level[cur] < low[nbr]){  // bridge found
                bridges.push_back({cur, nbr});
            }
        } 
        low[cur] = min(low[cur], low[nbr]);
    }
}

int main(){

	int n, m, src, dest;
	cin>>n>>m;
	vector<vector<int>> adjList(n);
	for(int i = 0; i<m; i++){
		cin>>src>>dest;
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}
	
	vector<int> articulationPoints, level, low;
    level = vector<int>(n, INT_MAX); 
    low = vector<int>(n, INT_MAX);
	findArticulationPoints(adjList, 0, 0, level, low, -1, articulationPoints);

    vector<vector<int>> bridges; 
    level = vector<int>(n, INT_MAX); 
    low = vector<int>(n, INT_MAX);
    findBridges(adjList, 0, 0, level, low, -1, bridges);

    sort(articulationPoints.begin(), articulationPoints.end());
    for(auto & i:bridges) if(i[0] > i[1]) swap(i[0], i[1]);
    sort(bridges.begin(), bridges.end(), [](const vector<int> & a, const vector<int> & b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });
    
    cout<<articulationPoints.size()<<endl;
    for(auto i:articulationPoints) cout<<i<<" "; cout<<endl;
    cout<<bridges.size()<<endl;
    for(auto i:bridges) cout<<i[0]<<" "<<i[1]<<endl;

	return 0;
}