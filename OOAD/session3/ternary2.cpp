#include<stdio.h>
#include<stdlib.h>
class stack
{
    public:
	int top;
	int a[1000];
    void push(stack* st,int a);
    int pop();
};
int main()
{
	int i,temp,n;
	int a[1000];
	stack* zero= new stack();
	stack* one= new stack();
	stack* two= new stack();
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
		zero->push(zero,a[i]);
		else if(a[i]==1)
		one->push(one,a[i]);
		else
		two->push(two,a[i]);
	}
	int j=0;
	while((zero->top)!=-1)
	{
		a[j]=zero->pop();
		j++;
	}
	while((one->top)!=-1)
	{
		a[j]=one->pop();
		j++;
	}
	while((two->top)!=-1)
	{
		a[j]=two->pop();
		j++;
	}
	for(i=0;i<n;i++)
	printf("%d",a[i]);
}
void stack::push(stack* st,int a)
{
	top=top+1;
	st->a[st->top]=a;
}
int stack::pop()
{
	top=top-1;
	return (a[top+1]);
}
