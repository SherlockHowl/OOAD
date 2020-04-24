#include<stdio.h>

void main()
{
	int i=2;
	int a,b;
	int d=0;
	printf("\n Enter number 1: ");
	scanf("%d",&a);
	printf("\n Enter number 2: ");
	scanf("%d",&b);
	if(a<0)
	a=a*-1;
	if(b<0)
	b=b*-1;
	if(a>b)
	{
		a=a^b;
		b=a^b;
		a=a^b;
	}
	if(a==0)
	{
		if(b==0)
		printf("\n Undefined\n");
		else
		printf("\nGcd: %d\n",b);
	}
	else
	{
		while(b%2==0 && a%2==0)
		{
			b=b/2;
			a=a/2;
			d++;
		}
		while(a!=b)
		{
			if(a%2==0)
			a=a/2;
			else if(b%2==0)
			b=b/2;
			else if(a>b)
			a=(a-b)/2;
			else if(b>a)
			b=(b-a)/2;
		}
		printf("\n GCD: %dx2^%d\n",a,d);
	}
}
