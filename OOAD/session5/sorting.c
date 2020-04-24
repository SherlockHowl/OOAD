#include<stdio.h>
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
int a[1000000];
int n;
int main()
{
	int i;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	if(n<1)
	return -1;
	printf("Enter First term: ");
	scanf("%d",&a[0]);
	for(i=1;i<n;i++)
	{
		printf("Enter the next term: ");
		scanf("%d",&a[i]);
	}
	mergeSort(a,0,n-1);
	for(i=0;i<n;i++)
	printf("%d",a[i]);
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
	L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
	R[j] = arr[m + 1+ j];
	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (r-l>10000)
	{
		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
	else
	{
		int n=r-l+1;
		int safe[n];
		int temp,i,j,k;
		for(i=0;i<n;i++)
		safe[i]=arr[l+i];
		for(i=0;i<n;i++)
		{
			temp=safe[i];
			for(j=0;j<i;j++)
			{
				if(arr[l+j]>temp)
				break;
			}
			for(k=i;k>j;k--)
			arr[l+k]=arr[l+k-1];
			arr[l+j]=temp;
		}
	}
}
