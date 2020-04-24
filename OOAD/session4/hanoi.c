#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int st[1000];
	int top;
};
struct stack* a=NULL;
struct stack* b=NULL;
struct stack* c=NULL;
void push(struct stack* a,int x);
int pop(struct stack* a);
void hanoi(struct stack* a,struct stack* b,struct stack* c,int n);
void main()
{
	a=malloc(sizeof(struct stack));
	b=malloc(sizeof(struct stack));
	c=malloc(sizeof(struct stack));
	(a->top)=-1;
	(b->top)=-1;
	(c->top)=-1;
	int n,temp;
	printf("Enter size: ");
	scanf("%d",&n);
	printf("Enter stack 1 in descending order:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		push(a,temp);
	}
	hanoi(a,b,c,n);
	for(int i=0;i<n;i++)
	printf("%d\n",pop(c));	
}
void push(struct stack* a,int x)
{
	a->top=(a->top)+1;
	a->st[a->top]=x;
}
int pop(struct stack* a)
{
	a->top=(a->top)-1;
	return a->st[(a->top)+1];
}
void hanoi(struct stack* a,struct stack* b,struct stack* c,int n)
{
	if(n==1)
	push(c,pop(a));
	else if(n>0)
	{
		hanoi(a,c,b,n-1);
		push(c,pop(a));
		hanoi(b,a,c,n-1);
	}
}
