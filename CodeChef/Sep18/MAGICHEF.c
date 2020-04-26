#include<iostream>
using namespace std;

int main()
{
	long T,N,X,S,arr[100],a,b;
	cin>>T;
	
	for(int i=0;i<T;i++)
	{
		scanf("%d %d %d", &N, &X, &S);
		for(int j=0; j<S; j++)
		{
			scanf("%d %d", &a, &b);
			if (a==X)
				X=b;
			else
				if (b==X)
					X=a;
		}
		cout<<X;
	}
}