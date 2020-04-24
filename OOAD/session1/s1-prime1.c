#include<stdio.h>
void main()
{
	int i=2;
	int j=1;
	int a,b;
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
		printf("\n Undefined");
		else
		printf("\nGcd: %d",b);
	}
	else
	{
		while(a>=i)
		{
			if(a%i==0 && b%i==0)
			{
				a=a/i;
				b=b/i;
				j=j*i;
			}
			else
			i++;
		}
		printf("\n GCD: %d",j);
	}
}
