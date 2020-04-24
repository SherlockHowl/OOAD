#include<stdio.h>
#include<iostream>
using namespace std;
int pqr(int a[],int n,int r);
void sort(int a[],int n);
int main()
{
	int a[10000];
	int n,r,p;
	int counter=0;
	printf("Size of array: ");
	scanf("%d",&n);
	printf("Enter the array: ");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the search term: ");
	scanf("%d",&r);
    sort(a,n);
    p=pqr(a,n,r);
    if(p==0)
	printf("NOT found");
	else
	printf("Found");
    return 0;
}
void sort(int a[],int n)
{
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
                a[j]=a[j]^a[j+1];
			    a[j+1]=a[j]^a[j+1];
			    a[j]=a[j]^a[j+1];
            }
		}
	}
}
int pqr(int a[],int n,int r)
{
    int p=0;
	int q=n-1;
	while(p!=q)
	{
		if(r<a[p]+a[q])
		q--;
		else if(r>a[p]+a[q])
		p++;
		else
		break;
	}
	if(p==q)
    return 0;
    else
    return 1;
}

