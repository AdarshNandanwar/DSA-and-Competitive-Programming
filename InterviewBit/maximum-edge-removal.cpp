// https://www.interviewbit.com/problems/maximum-edge-removal/

// Method 1 (DFS, O(n)):

// { nodeCount, cutCount}
pair<int, int> helper(int n, vector<vector<int>> & adjList){
    int nodeCount = 1, evenChildCount = 0, cutCount = 0;
    for(auto child:adjList[n]){
        auto h = helper(child, adjList);
        nodeCount += h.first;
        if(h.first%2 == 0) evenChildCount++;
        cutCount += h.second;
    }
    return {nodeCount, evenChildCount+cutCount};
}

int Solution::solve(int A, vector<vector<int> > &B) {
    if(A%2) return 0;
    vector<vector<int>> adjList(A+1);
    for(auto i:B) adjList[i[0]].push_back(i[1]);
    return helper(1, adjList).second;
}
