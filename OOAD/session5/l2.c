#include<stdio.h>
#include<stdlib.h>
struct arr
{
	int size;
	int a[1000];
};
struct arr* pa[100];
void merge(struct arr* pa[], int l, int r);
void mergeSort(struct arr* pa[], int l, int r);
void main()
{
	int k,i,j,temp;
	printf("Enter no. of arrays: ");
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		pa[i]=malloc(sizeof(struct arr));
		printf("Enter array %d size: ",i+1);
		scanf("%d",&temp);
		if(temp<1)
		pa[i]->size=0;
		else
		pa[i]->size=temp;
		for(j=0;j<(pa[i]->size);j++)
		{
			printf("Element %d-%d: ",i+1,j+1);
			scanf("%d",&temp);
			pa[i]->a[j]=temp;
		}
	}
	mergeSort(pa,0,k-1);
	if(k<1)
	pa[0]->size=0;
	printf("Final array:\n");
	for(i=0;i<(pa[0]->size);i++)
	printf("%d_",pa[0]->a[i]);
}
void merge(struct arr* pa[], int l, int r)
{
	int i, j, k;
	int n1 = pa[l]->size;
	int n2 = pa[r]->size;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
	L[i] = pa[l]->a[i];
	for (j = 0; j < n2; j++)
	R[j] = pa[r]->a[j];
	i = 0;
	j = 0;
	k = 0;
	pa[l]->size=n1+n2;
	while(i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			pa[l]->a[k] = L[i];
			i++;
		}
		else
		{
			pa[l]->a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		pa[l]->a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		pa[l]->a[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(struct arr* pa[], int l, int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2;
		mergeSort(pa, l, m);
		mergeSort(pa, m+1, r);
		merge(pa, l, m+1);
	}
}
