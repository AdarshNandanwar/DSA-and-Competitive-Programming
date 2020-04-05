#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int decimal_to_binary(int a)
{
	int b=0, i=1;
	while(a!=0)
	{
		b+=(i*(a%2));
		a/=2;
		i*=10;
	}
	return b;
}

int binary_to_decimal(int a)
{
	int b=0, i=1;
	while(a!=0)
	{
		b+=((a%10)*i);
		a/=10;
		i*=2;
	}
	return b;
}

int bitwise_xor(int a, int b)
{
	int x=decimal_to_binary(a), y=decimal_to_binary(b), z=0, i=1;
	while(!(x==0 && y==0))
	{
		if((x%10==1 && y%10==0) || (x%10==0 && y%10==1))
			z=(i*1)+z;
		x/=10;
		y/=10;
		i*=10;
	}
	return binary_to_decimal(z);
}

int max_bitwise_xor(int n, int k)
{
	int max=0, b;
	for (int i = n; i <= k; ++i)
		for (int j = i; j <= k; ++j)
		{
			b=bitwise_xor(i,j);
			if(max<b)
				max=b;
		}
	return max;
}

void calculate_the_maximum(int n, int k) {
	printf("%d\n", max_bitwise_xor(n,k));
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
