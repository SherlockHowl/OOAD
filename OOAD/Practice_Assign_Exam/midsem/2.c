#include<stdio.h>
int main()
{
	int a[1000];
	int i,temp,n,counter;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]=a[j]^a[j+1];
				a[j+1]=a[j]^a[j+1];
				a[j]=a[j]^a[j+1];
			}
		}
	}
	for(i=0;i<n;)
	{
		temp=a[i];
		counter=0;
		while(a[i]==temp)
		{
			i++;
			counter++;
			if(i==n)
			break;
		}
		printf("Multiplicity of %d: %d \n",temp,counter);
	}
	return 1;
}
