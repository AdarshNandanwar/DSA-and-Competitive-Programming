Please use this Google doc during your interview (your interviewer will see what you write here). To free your hands for typing, we recommend using a headset or speakerphone.

We would like to design an alerting system for a server. The input to the system is error rates of the server over time. For example, 5, 10, 7, 15, 0, 60, 55, 60, 60, 60, 0, 5, 5 will be interpreted as the server having an error rate of 5% during the 1st second, 10% during the 2nd second, 7% during the 3rd second, and so on.


We would like to know if the server was unhealthy at a given time p: please write a program that returns True iff there is an interval of s seconds that includes p and during which the error rate is never below r. The input consists of an array of error rates, and the values for p, s and r.

5, 10, 7, 15, 0, 60, 55, 60, 60, 60, 0, 5, 5

P = 6, s=3, r=50

q = {6, 7}
i = 7 -> 60

10 9 8 7 6 5 4 3 2 1 
S = 10


bool solve(vector<int> v, int p, int s, int r){
	if(s == 0) return false;
	int n = v.size();
	deque<int> q;
	int k = max(0, p-s+1);
	for(int cnt = 0; cnt<s and k<n; cnt++){
		while(!q.empty() and v[q.back()] >= v[k]){
			q.pop_back();
		}
		q.push_back(k);
		k++;
	}
	if(v[q.front()] >= r) return true;
	for(int i = min(n-1, p+1); i<p+s; i++){
		while(!q.empty() and v[q.back()] >= v[i]){
			q.pop_back();
		}
		q.push_back(i);
		if(i-q.front() >= s) q.pop_front();
		if(v[q.front()] >= r) return true;
	}
	return false;
}




Imagine two of your teammates have differing opinions on a project but decisions need to be made immediately. How would you help decide on an approach for the project?

What steps do you take in your job to ensure that you are building products that are accessible for all types of users?
