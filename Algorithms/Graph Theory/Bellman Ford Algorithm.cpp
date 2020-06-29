// Bellman Ford Algorithm

vector<int> bellmanFord(int n, vector<vector<int>> & edges){

	// {w, v}
	vector<vector<pair<int, int>>> adjList(n);
	for(auto e:edges){
		adjList[e[0]].push_back({e[2], e[1]});
	}
	bool noChange;

	vector<int> sp(n, INT_MAX);
	sp[0] = 0;

	for(int i = 0; i<n-1; i++){
		noChange = true;
		for(int j = 0; j<n; j++){
			if(sp[j] == INT_MAX) continue;
			for(auto nbr:adjList[j]){
				sp[nbr.second] = min(sp[nbr.second], sp[j]+nbr.first);
				noChange = false;
			}
		}
		if(noChange) break;
	}

	return sp;
}