#include<iostream>
using namespace std;

int main()
{
	int T,N,M,X,Y;
	cin>>T;
	
	for (int i=0; i<T; i++)
	{
		scanf("%d %d %d %d", &N, &M, &X, &Y);
		if ((N-1)%X==0 && (M-1)%Y==0 && (N-1)>=0 && (M-1)>=0)
			cout<<"Chefirnemo\n";
		else if ((N-2)%X==0 && (M-2)%Y==0 && (N-2)>=0 && (M-2)>=0)
			cout<<"Chefirnemo\n";
		else
			cout<<"Pofik\n";
	}
}