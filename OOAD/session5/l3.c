#include<stdio.h>
#include<stdlib.h>
struct arr
{
	int size,min;
	int a[1000];
};
struct arr* pa[100];
void main()
{
	int k,i,j,l,temp;
	int n=0;
	struct arr* tya=NULL;
	printf("Enter no. of arrays: ");
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		pa[i]=malloc(sizeof(struct arr));
		printf("Enter array %d size: ",i+1);
		scanf("%d",&temp);
		if(temp<1)
		{
			pa[i]->size=0;
			pa[i]->min=-1;
		}
		else
		{
			pa[i]->size=temp;
			pa[i]->min=0;
			n=n+temp;
		}
		for(j=0;j<(pa[i]->size);j++)
		{
			printf("Element %d-%d: ",i+1,j+1);
			scanf("%d",&temp);
			pa[i]->a[j]=temp;
		}
	}
	int result[n];
	for(j=0;j<n;j++)
	{
		l=-1;
		for(i=0;i<k;i++)
		{
			if(pa[i]->size>pa[i]->min && pa[i]->min > -1)
			{
				if(l<0)
				l=i;
				else if((pa[i]->a[pa[i]->min])<(pa[l]->a[pa[l]->min]))
				l=i;
			}
		}
		result[j]=pa[l]->a[pa[l]->min];
		pa[l]->min=pa[l]->min +1;
	}
	for(i=0;i<n;i++)
	printf("%d_",result[i]);
}
