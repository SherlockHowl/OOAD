#include<stdio.h>
#include<stdlib.h>
class stack
{
    public:
	int st[1000];
	int top;
    void push(struct stack* a,int x);
    int pop(struct stack* a);
    void hanoi(struct stack* a,struct stack* b,struct stack* c,int n);
};
stack* a=NULL;
stack* b=NULL;
stack* c=NULL;
int main()
{
	a=new stack();
    b=new stack();
    c=new stack();
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
void push(stack* a,int x)
{
	a->top=(a->top)+1;
	a->st[a->top]=x;
}
int pop(stack* a)
{
	a->top=(a->top)-1;
	return a->st[(a->top)+1];
}
void hanoi(stack* a,stack* b,stack* c,int n)
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
