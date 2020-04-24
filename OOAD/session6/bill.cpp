#include<stdio.h>
void main()
{
	int n,i,max,min;
	printf("Enter size: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i=i+2)
	{
		if(a[i]>a[i+1])
		{
			a[i]=a[i]^a[i+1];
			a[i+1]=a[i]^a[i+1];
			a[i]=a[i]^a[i+1];
		}
	}
	max=a[0];
	min=a[0];
	for(i=2;i<n;i=i+2)
	{
		if(a[i]<min)
		min=a[i];
	}
	for(i=1;i<n;i=i+2)
	{
		if(a[i]>max)
		max=a[i];
	}
	printf("Max: %d\nMin: %d",max,min);
}