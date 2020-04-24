#include<stdio.h>
int main()
{
	int i,j,n,k,l,counter;
	k=0;
	l=0;
	printf("Enter value of n: ");
	scanf("%d",&n);
	int prime[n];
	int comp[n];
	if(n>0)
	{
	comp[0]=1;
	l++;
	}
	for(i=2;i<=n;i++)
	{
		counter=0;
		for(j=2;i>=j*j;j++)
		{
			if(i%j==0)
			{
				counter=1;
				break;
			}
		}
		if(counter==0)
		{
			prime[k]=i;
			k++;
		}
		else
		{
			comp[l]=i;
			l++;
		}
	}
	printf("Prime Nos: ");
	for(i=0;i<k;i++)
	printf("%d,",prime[i]);
	printf("\nNot prime Nos: ");
	for(i=0;i<l;i++)
	printf("%d,",comp[i]);
	return 1;
}
