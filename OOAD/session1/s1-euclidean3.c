#include<stdio.h>

void main()
{
	int k,a;
	int b=1;
	printf("\nEnter no. of terms:");
	scanf("%d",&k);
	if(k>0)
	{
		printf("Enter First term:");
		scanf("%d",&a);
		k--;
		if(a<0)
		a=a*-1;
		while(k>0)
		{
			k--;
			printf("Enter next term:");
			scanf("%d",&b);
			if(b<0)
			b=b*-1;
			if(a>b)
			{
				a=a^b;
				b=a^b;
				a=a^b;
			}
			if(a==0)
			a=b;
			else
			{
				while(b%a!=0)
				{
					b=b%a;
					a=a^b;
					b=a^b;
					a=a^b;
				}
			}
		}
		if(a==0)
		printf("Undefined\n");
		else
		printf("Gcd: %d",a);
	}
	else
	printf("Enter k>0");
}
