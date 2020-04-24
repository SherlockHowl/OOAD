#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int top;
	int a[1000];
};
void push(struct stack* st,int a);
int pop(struct stack* st);
void main()
{
	int i,temp,n;
	int a[1000];
	struct stack* zero= malloc(sizeof(struct stack));
	struct stack* one= malloc(sizeof(struct stack));
	struct stack* two= malloc(sizeof(struct stack));
	zero->top=-1;
	one->top=-1;
	two->top=-1;
	printf("Enter the array size: ");
	scanf("%d",&n);
	printf("Enter the array: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		push(zero,a[i]);
		else if(a[i]==1)
		push(one,a[i]);
		else
		push(two,a[i]);
	}
	int j=0;
	while((zero->top)!=-1)
	{
		a[j]=pop(zero);
		j++;
	}
	while((one->top)!=-1)
	{
		a[j]=pop(one);
		j++;
	}
	while((two->top)!=-1)
	{
		a[j]=pop(two);
		j++;
	}
	for(i=0;i<n;i++)
	printf("%d",a[i]);
}
void push(struct stack* st,int a)
{
	st->top=st->top+1;
	st->a[st->top]=a;
}
int pop(struct stack* st)
{
	st->top=st->top-1;
	return (st->a[(st->top)+1]);
}
