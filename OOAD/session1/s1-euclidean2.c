#include<stdio.h>
int gcd(int a, int b);
void main()
{
	int i=2;
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
		a=gcd(a,b);
		printf("\n GCD: %d",a);
	}
}
int gcd(int a, int b)
{
	if(b%a!=0)
	{
		b=b%a;
		a=gcd(b,a);
	}
	return a;
}
