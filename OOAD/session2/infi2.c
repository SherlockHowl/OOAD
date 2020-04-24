#include<stdio.h>
void main()
{
	int a[10000];
	int temp,n;
	printf("Enter array:");
	for(int i=0;i<10000;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==-1)
		{
			while(i<10000)
			{
				a[i]=-1;
				i++;
			}
		}
	}
	n=0;
	while(a[n]!=-1)
	n++;
	printf("Position: %d",n+1);
}
