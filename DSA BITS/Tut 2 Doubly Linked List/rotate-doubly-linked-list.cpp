// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
struct node* update(struct node*start,int p);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        struct node*start = NULL;
        struct node* cur = NULL;
        struct node* ptr = NULL;
        
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            ptr=new node(a);
            ptr->data=a;
            ptr->next=NULL;
            ptr->prev=NULL;
            if(start==NULL)
            {
                start=ptr;
                cur=ptr;
            }
            else
            {
                cur->next=ptr;
                ptr->prev=cur;
                cur=ptr;
            }
        }
        struct node*str=update(start,p);
        while(str!=NULL)
        {
            cout<<str->data<<" ";
            str=str->next;
        }
        cout<<endl;  
    }
}

 // } Driver Code Ends
//User function Template for C++

/*
struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

struct node*update(struct node*start,int p)
{
    //Add your code here
    
    int len = 0;
    
    node * last = NULL;
    node * curr = start;
    while(curr != NULL){
        last = curr;
        curr = curr->next;
        len++;
    }
    
    if(p == len){
        return start;
    }
    
    last->next = start;
    start->prev = last;
    
    
    curr = start;
    
    for(int i = 0; i< p;i++){
        curr = curr->next;
    }
    
    curr->prev->next = NULL;
    curr->prev = NULL;
    
    return curr;
}

// { Driver Code Starts.
  // } Driver Code Ends