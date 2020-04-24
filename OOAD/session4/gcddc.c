#include<stdio.h>
int gcd(int i,int j);
int gcdsub(int a,int b);
int gcdmain(int a,int b);
int a[10000];
int main()
{
	int n,i;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	if(n<1)
	return -1;
	printf("Enter First term: ");
	scanf("%d",&a[0]);
	if(n==1)
	{
		printf("GCD: %d",gcdsub(a[0],0));
		return a[0];
	}
	for(i=1;i<n;i++)
	{
		printf("Enter the next term: ");
		scanf("%d",&a[i]);
	}
	i=gcd(0,n-1);
	if(i==0)
	{
		printf("GCD: UNDEFINED\n");
		return -1;
	}
	else
	{
		printf("GCD: %d\n",i);
		return i;
	}
}
int gcd(int i,int j)
{
	if(i==j)
	return gcdsub(a[i],0);
	else
	return gcdsub(gcd(i,(i+j)/2),gcd(1+(i+j)/2,j));
}
int gcdsub(int a,int b)
{
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
	return b;
	else
	return gcdmain(a,b);
}
int gcdmain(int a,int b)
{
	if(b%a!=0)
	{
		b=b%a;
		a=gcdmain(b,a);
	}
	return a;
}
