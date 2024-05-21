# Algorithms
## Longest Increasing Subsequence (LIS) in O(nlogn)
```cpp
int getLIS(vector<int> * v){
    vector<int> tails;
    for(auto &i:v){
        auto itr = lower_bound(tails.begin(), tails.end(), i);
        if(itr == tails.end()) tails.push_back(i);
        else *itr = i;
    }
    return tails.size();
}
```
## Implicit BFS - Covering the range
```cpp
int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n <= 1) return 0;
    
    int count = 0, pos = 0, curRange = 0, nextRange = 0;
    
    while(1){
        while(pos <= curRange){
            nextRange = max(nextRange, A[pos]+pos);
            pos++;
        }
        
        if(nextRange >= n-1) return count+1;
        
        if(curRange == nextRange) return -1;
        curRange = nextRange;
        count++;
    }
    return count;
}
```
## Sieve of Eratosthenes
```cpp
for (int p = 2; p * p <= n; p++){
    if (prime[p] == false) continue;
    for (int i = p * p; i <= n; i += p) 
        prime[i] = false;
}
```
## KMP (Knuth–Morris–Pratt algorithm) Algorithm
```cpp
vector<int> get_lps(string s){
int n = s.length();
	vector<int> lps(n, 0);
	int i = 1;
    int j = lsp[i-1];
    while(i<n){
        if(s[i] == s[j]){
            lps[i++] = j+1;
            j = lps[i-1];
        } else {
            if(j == 0) i++;
            else j = lps[j-1];
        }
    }
    return lps;
}
int kmp(string s, string p){
	vector<int> lps = get_lps(p);
	int n = s.length(), m = p.length(), i = 0, j = 0;
	while(true){
		while(i<n and j<m and s[i] == p[j]){
			i++; j++;
        }
        if(j == m) return i-m;
        if(i == n) return -1;
        if(j == 0) i++;
        else j = lps[j-1];
    }
}
```
## Manacher's Algorithm
```cpp
// add implementation here
```
## Serialization, Deserialization of Binary Tree
```cpp
string serialize(TreeNode* root) {
    string s;
    serializeHelper(root, s);
    return s;
}
void serializeHelper(TreeNode* root, string & s) {
    if(!root){
        s += ("#,");
    } else {
        s += (to_string(root->val)+",");
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }
}
TreeNode* deserialize(string data) {
    istringstream iss(data);
    return deserializeHelper(iss);
}
TreeNode * deserializeHelper(istringstream & iss) {
    string token;
    getline(iss, token, ',');
    if(token == "#") return NULL;
    TreeNode * root = new TreeNode(stoi(token));
    root->left = deserializeHelper(iss);
    root->right = deserializeHelper(iss);
    return root;
}
```
## Submask Enumeration 
```cpp
for(int submask=mask; submask>0; submask=((submask-1)&mask)){}
```
