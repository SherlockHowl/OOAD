#include<stdio.h>
int a[10000];
int count(int i,int j);
int main()
{
	int n,i;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	if(n<1)
	return -1;
	printf("Enter First term: ");
	scanf("%d",&a[0]);
	for(i=1;i<n;i++)
	{
		printf("Enter the next term: ");
		scanf("%d",&a[i]);
	}
	i=count(0,n-1);
	printf("Count: %d",i);
	return i;
}
int count(int i,int j)
{
	if(j!=i)
	return count(i,(i+j)/2)+count(1+(i+j)/2,j);
	else
	return a[i];
}
