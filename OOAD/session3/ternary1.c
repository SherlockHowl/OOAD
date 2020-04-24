#include<stdio.h>

void main()
{
	int i,temp,n;
	int a[1000];
	printf("Enter the array size: ");
	scanf("%d",&n);
	printf("Enter the array: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]=a[j]^a[j+1];
				a[j+1]=a[j]^a[j+1];
				a[j]=a[j]^a[j+1];
			}
		}
	}
	for(i=0;i<n;i++)
	printf("%d",a[i]);
}
