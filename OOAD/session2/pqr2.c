#include<stdio.h>
void main()
{
	int a[10000];
	int n,r,p,q;
	int counter=0;
	printf("Size of array: ");
	scanf("%d",&n);
	printf("Enter the array: ");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the search term: ");
	scanf("%d",&r);
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			a[j]=a[j]^a[j+1];
			a[j+1]=a[j]^a[j+1];
			a[j]=a[j]^a[j+1];
		}
	}
	p=0;
	q=n-1;
	while(p!=q)
	{
		if(r<(a[p]+a[q]))
		q--;
		else if(r>(a[p]+a[q]))
		p++;
		else if(r==a[p]+a[q])
		break;
	}
	if(p==q)
	printf("NOT found");
	else
	printf("Found");
}
