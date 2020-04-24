#include<stdio.h>
void main()
{
	int a[10000];
	int n,r;
	int counter=0;
	printf("Size of array: ");
	scanf("%d",&n);
	printf("Enter the array: ");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the search term: ");
	scanf("%d",&r);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(r==a[i]+a[j])
			counter++;
		}
		if(counter>0)
		break;
	}
	if(counter>0)
	printf("There exists p+q=r");
	else
	printf("There does not exists p+q=r");
}
