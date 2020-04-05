#include <stdio.h>
#include <string.h>
int ladukafunction(char a[])
{
	
	
	int ladu=0,bonus=0,b=0;
	
	if(strcmp(a,"CONTEST_WON")==0)
	{
		ladu=300;
        scanf("%d",&b);
		if(b<20 && b>0)
		{
			bonus=20-b;
		}
		ladu=ladu+bonus;
		return ladu;
	}
	else if(strcmp(a,"TOP_CONTRIBUTOR")==0)
	{
		ladu=300;
		return ladu;
	}
	else if(strcmp(a,"BUG_FOUND")==0)
	{
	    scanf("%d",&b);
		ladu=b;
		return ladu;
	}
	else if(strcmp(a,"CONTEST_HOSTED")==0)
	{
		return 50;
	}

	return 0;
}
int main(void) {
	int t=0;
	char nation[10];
	
	scanf("%d",&t);
	while(t>0)
	{
		int ladu=0,act;
		scanf("%d",&act);
		scanf("%s",nation);
		
		char a[10];
		while(act>0)
		{
			scanf("%s",a);
		    ladu=ladu+ladukafunction(a);
			act--;
		}
	
		int ans=0;
		if(strcmp(nation,"INDIAN")==0)
		{
			ans=ladu/200;
			printf("%d\n",ans);
		}
		else
		{
			ans=ladu/400;
			printf("%d\n",ans);
		}
		t--;
	}
	// your code goes here
	return 0;
}
