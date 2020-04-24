#include<stdio.h>
void print1(int n);
void print2(int n);
void print3(int n);
void print4(int n);
void print5(int n);
void main()
{
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	print1(n);
	print2(n);
	print3(n);
	print4(n);
	print5(n);
}
void print1(int n)
{
	while(n>0)
	{
		for(int i=1;i<=n;i++)
		printf("%d",i);
		printf("\n");
		n--;
	}
}
void print2(int n)
{
	int i;
	int k=n-1;
	while(k>=0)
	{
		for(i=1;i<(n-k);i++)
		printf(" ");
		while(i<=n)
		{
			printf("%d",i);
			i++;
		}
		printf("\n");
		k--;
	}
}
void print3(int n)
{
	int k=n-2;
	while(k>-2)
	{
		for(int i=1;i<(n-k);i++)
		printf("%d",i);
		printf("\n");
		k--;
	}
}
void print4(int n)
{
	int i;
	int k=n+1;
	while(n>0)
	{
		for(i=1;i<n;i++)
		printf(" ");
		while(i<k)
		{
			printf("%d",i);
			i++;
		}
		printf("\n");
		n--;
	}
}
void print5(int n)
{
	int i;
	int k=1;
	int m=2*n-1;
	while(k<n)
	{
		for(i=1;i<m;i++)
		{
			if((i<k)^(i>m-k))
			printf(" ");
			else
			printf("%d",i);
		}
		printf("\n");
		k++;
	}
	k=1;
	while(k<n)
	{
		for(i=1;i<m;i++)
		{
			if((i>n+k-1)^(i<n-k))
			printf(" ");
			else
			printf("%d",i);
		}
		printf("\n");
		k++;
	}
}
