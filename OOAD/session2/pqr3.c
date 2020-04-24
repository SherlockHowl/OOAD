#include<stdio.h>
void main()
{
	int a[10000];
	int b[10001];
	for(int i=0;i<10001;i++)
	b[i]=0;
	int n,r,p;
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
		p=a[i];
		b[p]=1;
		if(b[r-p]==1)
		{
			counter++;
			break;
		}
	}
	if(counter<1)
	printf("NOT found");
	else
	printf("Found");
}

