#include<stdio.h>
#include<iostream>
using namespace std;
int infi(int a[]);
int main()
{
	int a[10000];
    int temp;
	printf("Enter array:");
	for(int i=0;i<10000;i++)
	{
		scanf("%d",&temp);
        a[i]=temp;
		if(a[i]==-1)
		{
			while(i<10000)
			{
				a[i]=-1;
				i++;
			}
		}
	}
    temp=infi(a);
	printf("Position: %d",temp+1);
    return 0;
}
int infi(int a[])
{
    int n=1;
	while(a[n-1]!=-1)
	n=2*n;
	int start=(n)/2;
	int last=n;
	n=n/4;
	int mid=start+n;
	while(a[mid-1]!=-1||a[mid-2]==-1)
	{
		if(a[mid-1]==-1 && a[mid-2]==-1)
		{
			last=mid;
			n=n/2;
			mid=last-n;
		}
		else if(a[mid]!=-1)
		{
			start=mid;
			n=n/2;
			mid=start+n;
		}
        if(a[mid]==-1 && a[mid-1]!=-1)
        break;
	}
    return mid;
}