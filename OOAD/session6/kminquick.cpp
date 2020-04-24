#include<stdio.h>
void quick(int a[],int i,int j,int k);
int main()
{
	int n,k,i;
	printf("\nEnter size: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("\nElement %d: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nEnter k: ");
	scanf("%d",&k);
	if(k>n)
	return 0;
	quick(a,0,n-1,k);
	for(i=0;i<k;i++)
	printf("\nElement %d: %d",i+1,a[i]);
	return 1;
}
void quick(int a[],int i,int j,int k)
{
	int m=i;
	while(a[m]<=a[j] && m<j)
	m++;
	int v=m+1;
	while(v<j+1)
	{
		if(a[v]<=a[j])
		{
			a[m]=a[m]^a[v];
			a[v]=a[m]^a[v];
			a[m]=a[m]^a[v];
			m++;
		}
		v++;
	}
	if(m<k-1)
	quick(a,m,j,k);
	else if(m>k-1)
	quick(a,i,m-2,k);
}
