//DOUBTFULL
#include<stdio.h>
int lcm(int i,int j);
int lcmsub(int a,int b);
int gcdmain(int a,int b);
int a[10000];
int main()
{
	int n,i,k;
	k=1;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	if(n<1)
	return -1;
	printf("Enter First term: ");
	scanf("%d",&a[0]);
	if(n==1)
	{
		i=lcmsub(a[0],a[0]);
		printf("LCM: %d",i);
		return i;
	}
	for(i=1;i<n;i++)
	{
		printf("Enter the next term: ");
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		k=k*a[i];
	}	
	i=lcm(0,n-1);
	if(i==0)
	{
		printf("LCM: 0\n");
		return 0;
	}
	else
	{
		printf("LCM: %d\n",i);
		return i;
	}
}
int lcm(int i,int j)
{
	if(i==j)
	return lcmsub(a[i],0);
	else
	return lcmsub(lcm(i,(i+j)/2),lcm(1+(i+j)/2,j));
}
int lcmsub(int a,int b)
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
	return (a*b)/gcdmain(a,b);
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
