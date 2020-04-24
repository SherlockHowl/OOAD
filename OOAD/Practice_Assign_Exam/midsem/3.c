#include<stdio.h>
struct heap
{
	int ya[1000];
	int last;
};
struct heap H;
int delete();
void insert(int key);
int main()
{
	H.last=0;
	int a[1000];
	int b[1000];
	int i,temp,n,counter;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	insert(a[i]);
	for(i=0;i<n;i++)
	b[i]=delete();
	for(i=0;i<n;)
	{
		temp=b[i];
		counter=0;
		while(b[i]==temp)
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
void insert(int key)
{
	int temp;
	H.last=(H.last)+1;
	int k=H.last;
	H.ya[H.last]=key;
	while((k/2)!=0)
	{
		if(H.ya[k]<H.ya[k/2])
		{
			temp=H.ya[k];
			H.ya[k]=H.ya[k/2];
			H.ya[k/2]=temp;
		}
		k=k/2;
	}
}
int delete()
{
	if(H.last==0)
	{
		printf("QUEUE EMPTY");
		return 0;
	}	
	else
	{
		int tya=H.ya[1];
		int k=1;
		while(2*k<(H.last)+1)
		{
			if(2*k+1>H.last)
			{
				H.ya[k]=H.ya[2*k];
				k=2*k;
			}
			else if(H.ya[2*k+1]<H.ya[2*k])
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
