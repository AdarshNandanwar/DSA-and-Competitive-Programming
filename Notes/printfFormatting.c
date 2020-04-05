#include<stdio.h>
#include<math.h>
int main()
{
	printf("12345678901234567890\n");
	printf("%d\n",9876);
	printf("%6d\n",9876);
	printf("%2d\n",9876);
	printf("%-6d\n",9876);
	printf("%10d\n",12345);
	printf("%06d\n",9876);
	printf("%010d\n",12345);
	printf("%-10d\n",12345);
	printf("%10d\n",-12345);
	printf("%010d\n",-12345);
	printf("%0-10d\n",-12345);

	printf("\n\n");

	float y=98.7654;

	printf("%f\n",y);
	printf("%7.4f\n",y);
	printf("%7.2f\n",y);
	printf("%-7.2f\n",y);
	printf("%e\n",y);
	printf("%10.2e\n",y);
	printf("%11.4e\n",-y);
	printf("%-10.2e\n",y);
	printf("%07.2f\n",y);
	printf("%*.*f\n",7,2,y);

	printf("\n\n");

	char x='A';
	char name[20]="Anil  Kumar  Gupta";
	/* to print  column number*/
	printf("12345678901234567890\n");

	printf("%c\n%3c\n%5c\n",x,x,x);
	printf("%s\n",name);
	printf("%20s\n",name);
	printf("%20.10s\n",name);
	printf("%.5s\n",name);
	printf("%-20.10s\n",name);
	printf("%5s\n",name);

	printf("ASCII value of A is: %d\n", 'A');
	
	return 0;
}
