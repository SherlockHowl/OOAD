#include<stdio.h>
void main()
{
	int n,i;
	int bin[100];
	int k=0;
	int temp=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	if(n<0)
	n=n*-1;
	while(n>0)
	{
		bin[k]=n%2;
		n=n/2;
		k++;
	}
	int prod[2*k];
	for(i=0;i<2*k;i++)
	prod[i]=0;
	for(int j=0;j<k;j++)
	{
		if(bin[j]==1)
		{
			for(i=j;i<k+j;i++)
			prod[i]=prod[i]+bin[i-j];
		}
	}
	for(i=0;i<2*k;i++)
	{
		prod[i+1]=prod[i+1]+(prod[i])/2;
		prod[i]=prod[i]%2;
	}
	for(i=2*k;i>0;i--)
	printf("%d",prod[i-1]);
}
