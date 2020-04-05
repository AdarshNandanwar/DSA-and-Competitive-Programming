//Find the minimum of stack in O(1) time and O(1) space
 
#include<bits/stdc++.h>
using namespace std;
  
  
int main()
{
  int n;
  cin >> n;
  stack<int> q;
  int mn;
  for(int i=0; i<n; i++)
  {
    int l, r;
    cin >> l;
    if(l==1)
    {
      cin >> r;
      if(q.size()==0)
        q.push(r), mn = r;
      else
      {
        if(r<mn)
          q.push(2*r-mn), mn = r;
        else
          q.push(r);
      }
    }
    else
    {
      if(q.top()<mn)
      {
        mn = 2*mn - q.top();
        q.pop();
      }
      else
        q.pop();
    }
  
    if(q.size())
      cout << mn << endl;
    else
      cout << "Not exits" << endl;
  }
}
  
  
/*
10
1 5
1 10
1 4
1 3
1 -10
2
2
2
2
2
*/