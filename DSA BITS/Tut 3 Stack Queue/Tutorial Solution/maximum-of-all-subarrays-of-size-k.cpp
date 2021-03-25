    //Find maximum of all subarrays of size k
	
	#include<bits/stdc++.h>
    using namespace std;
     
     
    int main()
    {
    	int n, k;
    	cin >> n >> k;
    	int arr[n];
    	for(int i=0; i<n; i++)
    		cin >> arr[i];
    	deque<pair<int,int>> q;
     
    	for(int i=0; i<k; i++)
    	{
    		int c = 0;
    		while(q.size() and arr[i]>=q.back().first)
    			c += q.back().second, q.pop_back();
    		q.push_back({arr[i], 1+c});
    	}
     
     
    	cout << q.front().first << " ";
    	for(int i=k; i<n; i++)
    	{
    		int c = 0;
    		while(q.size() and arr[i]>=q.back().first)
    			c += q.back().second, q.pop_back();
    		q.push_back({arr[i], 1+c});
    		q.front().second--;
    		if(q.front().second==0)
    			q.pop_front();
    		cout << q.front().first << " ";
    	}
    }
     
    /*
    10 3
    1 2 3 4 5 4 3 2 1 100
    */