/*
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// s[st, end] = c(..)       inclusive
void helper(string & s, ll st, ll end, ll cur_col, unordered_map<ll, ll> & mid, unordered_map<ll, vector<char>> & col){
	if(st == end) return;
	col[cur_col].push_back(s[st]);
	helper(s, st+2, mid[st+1]-1, cur_col-1, mid, col);
	helper(s, mid[st+1], end-1, cur_col+1, mid, col);
}

void solve(){
	ll c;
	string s;
	cin>>c>>s;
	// mapping opening bracket to right subtree index
	unordered_map<ll, ll> mid;
	stack<ll> st;
	for(int i = 1; i<s.length(); i++){
		if(s[i] == '('){
			st.push(i);
		} else if(s[i] == ')'){
			st.pop();
		} else {
			if(!mid.count(st.top())){
				// left subtree
				mid[st.top()] = -1;
			} else {
				// right subtree
				mid[st.top()] = i;
			}
		}
	}

    // for(auto i:mid){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

	unordered_map<ll, vector<char>> col;

	helper(s, 0, s.length()-1, 0, mid, col);

    // for(auto i:col){
    //     cout<<i.first<<":";
    //     for(auto j:i.second) cout<<" "<<j; cout<<endl;
    // }

	if(col[c].empty()) cout<<"Common Gandhijee!\n";
	else {
		sort(col[c].begin(), col[c].end());
		for(auto i:col[c]) cout<<i; cout<<endl;
	}
}

int main(){

	ll t;
	cin>>t;
	while(t--){
		solve();
	}

	return 0;
}