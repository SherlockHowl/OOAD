#include<stdio.h>
int a[10000];
void mergeSort(int arr[], int l, int r);
void merge(int a[], int l, int m,int k, int r);
int main()
{
	int i,n;
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
void merge(int arr[], int l, int m,int k, int r)
{
	int i, j, p, s;
	int n1 = m - l + 1;
	int n2 =  k - m;
	int n3 =  r - k;
	int L[n1], C[n2],R[n3];
	for (i = 0; i < n1; i++)
	L[i] = arr[l + i];
	for (i = 0; i < n2; i++)
	C[i] = arr[m + 1+ i];
	for (i = 0; i < n3; i++)
	R[i] = arr[k + 1+ i];
	i = 0;
	j = 0;
	p = 0;
	s = l;
	while(i < n1 && j < n2 && p < n3)
	{
		if(C[j]<=R[p])
		{
			if (L[i] <= C[j])
			{
				arr[s] = L[i];
				i++;
			}
			else
			{
				arr[s] = C[j];
				j++;
			}
			s++;
		}
		else
		{
			if (L[i] <= R[p])
			{
				arr[s] = L[i];
				i++;
			}
			else
			{
				arr[s] = R[p];
				p++;
			}
			s++;
		}
	}
	while(i < n1 && j < n2)
	{
		if (L[i] <= C[j])
		{
			arr[s] = L[i];
			i++;
		}
		else
		{
			arr[s] = C[j];
			j++;
		}
		s++;
	}
	while(i < n1 && p < n3)
	{
		if (L[i] <= R[p])
		{
			arr[s] = L[i];
			i++;
		}
		else
		{
			arr[s] = R[p];
			p++;
		}
		s++;
	}
	while(p < n3 && j < n2)
	{
		if (R[p] <= C[j])
		{
			arr[s] = R[p];
			p++;
		}
		else
		{
			arr[s] = C[j];
			j++;
		}
		s++;
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
	if (l < r-1)
	{
		int m = l+(r-l)/3;
		int k = l+2*(r-l)/3;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, k);
		mergeSort(arr, k+1, l);
		merge(arr,l,m,k,r);
	}
}
