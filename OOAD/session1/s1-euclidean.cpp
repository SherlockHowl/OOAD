#include<stdio.h>
int gcd(int a, int k);
int gcdb(int a, int b);
int main()
{
	int k,a;
	int b=1;
	printf("\nEnter no. of terms:");
	scanf("%d",&k);
	if(k>0)
	{
		printf("Enter First term:");
		scanf("%d",&a);
		k--;
		if(a<0)
		a=a*-1;
		if(k==0)
		printf("Gcd: %d",a);
		else
		{
			a=gcd(a,k);
			if(a==0)
			printf("Undefined\n");
			else
			printf("Gcd: %d",a);
		}
	}
	else
	printf("Enter k>0");
    return 0;
}
int gcd(int a, int k)
{
	if(k>0)
	{
		int b;
		k--;
		printf("Enter next term:");
		scanf("%d",&b);
		if(b<0)
		b=b*-1;
		if(a>b)
		{
			a=a^b;
			b=a^b;
			a=a^b;
		}
		if(a==0)
		a=gcd(b,k);
		else
		a=gcd(gcdb(a,b),k);
	}
	return a;
}
int gcdb(int a, int b)
{
	if(b%a!=0)
	{
		b=b%a;
		a=gcdb(b,a);
	}
	return a;
}