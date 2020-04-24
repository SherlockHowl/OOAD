#include<stdio.h>

void main()
{
	int i,j,temp,k,n;
	int a[1000];
	printf("Enter the array size: ");
	scanf("%d",&n);
	printf("Enter the array: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		temp=a[0];
		k=0;
		for(j=1;j<n-i;j++)
		{
			if(a[j]>temp)
			{
				temp=a[j];
				k=j;
			}
		}
		a[k]=a[j-1];
		a[j-1]=temp;
	}
	for(i=0;i<n;i++)
	printf("%d",a[i]);
}
