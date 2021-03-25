//Next Greater Element
 
#include<bits/stdc++.h>
using namespace std;
  
  
  
signed main()
{
  stack<int> q;
  int n;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; i++)
    cin >> arr[i];
  int ans[n];
  for(int i=0; i<n; i++)
    ans[i] = -1;
  for(int i=0; i<n; i++)
  {
      while(q.size() and arr[i]>arr[q.top()])
        ans[q.top()] = i, q.pop();
      q.push(i);
  }
  
  for(int i=0; i<n; i++)
    cout << ans[i] << " ";  
  
  cout  << endl;
  for(int i=0; i<n; i++)
  if(ans[i]!=-1)
    cout << arr[ans[i]] << " ";
  else
    cout << -1 << " ";
}
  
/*
5
1 2 3 4 5
*/
  
/*
6
9 1 5 2 4 10
*/