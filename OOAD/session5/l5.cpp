#include<stdio.h>
#include<stdlib.h>
class heap
{
    public:
	struct arr* ya[100];
	int last;
};
class arr
{
    public:
	int size,min;
	int a[1000];
    arr* del();
    void insert(struct arr* key);
};
arr* pa[100];
heap H;
int main()
{
	H.last=0;
	int k,i,j,temp;
	int n=0;
	arr* tya=NULL;
	printf("Enter no. of arrays: ");
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		pa[i]=new arr;
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
	for(i=0;i<k;i++)
	{
		if(pa[i]->size>0)
		pa[i]->insert(pa[i]);
	}
	i=0;
	while(i<n)
	{
		tya=tya->del();
		result[i]=tya->a[tya->min];
		tya->min=(tya->min)+1;
		if(tya->min<tya->size)
		tya->insert(tya);
		i++;
	}
	for(i=0;i<n;i++)
	printf("%d_",result[i]);
}
void arr::insert(struct arr* key)
{
	struct arr* temp;
	H.last=(H.last)+1;
	int k=H.last;
	H.ya[H.last]=key;
	while((k/2)!=0)
	{
		if((H.ya[k]->a[H.ya[k]->min])<(H.ya[k/2]->a[H.ya[k/2]->min]))
		{
			temp=H.ya[k];
			H.ya[k]=H.ya[k/2];
			H.ya[k/2]=temp;
		}
		k=k/2;
	}
}
arr* arr::del()
{
	if(H.last==0)
	{
		printf("QUEUE EMPTY");
		return 0;
	}	
	else
	{
		struct arr* tya=H.ya[1];
		int k=1;
		while(2*k<(H.last)+1)
		{
			if(2*k+1>H.last)
			{
				H.ya[k]=H.ya[2*k];
				k=2*k;
			}
			else if((H.ya[2*k+1]->a[H.ya[2*k+1]->min])<(H.ya[2*k]->a[H.ya[2*k]->min]))
			{
				H.ya[k]=H.ya[2*k+1];
				k=2*k+1;
			}
			else
			{
				H.ya[k]=H.ya[2*k];
				k=2*k;
			}
		}
		H.ya[k]=H.ya[H.last];		
		H.last=(H.last)-1;
		return tya;
	}
}
